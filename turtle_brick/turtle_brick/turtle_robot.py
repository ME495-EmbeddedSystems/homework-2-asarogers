import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import TransformStamped, Vector3, Quaternion
from tf2_ros import TransformBroadcaster
import tf_transformations
from visualization_msgs.msg import Marker

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
        self.timer = self.create_timer(self.frequency, self.handleStaticFrames)
        self.latest_pose = None
        self.markerPublisher = self.create_publisher(Marker, "visualization_marker", 10)
        self.defaultTranslation = Vector3(x=0.0, y=0.0, z=0.0)
        self.defaultRotation = Quaternion(x=0.0, y=0.0, z=0.0, w= 1.0)
        self.get_logger().set_level(rclpy.logging.LoggingSeverity.DEBUG)
        self.print = self.get_logger().info
        self.wheelRadius = 0.1


    def handleStaticFrames(self):
        """
        Informs the handle_broadcast which frames to connect
        """
        self.handle_broadcast('world', 'odom')
        self.handle_broadcast('base_link', 'base_footprint')
        # self.handle_broadcast('base_link', 'pole_to_base_joint')
        # self.handle_broadcast('base_link', 'caster_wheel_joint')
        # self.handle_broadcast('caster_wheel_joint', 'caster_wheel')
        

        
        

        

    def handle_broadcast(self, parent_frame, child_frame):
        """
        Creates the transformation between the different frames

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
        

    def handle_turtle_pose(self, msg):
        """Store the latest pose from the turtlesim node"""
        self.latest_pose = msg
        linear_velocity =  msg.linear_velocity
        angular_velocity =  linear_velocity / self.wheelRadius
        theta = angular_velocity * self.wheelRadius

        distance = angular_velocity * self.wheelRadius
        # self.print(str(distance))



        # Create and broadcast the transform based on the latest pose
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'odom'
        t.child_frame_id = 'base_link'

        # self.latest_pose.x
        # self.latest_pose.y
        # t.transform.translation.x = 0.0
        # t.transform.translation.y = 0.0
        # t.transform.translation.z = 0.0 

        t.transform.translation.x = self.latest_pose.x
        t.transform.translation.y = self.latest_pose.y
        t.transform.translation.z = 0.0

        # Convert theta to quaternion
        quat = tf_transformations.quaternion_from_euler(0, 0, self.latest_pose.theta)
        t.transform.rotation.x = quat[0]
        t.transform.rotation.y = quat[1]
        t.transform.rotation.z = quat[2]
        t.transform.rotation.w = quat[3]

        # Broadcast the transform
        self.tf_broadcaster.sendTransform(t)

def main(args=None):
    rclpy.init(args=args)
    node = TurtleRobot()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
