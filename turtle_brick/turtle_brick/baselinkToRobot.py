import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster

class BaseLinkToRobot(Node):
    def __init__(self):
        super().__init__('baselinkToRobot')
        self.tf_broadcaster = TransformBroadcaster(self)
        # Single timer to handle all broadcasts at 0.02 seconds (50 Hz)
        self.timer = self.create_timer(0.02, self.broadcast_transforms)

    def broadcast_transforms(self):
        self.broadcast_transform('world', 'base_footprint')

        # Broadcast for my_robot (base_link -> my_robot)
        self.broadcast_transform('base_link', 'my_robot')

        # Broadcast for left_wheel (base_link -> left_wheel)
        self.broadcast_transform('base_link', 'left_wheel')

        # Broadcast for right_wheel (base_link -> right_wheel)
        self.broadcast_transform('base_link', 'right_wheel')

        # Broadcast for caster_wheel (base_link -> caster_wheel)
        self.broadcast_transform('base_link', 'caster_wheel')
        

    

def main(args=None):
    rclpy.init(args=args)
    node = BaseLinkToRobot()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
