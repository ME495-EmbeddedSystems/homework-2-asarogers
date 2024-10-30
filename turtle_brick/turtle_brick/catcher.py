import rclpy
from rclpy.node import Node
import yaml
from rclpy.qos import QoSProfile, QoSDurabilityPolicy
from turtle_brick_interfaces.msg import TurtleLocation, BrickLocation, BrickDropped, Tilt
from geometry_msgs.msg import PoseStamped, Pose, Point, Quaternion
from std_srvs.srv import Empty
import math
from turtle_brick_interfaces.srv import ProvideGoalPose,StopGravity

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
        self.canReach = False
        self.gravity =  0.0
        self.platformHeight =  0.0
        self.maxVelocity =  0.0
        self.turtleAccel = 0.0
        self.platformRadius =0.0
        self.brickTolerance = 0.0
        self.homePositon = Point(x = 5.544445, y=5.544445, z = 0.0)
        self.config_path = self.declare_parameter('config_path', '').get_parameter_value().string_value
        if self.config_path:
            with open(self.config_path, 'r') as configFile:
                config = yaml.safe_load(configFile)
            self.gravity = config['robot']['gravity_accel']
            self.platformHeight = config['robot']['platform_height']
            self.maxVelocity = config['robot']['max_velocity']
            self.turtleAccel  = config['robot']['turtle_accel']
            self.platformRadius  = config['robot']['platform_radius']
            self.brickTolerance = config['robot']['platform_tolerance']  
        else:
            self.get_logger().error('Config path not provided')

        # Set QoS profile with transient local durability and depth of 1
        qos_profile = QoSProfile(depth=1, durability=QoSDurabilityPolicy.TRANSIENT_LOCAL)

        # Subscribers
        self.create_subscription(TurtleLocation, 'turtle_location', self.handleTurtleLocation,qos_profile)
        self.create_subscription(BrickLocation, 'brick_location', self.handleBrickLocation,qos_profile)
        self.create_subscription(BrickDropped, 'brick_dropped', self.handleBrickDropped,qos_profile)
        self.tilt_publisher = self.create_publisher(Tilt, '/tilt', qos_profile)

        # client
        self.client = self.create_client(ProvideGoalPose, '/provide_goal_pose')
        self.stopGravityClient = self.create_client(StopGravity, '/stop_gravity')



        #Publishers
        self.goalPublisher = self.create_publisher(PoseStamped, '/goal_pose', qos_profile)
    def canCatch(self):
        height = self.brickLocation.z
        brickX = self.brickLocation.x
        brickY = self.brickLocation.y
        bias = 1.7

        turtleX = self.turtleLocation.x
        turtleY = self.turtleLocation.y

        Vmax = self.maxVelocity
        a = self.turtleAccel 
        platformHeight = self.platformHeight
        # sqrt((2 * h)/g)
        timeUntilBrickIsBelowTurtle = math.sqrt((2 * (height-platformHeight))/self.gravity)
        distanceFromBrick = math.sqrt((brickX- turtleX)**2 + (brickY - turtleY)**2)

        timeUntilMaxVelocity = Vmax / a

        distanceCoveredDuringAcceleration = (1/2)*a*timeUntilMaxVelocity**2
        timeUntilTurtleReachesBrick = 0
        

        if distanceCoveredDuringAcceleration >= distanceFromBrick:
            timeUntilTurtleReachesBrick = math.sqrt((2 * distanceFromBrick)/a)
        else:
            timeUntilTurtleReachesBrick = timeUntilMaxVelocity +(distanceFromBrick - distanceCoveredDuringAcceleration)/Vmax


        return timeUntilBrickIsBelowTurtle + bias >= timeUntilTurtleReachesBrick
    
    def sendGoalPose(self, x, y, z):
        # Create the request message
        request = ProvideGoalPose.Request()
        
        # Fill in the header, position, and orientation for goal pose
        request.goal_pose.header.frame_id = 'odom'
        request.goal_pose.pose.position = Point(x=x, y=y, z=z)
        request.goal_pose.pose.orientation = Quaternion(x=0.0, y=0.0, z=0.0, w=1.0)

        # Call the service
        future = self.client.call_async(request)
        
        # Set a callback for the service response
        future.add_done_callback(self.handle_response)

    def handle_response(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info('sent successfully!')
            else:
                self.get_logger().info('Failed to set goal pose.')
        except Exception as e:
            self.get_logger().error(f'Service call failed: {e}')

    def handleBrickDropped(self, msg):
        self.canReach = self.canCatch()
        
        self.sendGoalPose(self.brickLocation.x,self.brickLocation.y,self.brickLocation.z)

        

    def checkTolerance(self, value1, value2, tolerance):
        return abs(value1 - value2) <= tolerance

    def handleTurtleLocation(self, msg):
        """Subscribe to the turtle msg node and update the location whenever a new msg is received"""
        self.turtleLocation = msg
        
        
                
        
    def handleBrickLocation(self, msg):
        """Subscription to the brickLocation msg that is called everytime the brick's location updates"""
        self.brickLocation = msg
        if self.canReach:
            
            if self.checkTolerance(self.platformHeight, self.brickLocation.z, self.brickTolerance):
                self.print("caught!")
                request = StopGravity.Request()
                request.stopped = True
                future = self.stopGravityClient.call_async(request)
        
                # Set a callback for the service response
                future.add_done_callback(self.handle_response)
                x=self.homePositon.x
                y=self.homePositon.y
                z = 1.0
                self.sendGoalPose(x,y,z)

            if self.brickLocation:
                if self.checkTolerance(self.brickLocation.x, self.homePositon.x, 0.2) and self.checkTolerance(self.brickLocation.y, self.homePositon.y, 0.2):
                    tilt= Tilt()
                    tilt.tilt =0.5
                    self.tilt_publisher.publish(tilt)
                    self.canReach = False

    def handle_response(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info('sent successfully!')
            else:
                self.get_logger().info('Failed to set goal pose.')
        except Exception as e:
            self.get_logger().error(f'Service call failed: {e}')
        

def main(args=None):
    rclpy.init(args=args)
    node = Catcher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
