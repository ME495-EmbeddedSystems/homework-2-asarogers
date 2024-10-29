import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster
import tf_transformations
from visualization_msgs.msg import Marker
from geometry_msgs.msg import Point, Quaternion
import math
from rclpy.qos import QoSProfile, QoSDurabilityPolicy
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster
from turtle_brick_interfaces.srv import Place
from turtle_brick import physics
from std_srvs.srv import Empty
import yaml



class Arena(Node):
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
        brickScale : list
        Dimensions of the brick [x, y, z].
    brickRgba : list
        RGBA color values for the brick in the format [R, G, B, A].

    """

    def __init__(self):
        """Creates Arena node """
        super().__init__('arena')
        self.frequency = 0.01
        #             X     Y    Z
        self.wallScale =[0.25, 10.25, 2.5]
        self.wallRgba = [0.0, 0.0, 0.0, 1.0]
        self.referenceFrame = "world"
        self.brickScale = [0.1, 0.25, 0.1]  
        self.brickRgba = [0.5, 0.2, 0.0, 1.0] 
        self.dt = 0.004  
        self.gravity = -9.8  
        self.platformRadius = 0.3
        self.fall = False
        self.brickPose = None
        self.brickPhysics = None
        self.print = self.get_logger().info

        config_path = self.declare_parameter('config_path', '').get_parameter_value().string_value
        if config_path:
            with open(config_path, 'r') as configFile:
                config = yaml.safe_load(configFile)
            self.gravity = config['robot']['gravity_accel']
            self.platformHeight = config['robot']['platform_height']
            self.maxVelocity = config['robot']['max_velocity']
        else:
            self.get_logger().error('Config path not provided')



        #Transient_local ensure the last message recieves is saved, so when the subscribers connects, it immediately recieves it
        # depth specifies the number of messages stored in the history buffer
        qos_profile = QoSProfile(depth=1, durability=QoSDurabilityPolicy.TRANSIENT_LOCAL)
        self.brickOrientation = Quaternion(x = 0.0, y = 0.0, z = math.radians(45))
        self.zPoseAboveTheGrid = 1.0
        self.shiftByTurtleStart = 5.0

        self.xWallCoordinates = [[-5.0 + self.shiftByTurtleStart ,self.shiftByTurtleStart ,0.0], [5.0 + self.shiftByTurtleStart , self.shiftByTurtleStart , 0.0]]
        self.yWallCoordinates = [[-5.0 + self.shiftByTurtleStart , -self.shiftByTurtleStart ,0.0], [5.0+ self.shiftByTurtleStart , -self.shiftByTurtleStart , 0.0]]

        # Publishers
        self.tf_broadcaster = TransformBroadcaster(self)
        self.xWallPublisher = self.create_publisher(Marker, "visualization_marker", qos_profile)
        self.yWallPublisher = self.create_publisher(Marker, "visualization_marker", qos_profile)
        self.brickPublisher = self.create_publisher(Marker, "visualization_marker", qos_profile)


        # Timers
        self.timer = self.create_timer(self.frequency, self.publishMarker)
        self.timer2 = self.create_timer(self.frequency, self.publishMarker2)
        self.brickTimer = self.create_timer(self.frequency, self.brickCallback)

        # Services
        self.create_service(Place, "place", self.placeBrick)
        self.create_service(Empty, "drop", self.dropBrick)
    
        
    
    
    def dropBrick(self, request, response):
        if self.brickPose != None:
            self.fall = True
        else:
            self.get_logger.error('The brick position has not been placed. Please place the brick with the /place service \n ex) /place turtle_brick_interfaces/srv/Place "{x: 5.0, y: 2.0, z: 5.0}"')
        return response
    
    def placeBrick(self, request, response):
        """Place the brick at the request position"""
        self.brickPhysics = physics.World((request.x, request.y, request.z), self.gravity, self.platformRadius, self.dt)
        x, y, z = self.brickPhysics.brick
        self.brickPose = Point(x=x, y=y, z=z)
        response.success = True
        response.message = f"Brick placed at ({request.x}, {request.y}, {request.z})"
        return response
    
    def brickCallback(self):
        """Update the brick's physics state and publish its current position."""
        # Update the brick's position based on physics

        if self.brickPose != None:
            if self.fall == True:
                self.fall = self.brickPhysics.drop()
            x, y, z = self.brickPhysics.brick
            self.print(f"x ={x}, y={y}, z={z}")
            self.brickPose = Point(x=x, y=y, z=z)
            self.publishBrick(self.brickOrientation, self.brickPose, self.brickScale, self.brickRgba)


    def publishBrick(self, orientation, position, scale, rgba):
        """
        Publishes the brick's marker in RViz with specified orientation, position, scale, and color.

        Parameters
        ----------
        orientation : Quaternion - The orientation of the brick in the world frame.
        position : Point - The position of the brick in the world frame.
        scale : list - 3D scaling factors [x, y, z] for the brick dimensions.
        rgba : list - RGBA color values for the brick in the format [R, G, B, A].
        """
        brickMarker = Marker()
        brickMarker.header.frame_id = self.referenceFrame
        brickMarker.header.stamp = self.get_clock().now().to_msg()
        brickMarker.ns = "brick"
        brickMarker.id = 3
        brickMarker.type = Marker.CUBE
        brickMarker.action = Marker.ADD

        # Set position and orientation
        brickMarker.pose.position = position
        brickMarker.pose.orientation = orientation

        # Set scale and color
        brickMarker.scale.x = scale[0]
        brickMarker.scale.y = scale[1]
        brickMarker.scale.z = scale[2]
        brickMarker.color.r = rgba[0]
        brickMarker.color.g = rgba[1]
        brickMarker.color.b = rgba[2]
        brickMarker.color.a = rgba[3]

        # Publish the marker
        self.brickPublisher.publish(brickMarker)
    







    def publishMarker(self):
        """Publishes two wall along the x-axis"""
        self.GenerateWall(self.xWallCoordinates[0],self.xWallCoordinates[1], "x_wall", 0, self.xWallPublisher)

    def publishMarker2(self):
        """Publishes two walls along the y-axis"""
        self.GenerateWall(self.yWallCoordinates[0], self.yWallCoordinates[1], "y_wall", 1, self.yWallPublisher)

    def GenerateWall(self, firstWallPositon, secondWallPosition, nameOfCurrentFrame, id, publisher):
        """
        Creates and publishes a wall market given the two endpoints

        Parameters
        ----------
        firstWallPosition : list - starting point [x, y, z] for the wall.
        secondWallPosition : list - ending point [x, y, z] for the wall.
        nameOfCurrentFrame : str - reference frame for the marker (e.g., "x_wall" or "y_wall").
        id : int - unique identifier for each wall marker.
        """
        marker = Marker()
        marker.header.frame_id = self.referenceFrame
        marker.header.stamp = self.get_clock().now().to_msg()

        angle = math.radians(90 * id)
        marker.pose.orientation = self.create_quaternion_from_yaw(angle)
        marker.pose.position.z = self.zPoseAboveTheGrid

        marker.ns= nameOfCurrentFrame
        marker.id = id
        marker.type = Marker.CUBE_LIST
        marker.action = Marker.ADD

        marker.lifetime.sec = 0
        marker.lifetime.nanosec = 0

        cube_positions = [
            Point(x = firstWallPositon[0], y = firstWallPositon[1], z = firstWallPositon[2]),
            Point(x = secondWallPosition[0], y = secondWallPosition[1], z = secondWallPosition[2])
        ]

        marker.scale.x = self.wallScale[0]
        marker.scale.y = self.wallScale[1]
        marker.scale.z = self.wallScale[2]
        marker.points.extend(cube_positions)

        marker.color.r = self.wallRgba[0]
        marker.color.g = self.wallRgba[1]
        marker.color.b = self.wallRgba[2]
        marker.color.a = self.wallRgba[3]

        publisher.publish(marker)
    
    def create_quaternion_from_yaw(self, yaw):
        """
        Creates a quaternion representing a rotation around the z-axis by a given yaw angle.

        Parameters
        ----------
        yaw : float - angle in radians for rotation around the z-axis.

        Returns
        -------
        Quaternion - quaternion representing the yaw rotation.
        
        """
        q = tf_transformations.quaternion_from_euler(0, 0, yaw)
        return Quaternion(x=q[0], y=q[1], z=q[2], w=q[3])

def main(args=None):
    rclpy.init(args=args)
    node = Arena()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
