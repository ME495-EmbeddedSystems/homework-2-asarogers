from geometry_msgs.msg import TransformStamped

import rclpy
from rclpy.node import Node

from tf2_ros import TransformBroadcaster


class worldFrame(Node):
    def __init__(self):
       super().__init__('worldFrame')
       self.tf_broadcaster = TransformBroadcaster(self)
       self.timer = self.create_timer(0.1, self.broadcast_timer_callback)
       
        
    def broadcast_timer_callback(self):
       t = TransformStamped()
       t.header.stamp = self.get_clock().now().to_msg()
       t.header.frame_id = 'world'
       t.child_frame_id = 'base_link'
       t.transform.translation.x = 1.0
       t.transform.translation.y = 0.0
       t.transform.translation.z = 0.0
       t.transform.rotation.x = 0.0
       t.transform.rotation.y = 0.0
       t.transform.rotation.z = 0.0
       t.transform.rotation.w = 1.0
       self.tf_broadcaster.sendTransform(t)

       


def main():
    rclpy.init()
    node = worldFrame()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    rclpy.shutdown()