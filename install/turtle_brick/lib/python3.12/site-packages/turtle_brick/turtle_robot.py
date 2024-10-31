"""TurtleRobot ROS2 Node for Managing Turtle Simulations.

This module defines the TurtleRobot class, a ROS2 node that integrates with
turtlesim to handle pose, velocity, goal setting, and transformations. It
includes both static and dynamic frame broadcasting for visualizing movement
in Rviz and supports customizable configurations.

Authors:
- Asa Rogers
- Date: 2024-10-30
"""

from geometry_msgs.msg import (
    Point,
    PoseStamped,
    Quaternion,
    TransformStamped,
    Twist,
    Vector3,
)

from nav_msgs.msg import Odometry

import numpy as np

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy, QoSProfile

from sensor_msgs.msg import JointState

from tf2_ros import StaticTransformBroadcaster, TransformBroadcaster

import tf_transformations

from turtle_brick_interfaces.msg import BrickLocation, Tilt, TurtleLocation
from turtle_brick_interfaces.srv import ProvideGoalPose

from turtlesim.msg import Pose

import yaml


class TurtleRobot(Node):
    """ROS2 Node to manage turtlebot inside the RVIZ enviroment.

    Publishes
    ---------
    JointState : sensor_msgs/msg/JointState
        Publishes joint states for the turtle robot.
    Odometry : nav_msgs/msg/Odometry
        Publishes odometry data.
    TurtleLocation : turtle_brick_interfaces/msg/TurtleLocation
        Publishes the turtle's current location.
    Twist : geometry_msgs/msg/Twist
        Publishes velocity commands to the turtle.

    Parameters
    ----------
    frequency : float
        Timer frequency in seconds to control update rate.
    tolerance : float
        Distance threshold for reaching a goal.
    gravity : float
        Gravitational constant, loaded from configuration.
    platformHeight : float
        Platform height, loaded from configuration.
    maxVelocity : float
        Maximum allowable velocity, from configuration.
    wheelRadius : float
        Radius of the robot's wheel.
    latest_pose : Pose
        Latest pose received from the turtlesim node.
    goal_pose : PoseStamped
        Target goal pose for the robot to reach.
    """

    def __init__(self):
        """Create TurtleRobot node."""
        super().__init__('turtle_robot')
        self.frequency = 0.01
        self.latest_cmd_vel = Twist()
        self.latest_pose = None
        self.goal_pose = None
        self.defaultTranslation = Vector3(x=0.0, y=0.0, z=0.0)
        self.defaultRotation = Quaternion(x=0.0, y=0.0, z=0.0, w=1.0)
        self.get_logger().set_level(rclpy.logging.LoggingSeverity.DEBUG)
        self.wheelRadius = 0.1
        self.quat = None
        self.revolution = 0
        self.total_distance_traveled = 0.0
        self.print = self.get_logger().info
        self.tolerance = 0.5
        self.gravity = 0.0
        self.platformHeight = 0.0
        self.maxVelocity = 0.0
        self.turtleAccel = 0.0
        self.brickLocation = None
        self.homePositon = Point(x=5.544445, y=5.544445, z=0.0)
        self.tilt = 0.0
        config = self.declare_parameter('config_path', '')
        # Load configurations
        self.config_path = (
            config.get_parameter_value().string_value
        )
        if self.config_path:
            with open(self.config_path, 'r') as configFile:
                config = yaml.safe_load(configFile)
            self.gravity = config['robot']['gravity_accel']
            self.platformHeight = config['robot']['platform_height']
            self.maxVelocity = config['robot']['max_velocity']
            self.turtleAccel = config['robot']['turtle_accel']
            self.brickTolerance = config['robot']['platform_tolerance']
        else:
            self.get_logger().error('Config path not provided')

        # QoS setup
        qos = QoSProfile(
            depth=1, durability=QoSDurabilityPolicy.TRANSIENT_LOCAL
        )

        # Subscribers
        self.create_subscription(Pose, '/turtle1/pose', self.handleTurtleP, 1)
        self.create_subscription(Twist, '/cmd_vel', self.handle_cmd_vel, 1)
        self.create_subscription(Tilt, '/tilt', self.handle_tilt, 1)
        self.create_subscription(PoseStamped, '/goal_pose', self.goalPose, 1)
        self.create_subscription(
            BrickLocation, 'brick_location', self.handleBrickLocation, qos
        )

        # Publishers
        self.tf_broadcaster = TransformBroadcaster(self)
        self.wheelTF = TransformBroadcaster(self)
        self.platformTF = StaticTransformBroadcaster(self)
        self.platformJointTF = TransformBroadcaster(self)
        self.wheelToBase = StaticTransformBroadcaster(self)
        self.tf_staticbroadcaster = StaticTransformBroadcaster(self)
        self.joint_state_pub = self.create_publisher(
            JointState, 'joint_states', qos
        )
        self.odom_publisher = self.create_publisher(Odometry, 'odom', qos)
        self.turtleLocationPublisher = self.create_publisher(
            TurtleLocation, 'turtle_location', qos
        )
        self.cmd_vel_publisher = self.create_publisher(
            Twist, 'turtle1/cmd_vel', qos
        )

        # Services
        self._srv = self.create_service(
            ProvideGoalPose, 'provide_goal_pose', self.giveGoalPose
        )

        # Timers
        self.staticTimer = self.create_timer(self.frequency, self.staticFrames)
        self.dynTimer = self.create_timer(self.frequency, self.dynamicFrames)
        self.timer = self.create_timer(self.frequency, self.handleTurtleFrame)
        self.controlTimer = self.create_timer(self.frequency, self.driveToGoal)
        self.platformJointTimer = self.create_timer(
            self.frequency, self.handlePlatformJointFrame
        )

    def handleWheelToBaseFrame(self):
        """Handle the platform frame rendering between wheel and base link."""
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'base_link'
        t.child_frame_id = 'wheel'
        t.transform.translation = self.defaultTranslation
        t.transform.rotation = self.defaultRotation
        self.wheelToBase.sendTransform(t)

    def handlePlatformFrame(self):
        """Handle the platform frame rendering."""
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'base_link'
        t.child_frame_id = 'platform_joint'
        t.transform.translation = self.defaultTranslation
        t.transform.rotation = self.defaultRotation
        self.platformTF.sendTransform(t)

    def handlePlatformJointFrame(self):
        """Handle platform joint frame rendering with tilt transformation."""
        tilt = self.tilt * 9
        q = tf_transformations.quaternion_from_euler(self.tilt, 0.0, tilt)
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'pole_link'
        t.child_frame_id = 'platform'
        t.transform.translation = self.defaultTranslation
        t.transform.rotation.x = q[0]
        t.transform.rotation.y = q[1]
        t.transform.rotation.z = q[2]
        t.transform.rotation.w = q[3]
        self.platformJointTF.sendTransform(t)

    def handleWheelFrame(self):
        """Handle the wheel frame rendering."""
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'base_link'
        t.child_frame_id = 'wheel_joint'
        t.transform.translation = self.defaultTranslation
        t.transform.rotation = self.defaultRotation
        self.wheelTF.sendTransform(t)

    def handleBrickLocation(self, msg):
        """Handle updates to brick location.

        Parameters
        ----------
        msg : BrickLocation
            The updated brick location message.
        """
        self.brickLocation = msg

    def publish_odom(self):
        """Publish the latest odometry information."""
        if self.latest_pose:
            odom = Odometry()
            odom.header.stamp = self.get_clock().now().to_msg()
            odom.header.frame_id = 'odom'
            odom.child_frame_id = 'base_link'
            odom.pose.pose.position.x = self.latest_pose.x
            odom.pose.pose.position.y = self.latest_pose.y
            theta = self.latest_pose.theta
            q = tf_transformations.quaternion_from_euler(0, 0, theta)
            odom.pose.pose.orientation.x = q[0]
            odom.pose.pose.orientation.y = q[1]
            odom.pose.pose.orientation.z = q[2]
            odom.pose.pose.orientation.w = q[3]
            odom.twist.twist = self.latest_cmd_vel
            self.odom_publisher.publish(odom)

    def handle_tilt(self, msg):
        """Set the tilt based on received message.

        Parameters
        ----------
        msg : Tilt
            The tilt message containing tilt data.
        """
        self.print('received tilt!!')
        self.tilt = msg.tilt

    def giveGoalPose(self, request, response):
        """Set the goal pose.

        Parameters
        ----------
        request : ProvideGoalPose.Request
            The request containing the goal pose.
        response : ProvideGoalPose.Response
            The response to confirm goal setting.

        Returns
        -------
        ProvideGoalPose.Response
            Response indicating success.
        """
        self.goal_pose = request.goal_pose
        response.success = True
        return response

    def handle_cmd_vel(self, msg):
        """Store the latest command velocity.

        Parameters
        ----------
        msg : Twist
            The latest command velocity message.
        """
        self.latest_cmd_vel = msg

    async def handleTurtleP(self, msg):
        """Store the latest pose from the turtlesim node.

        Parameters
        ----------
        msg : Pose
            The latest pose message.
        """
        self.latest_pose = msg
        circumference = 2 * np.pi * self.wheelRadius
        self.revolution = self.total_distance_traveled / circumference
        self.revolution = (self.revolution + np.pi) % (2 * np.pi) - np.pi
        self.quat = tf_transformations.quaternion_from_euler(
            0, 0, self.latest_pose.theta
        )

    def goalPose(self, msg):
        """Store the goal pose from the received message.

        Parameters
        ----------
        msg : PoseStamped
            The goal pose message.
        """
        self.goal_pose = msg.pose

    def driveToGoal(self):
        """Drive the robot towards the goal pose using proportional control."""
        if self.latest_pose is None or self.goal_pose is None:
            return

        dx = self.goal_pose.pose.position.x - self.latest_pose.x
        dy = self.goal_pose.pose.position.y - self.latest_pose.y
        distance = np.sqrt(dx**2 + dy**2)
        goal_theta = np.arctan2(dy, dx)
        angle_diff = goal_theta - self.latest_pose.theta
        angle_diff = (angle_diff + np.pi) % (2 * np.pi) - np.pi

        k_linear = self.turtleAccel
        k_angular = 2.0
        linear_speed = distance * k_linear
        angular_speed = angle_diff * k_angular
        max_ls = self.maxVelocity
        max_as = 2.0

        linear_speed = max(-max_ls, min(linear_speed, max_ls))
        angular_speed = max(-max_as, min(angular_speed, max_as))

        if distance < self.tolerance:
            self.get_logger().info('Goal reached')
            self.goal_pose = None
            return

        cmd_vel_msg = Twist()
        cmd_vel_msg.linear.x = linear_speed
        cmd_vel_msg.angular.z = angular_speed
        self.cmd_vel_publisher.publish(cmd_vel_msg)
        self.publish_odom()

    def staticFrames(self):
        """Broadcast static frames between 'base_link' and 'base_footprint'."""
        self.handle_broadcast('base_link', 'base_footprint')

    def dynamicFrames(self):
        """Broadcast dynamic frames between 'world' and 'odom'."""
        self.handle_dynamic_broadcast('world', 'odom')

    def handleTurtleFrame(self):
        """Handle broadcasting and publishing turtle movements in Rviz."""
        try:
            if self.latest_pose is None:
                return
            t = TransformStamped()
            t.header.stamp = self.get_clock().now().to_msg()
            t.header.frame_id = 'odom'
            t.child_frame_id = 'base_link'
            t.transform.translation.x = self.latest_pose.x
            t.transform.translation.y = self.latest_pose.y
            t.transform.translation.z = 0.0
            t.transform.rotation.x = self.quat[0]
            t.transform.rotation.y = self.quat[1]
            t.transform.rotation.z = self.quat[2]
            t.transform.rotation.w = self.quat[3]

            pose_dict = TurtleLocation()
            pose_dict.x = self.latest_pose.x
            pose_dict.y = self.latest_pose.y
            pose_dict.theta = self.latest_pose.theta

            self.turtleLocationPublisher.publish(pose_dict)
            self.tf_broadcaster.sendTransform(t)
        except Exception as e:
            self.get_logger().error(f'An error occurred: {e}')

    def handle_dynamic_broadcast(self, parent_frame, child_frame):
        """Create the transformation between frames dynamically.

        Parameters
        ----------
        parent_frame : str
            The name of the parent frame.
        child_frame : str
            The name of the child frame.
        """
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = parent_frame
        t.child_frame_id = child_frame
        t.transform.translation = self.defaultTranslation
        t.transform.rotation = self.defaultRotation
        self.tf_broadcaster.sendTransform(t)

    def handle_broadcast(self, parent_frame, child_frame):
        """Create the transformation between frames statically.

        Parameters
        ----------
        parent_frame : str
            The name of the parent frame.
        child_frame : str
            The name of the child frame.
        """
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = parent_frame
        t.child_frame_id = child_frame
        t.transform.translation = self.defaultTranslation
        t.transform.rotation = self.defaultRotation
        self.tf_staticbroadcaster.sendTransform(t)


def main(args=None):
    """Initialize and run the TurtleRobot node."""
    rclpy.init(args=args)
    node = TurtleRobot()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()