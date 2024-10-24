import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster
import tf_transformations

class TurtleRobot(Node):
    """
    Node pushes messages at a fixed frequency.
    """

    def __init__(self):
        """Create the Turtle_robot bridge"""
        super().__init__('turtle_robot')

        # Subscribe to Turtlesim Pose topic with a queue size of 10
        self.create_subscription(Pose, '/turtle1/pose', self.handle_turtle_pose, 10)

        # Create a TransformBroadcaster
        self.tf_broadcaster = TransformBroadcaster(self)

        # Set the transform update rate to 10 Hz
        self.timer = self.create_timer(0.1, self.broadcast_transforms)
        # Store the latest pose
        self.latest_pose = None

    def broadcast_transforms(self):
        self.handle_broadcast('world', 'base_footprint')

        # Broadcast for my_robot (base_link -> my_robot)
        self.handle_broadcast('base_footprint', 'base_link')

        # # Broadcast for left_wheel (base_link -> left_wheel)
        self.handle_broadcast('base_link', 'my_robot')

        # # Broadcast for right_wheel (base_link -> right_wheel)
        # self.handle_broadcast('base_link', 'right_wheel')

        # # Broadcast for caster_wheel (base_link -> caster_wheel)
        # self.handle_broadcast('base_link', 'caster_wheel')
        

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
        t.header.frame_id = 'base_footprint'
        t.child_frame_id = 'base_link'

        t.transform.translation.x = self.latest_pose.x
        t.transform.translation.y = self.latest_pose.y
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
