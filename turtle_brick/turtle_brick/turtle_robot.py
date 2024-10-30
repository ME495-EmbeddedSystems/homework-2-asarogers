import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import TransformStamped, Vector3, Quaternion, Twist, PoseStamped, Point
from nav_msgs.msg import Odometry
from tf2_ros import TransformBroadcaster, StaticTransformBroadcaster
import tf_transformations
from visualization_msgs.msg import Marker
import numpy as np
from sensor_msgs.msg import JointState
from turtle_brick_interfaces.srv import ProvideGoalPose
from turtle_brick_interfaces.msg import Tilt, TurtleLocation, BrickLocation
import yaml
from rclpy.qos import QoSProfile, QoSDurabilityPolicy

class TurtleRobot(Node):
    def __init__(self):
        """Create the Turtle_robot bridge"""
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
        self.homePositon = Point(x = 5.544445, y=5.544445, z = 0.0)
        self.tilt = 0.0
        
        
        
        self.config_path = self.declare_parameter('config_path', '').get_parameter_value().string_value
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

        qos_profile = QoSProfile(depth=1, durability=QoSDurabilityPolicy.TRANSIENT_LOCAL)
        self.create_subscription(Pose, '/turtle1/pose', self.handle_turtle_pose, 1)
        self.create_subscription(Twist, '/cmd_vel', self.handle_cmd_vel, 1)
        self.create_subscription(Tilt, '/tilt', self.handle_tilt, 1)
        self.create_subscription(PoseStamped, '/goal_pose', self.handle_goal_pose, 1)

        # Publishers
        self.tf_broadcaster = TransformBroadcaster(self)
        self.wheelTF = TransformBroadcaster(self)
        self.platformTF = StaticTransformBroadcaster(self)
        self.platformJointTF = TransformBroadcaster(self)
        self.wheelToBase = StaticTransformBroadcaster(self)
        self.tf_staticbroadcaster = StaticTransformBroadcaster(self)
        self.joint_state_pub = self.create_publisher(JointState, 'joint_states', qos_profile)
        self.odom_publisher = self.create_publisher(Odometry, 'odom', qos_profile)
        self.turtleLocationPublisher = self.create_publisher(TurtleLocation, 'turtle_location', qos_profile)
        self.cmd_vel_publisher = self.create_publisher(Twist, 'turtle1/cmd_vel', qos_profile)


        # Services
        self._srv = self.create_service(ProvideGoalPose, 'provide_goal_pose', self.giveGoalPose)
        self.create_subscription(BrickLocation, 'brick_location', self.handleBrickLocation,qos_profile)
        
        # Timers
        self.staticTimer = self.create_timer(self.frequency, self.handleStaticFrames)
        self.dynamicTimer = self.create_timer(self.frequency, self.handleDynamicFrames)
        self.timer = self.create_timer(self.frequency, self.handleTurtleFrame)
        self.control_timer = self.create_timer(self.frequency, self.driveToGoal)
        # self.wheelTimer = self.create_timer(self.frequency, self.handleWheelFrame)
        self.platformTimer = self.create_timer(self.frequency, self.handlePlatformFrame)
        self.platformJointTimer = self.create_timer(self.frequency, self.handlePlatformJointFrame)
        # self.platwheeltoPlatoform = self.create_timer(self.frequency, self.handleWheelToBaseFrame)

    # def publishJointState(self):
    #     """Publish the joint states at a fixed 100 Hz."""
    #     joint_state = JointState()
    #     joint_state.header.stamp = self.get_clock().now().to_msg()

    #     # Define the caster wheel joint
    #     joint_state.name = ['wheel_joint']
    #     joint_state.position = [self.revolution]  # Assuming revolution angle represents the rotation

    #     # Publish the joint state
    #     self.joint_state_pub.publish(joint_state)

    # self.handle_dynamic_broadcast('base_link', 'wheel')
    def handleWheelToBaseFrame(self):
        """handles the platform frame rendering"""
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = "base_link"
        t.child_frame_id = "wheel"
        t.transform.translation = self.defaultTranslation

        # Set the rotation from the computed quaternion
        t.transform.rotation = self.defaultRotation
        self.wheelToBase.sendTransform(t)

    def handlePlatformFrame(self):
        """handles the platform frame rendering"""
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = "base_link"
        t.child_frame_id = "platform_joint"
        t.transform.translation = self.defaultTranslation

        # Set the rotation from the computed quaternion
        t.transform.rotation = self.defaultRotation
        self.platformTF.sendTransform(t)


    def handlePlatformJointFrame(self):
        """handles the platform frame rendering"""
        q = tf_transformations.quaternion_from_euler(0.5, 0.0, self.tilt)

        # Create and populate the TransformStamped message for the platform_joint
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = "pole_link"
        t.child_frame_id = "platform"

        # Set the rotation from the computed quaternion
        t.transform.translation = self.defaultTranslation

        t.transform.rotation.x = q[0]
        t.transform.rotation.y = q[1]
        t.transform.rotation.z = q[2]
        t.transform.rotation.w = q[3]
        self.platformJointTF.sendTransform(t)


    def handleWheelFrame(self):
        """handles the wheel frame rendering"""
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = "base_link"
        t.child_frame_id = "wheel_joint"
        t.transform.translation = self.defaultTranslation
        t.transform.rotation = self.defaultRotation
        self.wheelTF.sendTransform(t)

    def handleBrickLocation(self, msg):
        """Subscription to the brickLocation msg that is called everytime the brick's location updates"""
        self.brickLocation = msg

    def publish_odom(self):
        '''
        Publish to the odometry topic
        '''
        if self.latest_pose:
            odom = Odometry()
            odom.header.stamp = self.get_clock().now().to_msg()
            odom.header.frame_id = 'odom'
            odom.child_frame_id = 'base_link'

            # Position
            odom.pose.pose.position.x = self.latest_pose.x
            odom.pose.pose.position.y = self.latest_pose.y

            # Orientation
            q = tf_transformations.quaternion_from_euler(0, 0, self.latest_pose.theta)
            odom.pose.pose.orientation.x = q[0]
            odom.pose.pose.orientation.y = q[1]
            odom.pose.pose.orientation.z = q[2]
            odom.pose.pose.orientation.w = q[3]

            # Twist (velocity from cmd_vel)
            odom.twist.twist = self.latest_cmd_vel
            self.odom_publisher.publish(odom)

    def handle_tilt(self, msg):
        '''
        set the tilt based on the recieved msg
        '''
        self.print("recieved tilt!!")
        self.tilt = msg.tilt
        


    def giveGoalPose(self, request, response):
        '''
        Set the goal pose when msg recieved
        '''
        self.goal_pose = request.goal_pose

        # Log the goal pose received
        self.get_logger().info(f"Received new goal pose: x={self.goal_pose.pose.position.x}, y={self.goal_pose.pose.position.y}")

        response.success = True
        return response

    

    def handle_cmd_vel(self, msg):
        """Store the latest cmd_vel command"""
        self.latest_cmd_vel = msg
        
    async def handle_turtle_pose(self, msg):
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

        k_linear = self.turtleAccel 
        k_angular = 2.0 


        linear_speed = distance * k_linear
        angular_speed = angle_diff * k_angular


        max_linear_speed = self.maxVelocity 
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
        self.publish_odom()

    def handleStaticFrames(self):
        """Informs the handle_broadcast which frames to statically connect"""
        self.handle_broadcast('base_link', 'base_footprint')
        
        

    def handleDynamicFrames(self):
        """Informs the dynamic broadcast which frames to dynamically connect"""
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

            pose_dict = TurtleLocation()
            pose_dict.x = self.latest_pose.x
            pose_dict.y = self.latest_pose.y
            pose_dict.theta = self.latest_pose.theta

            self.turtleLocationPublisher.publish(pose_dict)
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
