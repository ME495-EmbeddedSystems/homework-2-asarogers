import rclpy
from rclpy.node import Node
import yaml
from rclpy.qos import QoSProfile, QoSDurabilityPolicy
from turtle_brick_interfaces.msg import TurtleLocation, BrickLocation, BrickDropped
from geometry_msgs.msg import PoseStamped
from std_srvs.srv import Empty

class Catcher(Node):
    """
    Node that controls the robot to catch the brick.
    """

    def __init__(self):
        """Creates catcher node"""
        super().__init__('catcher')
        
        # Variables
        self.frequency = 0.01 # Check location every second
        self.location = None
        self.print = self.get_logger().info
        self.turtleLocation = None
        self.canReach = True

        # Set QoS profile with transient local durability and depth of 1
        qos_profile = QoSProfile(depth=1, durability=QoSDurabilityPolicy.TRANSIENT_LOCAL)

        # Subscribers
        self.create_subscription(TurtleLocation, 'turtle_location', self.handleTurtleLocation,qos_profile)
        self.create_subscription(BrickLocation, 'brick_location', self.handleBrickLocation,qos_profile)
        self.create_subscription(BrickDropped, 'brick_dropped', self.handleBrickDropped,qos_profile)


        #Publishers
        self.goalPublisher = self.create_publisher(PoseStamped, '/goal_pose', qos_profile)
        

    def handleBrickDropped(self, msg):
        if self.canReach == True:
            self.print("checking this works")


    def handleTurtleLocation(self, msg):
        """Subscribe to the turtle msg node and update the location whenever a new msg is received"""
        self.turtleLocation = msg
        
    def handleBrickLocation(self, msg):
        """Subscription to the brickLocation msg that is called everytime the brick's location updates"""
        self.brickLocation = msg

def main(args=None):
    rclpy.init(args=args)
    node = Catcher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
