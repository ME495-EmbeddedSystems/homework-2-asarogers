import rclpy
from rclpy.node import Node
import yaml
from rclpy.qos import QoSProfile, QoSDurabilityPolicy
from turtle_brick_interfaces.msg import TurtleLocation, BrickLocation, BrickDropped
from geometry_msgs.msg import PoseStamped
from std_srvs.srv import Empty
import math

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
        self.gravity = None
        self.platformHeight = None
        self.maxVelocity = None
        self.config_path = self.declare_parameter('config_path', '').get_parameter_value().string_value
        if self.config_path:
            with open(self.config_path, 'r') as configFile:
                config = yaml.safe_load(configFile)
            self.gravity = config['robot']['gravity_accel']
            self.platformHeight = config['robot']['platform_height']
            self.maxVelocity = config['robot']['max_velocity']
        else:
            self.get_logger().error('Config path not provided')

        # Set QoS profile with transient local durability and depth of 1
        qos_profile = QoSProfile(depth=1, durability=QoSDurabilityPolicy.TRANSIENT_LOCAL)

        # Subscribers
        self.create_subscription(TurtleLocation, 'turtle_location', self.handleTurtleLocation,qos_profile)
        self.create_subscription(BrickLocation, 'brick_location', self.handleBrickLocation,qos_profile)
        self.create_subscription(BrickDropped, 'brick_dropped', self.handleBrickDropped,qos_profile)


        #Publishers
        self.goalPublisher = self.create_publisher(PoseStamped, '/goal_pose', qos_profile)
    def canCatch(self):
        height = self.brickLocation.z
        brickX = self.brickLocation.x
        brickY = self.brickLocation.y

        Vmax = 1.0
        a = 0.25
        platformHeight = 0.6
        # sqrt((2 * h)/g)
        timeUntilBrickIsBelowTurtle = math.sqrt((2 * height-platformHeight)/self.gravity)

        timeUntil

        
        distanceFromBrick = math.sqrt(brickX**2 + brickY**2)

        # time until turtle bot reaches the brick
        timeUntilTurtleReachesBrick = math.sqrt((2 * distanceFromBrick)/self.gravity)

        
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
