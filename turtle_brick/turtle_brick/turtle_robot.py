import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster
import tf_transformations
from visualization_msgs.msg import Marker

class TurtleRobot(Node):
    """
    Node pushes messages at a fixed frequency.
    """

    def __init__(self):
        """Create the Turtle_robot bridge"""
        super().__init__('turtle_robot')
        self.frequency = 0.01

        # Subscribe to Turtlesim Pose topic with a queue size of 10
        self.create_subscription(Pose, '/turtle1/pose', self.handle_turtle_pose, 1)

        # Create a TransformBroadcaster
        self.tf_broadcaster = TransformBroadcaster(self)

        # Set the transform update rate to 10 Hz
        self.timer = self.create_timer(self.frequency, self.handleStaticFrames)

        # Store the latest pose
        self.latest_pose = None

        self.markerPublisher = self.create_publisher(Marker, "visualization_marker", 10)


    def publishMarker(self):
        marker = Marker()

        marker.header.frame_id = "world"
        marker.header.stamp = self.get_clock().now().to_msg()

        marker.ns= "basic_shapes"
        marker.id = 0
        marker.type = Marker.CUBE
        marker.action = Marker.ADD
        
        marker.pose.position.x = 5.0
        marker.pose.position.y = 0.0
        marker.pose.position.z = 0.5
        marker.pose.orientation.x = 0.0
        marker.pose.orientation.y = 0.0
        marker.pose.orientation.z = 0.0
        marker.pose.orientation.w = 1.0

        # Set marker scale (size)
        marker.scale.x = 0.25
        marker.scale.y = 10.0
        marker.scale.z = 1.0

        # Set marker color (RGBA)
        marker.color.r = 0.0
        marker.color.g = 0.0
        marker.color.b = 0.0
        marker.color.a = 1.0  

        # Publish marker
        self.markerPublisher.publish(marker)
        self.get_logger().info('Publishing marker at position: x=1.0, y=1.0, z=0.0')

    def handleStaticFrames(self):
        self.handle_broadcast('world', 'odom')
        self.handle_broadcast('base_link', 'base_footprint')
        self.handle_broadcast('base_link', 'caster_wheel')

        self.broadcast_transform()
        
        

        

    def handle_broadcast(self, parent_frame, child_frame):
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = parent_frame
        t.child_frame_id = child_frame

        # Static translation (no movement)
        t.transform.translation.x = 0.0
        t.transform.translation.y = 0.0
        t.transform.translation.z = 0.0

        # Identity rotation (no rotation)
        t.transform.rotation.x = 0.0
        t.transform.rotation.y = 0.0
        t.transform.rotation.z = 0.0
        t.transform.rotation.w = 1.0

        # Broadcast the transform
        self.tf_broadcaster.sendTransform(t)
        

    def handle_turtle_pose(self, msg):
        """Store the latest pose from the turtlesim node"""
        self.latest_pose = msg

    def broadcast_transform(self):
        """Broadcast transform if we have a pose"""
        if self.latest_pose is None:
            return  # No pose available yet

        # Create and broadcast the transform based on the latest pose
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'odom'
        t.child_frame_id = 'base_link'

        # self.latest_pose.x
        # self.latest_pose.y
        t.transform.translation.x = 0.0
        t.transform.translation.y = 0.0
        t.transform.translation.z = 0.0  # Assuming 2D movement

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
