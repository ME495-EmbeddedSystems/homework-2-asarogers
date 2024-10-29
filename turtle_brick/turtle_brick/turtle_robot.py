import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import TransformStamped, Vector3, Quaternion, Twist, PoseStamped
from nav_msgs.msg import Odometry
from tf2_ros import TransformBroadcaster, StaticTransformBroadcaster
import tf_transformations
from visualization_msgs.msg import Marker
import numpy as np
from sensor_msgs.msg import JointState
from turtle_brick_interfaces.srv import ProvideGoalPose
from turtle_brick_interfaces.msg import Tilt


class TurtleRobot(Node):
    def __init__(self):
        """Create the Turtle_robot bridge"""
        super().__init__('turtle_robot')
        self.frequency = 0.01
        # self.platform_height = self.get_parameter('robot.platform_height').get_parameter_value().double_value
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


        self.create_subscription(Pose, '/turtle1/pose', self.handle_turtle_pose, 1)
        self.create_subscription(Twist, '/cmd_vel', self.handle_cmd_vel, 1)
        self.create_subscription(Tilt, '/tilt', self.handle_tilt, 1)
        # self.create_subscription(PoseStamped, '/goal_pose', self.handle_goal_pose, 1)

        # Publishers
        self.tf_broadcaster = TransformBroadcaster(self)
        self.tf_staticbroadcaster = StaticTransformBroadcaster(self)
        self.joint_state_pub = self.create_publisher(JointState, 'joint_states', 10)
        self.odom_publisher = self.create_publisher(Odometry, 'odom', 10)
        self.cmd_vel_publisher = self.create_publisher(Twist, 'turtle1/cmd_vel', 10)

        self._srv = self.create_service(ProvideGoalPose, 'provide_goal_pose', self.giveGoalPose)
        
        # Timers
        self.staticTimer = self.create_timer(self.frequency, self.handleStaticFrames)
        self.dynamicTimer = self.create_timer(self.frequency, self.handleDynamicFrames)
        self.timer = self.create_timer(self.frequency, self.handleTurtleFrame)
        # self.joint_state_timer = self.create_timer(self.frequency, self.publishJointState)
        self.control_timer = self.create_timer(self.frequency, self.driveToGoal)
        self.wheel_timer = self.create_timer(self.frequency, self.publishJointState)


        

    def handle_tilt(self, msg):
        self.tilt = msg.tilt


    def giveGoalPose(self, request, response):
        self.goal_pose = request.goal_pose

        # Log the goal pose received
        self.get_logger().info(f"Received new goal pose: x={self.goal_pose.pose.position.x}, y={self.goal_pose.pose.position.y}")

        response.success = True
        return response

    def publishJointState(self):
        # Create a JointState message
        joint_state = JointState()
        joint_state.header.stamp = self.get_clock().now().to_msg()

        # Define the caster wheel joint
        joint_state.name = ['wheel_joint']

        # Set the position of the caster wheel (example value)
        joint_state.position = [self.revolution]  # Update the caster wheel rotation based on the revolution calculation

        # Publish the joint state
        self.joint_state_pub.publish(joint_state)

    def handle_cmd_vel(self, msg):
        """Store the latest cmd_vel command"""
        self.latest_cmd_vel = msg
        
    def handle_turtle_pose(self, msg):
        """Store the latest pose from the turtlesim node"""
        self.latest_pose = msg
        circumference = 2 * np.pi * self.wheelRadius
        self.revolution = self.total_distance_traveled / circumference
        self.revolution = (self.revolution + np.pi) % (2 * np.pi) - np.pi
        self.quat = tf_transformations.quaternion_from_euler(0, 0, self.latest_pose.theta)
    
    def handle_goal_pose(self, msg):
        """Store the goal pose"""
        self.goal_pose = msg.pose
        self.get_logger().info(f"Received new goal pose: x={self.goal_pose.position.x}, y={self.goal_pose.position.y}")

    def driveToGoal(self):
        """Drive the robot towards the goal pose using proportional control for smoother navigation."""
        if self.latest_pose is None or self.goal_pose is None:
            return  # Return early if no pose or goal

        # Calculate differences in position
        dx = self.goal_pose.pose.position.x - self.latest_pose.x
        dy = self.goal_pose.pose.position.y - self.latest_pose.y

        # Compute the distance and orientation difference
        distance = np.sqrt(dx**2 + dy**2)
        goal_theta = np.arctan2(dy, dx)
        angle_diff = goal_theta - self.latest_pose.theta

        # Normalize the angle to [-pi, pi] range
        angle_diff = (angle_diff + np.pi) % (2 * np.pi) - np.pi

        k_linear = 0.25 
        k_angular = 2.0 


        linear_speed = distance * k_linear
        angular_speed = angle_diff * k_angular


        max_linear_speed = 1.0
        max_angular_speed = 2.0

        # Constrain linear and angular speeds to max limits
        linear_speed = max(-max_linear_speed, min(linear_speed, max_linear_speed))
        angular_speed = max(-max_angular_speed, min(angular_speed, max_angular_speed))

        # Stop if within tolerance of the goal
        if distance < self.tolerance:
            self.get_logger().info("Goal reached")
            self.goal_pose = None  # Clear goal when reached
            return

        # Publish the calculated command velocities
        cmd_vel_msg = Twist()
        cmd_vel_msg.linear.x = linear_speed
        cmd_vel_msg.angular.z = angular_speed
        self.cmd_vel_publisher.publish(cmd_vel_msg)

    def handleStaticFrames(self):
        """Informs the handle_broadcast which frames to statically connect"""
        self.handle_broadcast('base_link', 'base_footprint')
        self.handle_broadcast('base_link', 'pole_link')
        self.handle_broadcast('pole_link', 'platform')

    def handleDynamicFrames(self):
        """Informs the dynamic broadcast which frames to dynamically connect"""
        self.handle_dynamic_broadcast('base_link', 'wheel_joint')
        self.handle_dynamic_broadcast('world', 'odom')


    def handleTurtleFrame(self):
        """Handles broadcasting and publishes turtle movements in Rviz"""
        try:
            if self.latest_pose is None:
                return

            # Broadcast the transform between odom and base_link
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

            self.tf_broadcaster.sendTransform(t)

            

        except Exception as e:
            self.get_logger().error(f"An error occurred: {e}")

    def handle_dynamic_broadcast(self, parent_frame, child_frame):
        """Creates the transformation between the different frames dynamically"""
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = parent_frame
        t.child_frame_id = child_frame
        t.transform.translation = self.defaultTranslation
        t.transform.rotation = self.defaultRotation
        self.tf_broadcaster.sendTransform(t)

    def handle_broadcast(self, parent_frame, child_frame):
        """Creates the transformation between the different frames statically"""
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = parent_frame
        t.child_frame_id = child_frame
        t.transform.translation = self.defaultTranslation
        t.transform.rotation = self.defaultRotation
        self.tf_staticbroadcaster.sendTransform(t)

def main(args=None):
    rclpy.init(args=args)
    node = TurtleRobot()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
