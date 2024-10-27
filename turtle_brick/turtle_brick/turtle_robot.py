import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import TransformStamped, Vector3, Quaternion, Twist
from tf2_ros import TransformBroadcaster, StaticTransformBroadcaster
import tf_transformations
from visualization_msgs.msg import Marker
import numpy as np
from sensor_msgs.msg import JointState
class TurtleRobot(Node):
    """
    Node that creates an arena in the rviz environment

    Publishes
    ---------
    Marker : visualization_msgs/msg/Marker - publishes markers to visualize walls in RViz.

    Parameters
    ----------
    frequency : float - timer freqency in seconds to control update rate
    scale: list - 3D scaling factors [x, y, z] for wall dimensions.
    rgba : list - RGBA volor values for the walls in the format [R, G, B, A]

    """

    def __init__(self):
        """Create the Turtle_robot bridge"""
        super().__init__('turtle_robot')
        self.frequency = 0.01
        self.create_subscription(Pose, '/turtle1/pose', self.handle_turtle_pose, 1)
        self.tf_broadcaster = TransformBroadcaster(self)
        self.tf_staticbroadcaster = StaticTransformBroadcaster(self)
        self.staticTimer = self.create_timer(self.frequency, self.handleStaticFrames)
        self.dynamicTimer = self.create_timer(self.frequency, self.handleDynamicFrames)
        self.create_subscription(Twist, '/cmd_vel', self.handle_cmd_vel, 1)

        self.joint_state_pub = self.create_publisher(JointState, 'joint_states', 10)
        self.joint_state_timer = self.create_timer(self.frequency, self.publish_joint_state)

        self.latest_cmd_vel = Twist()
        self.latest_pose = None
        self.markerPublisher = self.create_publisher(Marker, "visualization_marker", 10)
        self.defaultTranslation = Vector3(x=0.0, y=0.0, z=0.0)
        self.defaultRotation = Quaternion(x=0.0, y=0.0, z=0.0, w= 1.0)
        self.get_logger().set_level(rclpy.logging.LoggingSeverity.DEBUG)
        self.print = self.get_logger().info
        self.wheelRadius = 0.1
        self.quat = None
        self.latest_pose = None
        self.timer = self.create_timer(self.frequency, self.handleTurtleFrame)
        self.revolution = 0
        self.total_distance_traveled = 0.0

    def publish_joint_state(self):
        # Create a JointState message
        joint_state = JointState()
        joint_state.header.stamp = self.get_clock().now().to_msg()

        # Define the caster wheel joint
        joint_state.name = ['caster_wheel_joint']

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
        distance =  msg.linear_velocity
        circumference = 2 * np.pi * self.wheelRadius
        self.revolution =  self.total_distance_traveled / circumference
        self.revolution = (self.revolution + np.pi) % (2 * np.pi) - np.pi

        self.quat = tf_transformations.quaternion_from_euler(0, 0, self.latest_pose.theta)
        # self.print(f" theta = {(theta)} and robotTheta = {self.latest_pose.theta}")
        # self.print(str(revolutions))
    

     
    def handleStaticFrames(self):
        """
        Informs the handle_broadcast which frames to statically connect
        """
        # self.handle_broadcast('world', 'odom')
        self.handle_broadcast('base_link', 'base_footprint')
        # self.handle_broadcast('base_link', 'caster_wheel')
        self.handle_broadcast('base_link', 'pole_link')
        self.handle_broadcast('pole_link', 'top_link')
        
        # self.handle_broadcast('base_link', 'caster_wheel_joint')
        # self.handle_broadcast('caster_wheel_joint', 'caster_wheel')

    def handleDynamicFrames(self):
        """
        Informs the dynamic broadcast which frames to dynamically connect
        """
        # self.handle_dynamic_broadcast('base_link', 'caster_wheel_joint')
        # self.handle_dynamic_broadcast('caster_wheel_joint', 'caster_wheel')
        self.handle_dynamic_broadcast('base_link', 'caster_wheel_joint')
        self.handle_dynamic_broadcast('world', 'odom')
        # self.handle_dynamic_broadcast('base_link', 'caster_wheel')
        # self.handle_dynamic_broadcast('base_link', 'caster_wheel_joint')

    def handleTurtleFrame(self):
        try:

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

            # Broadcast the transform
            self.tf_broadcaster.sendTransform(t)
        except Exception as e:
            print(f"An error occurred: {e}")


        

        
        

    def handle_dynamic_broadcast(self, parent_frame, child_frame):
        """
        Creates the transformation between the different frames dynamically

        Parameters
        ----------
        parent_frame : string - the parent frame
        child_frame: string - the child frame

        """
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = parent_frame
        t.child_frame_id = child_frame
        t.transform.translation = self.defaultTranslation
        t.transform.rotation = self.defaultRotation

        # Broadcast the transform
        self.tf_broadcaster.sendTransform(t)

    def handle_broadcast(self, parent_frame, child_frame):
        """
        Creates the transformation between the different frames statically

        Parameters
        ----------
        parent_frame : string - the parent frame
        child_frame: string - the child frame

        """
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = parent_frame
        t.child_frame_id = child_frame
        t.transform.translation = self.defaultTranslation
        t.transform.rotation = self.defaultRotation

        # Broadcast the transform
        self.tf_staticbroadcaster.sendTransform(t)
        

    



def main(args=None):
    rclpy.init(args=args)
    node = TurtleRobot()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
