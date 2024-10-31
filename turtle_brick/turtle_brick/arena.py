"""Module that defines the class for creating an arena in the RViz environment.

This module uses ROS2 and RViz to simulate an arena with walls and a brick that
can be dropped, placed, or stuck to a platform.
"""

import math

from geometry_msgs.msg import Point, Quaternion

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy, QoSProfile

from std_srvs.srv import Empty

from tf2_ros import TransformBroadcaster

import tf_transformations

from turtle_brick import physics

from turtle_brick_interfaces.msg import (BrickDropped, BrickLocation, Tilt,
                                         TurtleLocation)
from turtle_brick_interfaces.srv import Place, StopGravity

from visualization_msgs.msg import Marker

import yaml


class Arena(Node):
    """Node that creates an arena in the RViz environment.

    Publishes
    ---------
    Marker : visualization_msgs/msg/Marker - markers to visualize walls.

    Parameters
    ----------
    frequency : float - timer frequency in seconds to control update rate
    scale: list - 3D scaling factors [x, y, z] for wall dimensions.
    rgba : list - RGBA color values for the walls in the format [R, G, B, A]
        brickScale : list
        Dimensions of the brick [x, y, z].
    brickRgba : list
        RGBA color values for the brick in the format [R, G, B, A].
    """

    def __init__(self):
        """Create an Arena node."""
        super().__init__('arena')
        self.frequency = 0.01
        #             X     Y    Z
        self.wallScale = [0.25, 12.5, 2.5]
        self.wallRgba = [0.0, 0.0, 0.0, 1.0]
        self.referenceFrame = 'world'
        self.brScale = [0.1, 0.25, 0.1]
        self.brRgba = [0.5, 0.2, 0.0, 1.0]
        self.dt = 0.004
        self.gravity = -9.8
        self.platformRadius = 0.3
        self.fall = False
        self.brickPose = None
        self.brickPhysics = None
        self.print = self.get_logger().info
        self.brickZPositon = 0.0
        self.caught = False
        self.turtleLocation = None
        self.brickTolerance = 0.0
        self.homePositon = Point(x=5.544445, y=5.544445, z=0.0)
        self.tilt = 0.0
        config = self.declare_parameter('config_path', '')
        config_path = (
            config.get_parameter_value().string_value
        )
        if config_path:
            with open(config_path, 'r') as configFile:
                config = yaml.safe_load(configFile)
            self.gravity = config['robot']['gravity_accel']
            self.platformHeight = config['robot']['platform_height']
            self.maxVelocity = config['robot']['max_velocity']
            self.brickTolerance = config['robot']['platform_tolerance']
        else:
            self.get_logger().error('Config path not provided')

        qos_profile = QoSProfile(
            depth=1, durability=QoSDurabilityPolicy.TRANSIENT_LOCAL
        )
        self.brOrientation = Quaternion(x=0.0, y=0.0, z=math.radians(45))
        self.zPoseAboveTheGrid = 1.0
        self.shiftByTurtleStart = 5.0

        self.xWallCoordinates = [
            [-5.5 + self.shiftByTurtleStart, self.shiftByTurtleStart, 0.0],
            [6.2 + self.shiftByTurtleStart, self.shiftByTurtleStart, 0.0],
        ]
        self.yWallCoordinates = [
            [-5.4 + self.shiftByTurtleStart, -self.shiftByTurtleStart, 0.0],
            [6.4 + self.shiftByTurtleStart, -self.shiftByTurtleStart, 0.0],
        ]

        # Publishers
        self.tf_broadcaster = TransformBroadcaster(self)
        self.xWallPublisher = self.create_publisher(
            Marker, 'visualization_marker1', qos_profile
        )
        self.yWallPublisher = self.create_publisher(
            Marker, 'visualization_marker2', qos_profile
        )
        self.brickPublisher = self.create_publisher(
            Marker, 'visualization_marker3', qos_profile
        )
        self.brickLocationPublisher = self.create_publisher(
            BrickLocation, 'brick_location', qos_profile
        )
        self.brickDroppedPublisher = self.create_publisher(
            BrickDropped, 'brick_dropped', qos_profile
        )
        self.tilt_publisher = self.create_publisher(Tilt, '/tilt', qos_profile)

        # Timers
        self.xWallTimer = self.create_timer(self.frequency, self.publishMarker)
        self.yWallTime = self.create_timer(self.frequency, self.publishMarker2)
        self.brickTimer = self.create_timer(self.frequency, self.brickCallback)

        # Services
        self.create_subscription(Tilt, '/tilt', self.handle_tilt, 1)
        self.create_service(Place, 'place', self.placeBrick)
        self.create_service(Empty, 'drop', self.dropBrick)
        self.create_service(StopGravity, 'stop_gravity', self.stickToBot)
        self.create_subscription(
            TurtleLocation, 'bot_location', self.handleBotLocation, qos_profile
        )

    def handleBotLocation(self, msg):
        """Subscribe to the turtle location topic and update the location.

        Parameters
        ----------
        msg : TurtleLocation
            The message containing the updated turtle location.
        """
        self.turtleLocation = msg

    def stickToBot(self, reqest, response):
        """Stick the brick to the platform if it is falling.

        Parameters
        ----------
        reqest : StopGravity.Request
            The request to stop gravity.
        response : StopGravity.Response
            The response to indicate success or failure.

        Returns
        -------
        StopGravity.Response
            The response after processing the request.
        """
        try:
            if self.fall:
                self.brickPhysics.stopGravity()
                self.caught = True
            else:
                self.get_logger().error(
                    'Brick not placed. Use /place service to place the brick.'
                )
        except Exception as er:
            self.print(f' error = {er}')
        return response

    def dropBrick(self, request, response):
        """Notify that the brick has begun falling.

        Parameters
        ----------
        request : Empty.Request
            The request to drop the brick.
        response : Empty.Response
            The response indicating the drop status.

        Returns
        -------
        Empty.Response
            The response after processing the drop request.
        """
        try:
            if self.brickPose is not None:
                self.fall = True
                dropped = BrickDropped()
                dropped.is_dropped = True
                if not self.caught:
                    self.brickDroppedPublisher.publish(dropped)
            else:
                self.get_logger().error(
                    'Brick not placed. Use /place service to place the brick.'
                )
        except Exception as er:
            self.print(f' error = {er}')
        return response

    def placeBrick(self, request, response):
        """Place the brick at the requested position.

        Parameters
        ----------
        request : Place.Request
            The request containing the brick placement coordinates.
        response : Place.Response
            The response indicating the placement status.

        Returns
        -------
        Place.Response
            The response after processing the placement request.
        """
        self.brickPhysics = physics.World(
            (request.x, request.y, request.z),
            self.gravity,
            self.platformRadius,
            self.dt,
        )
        x, y, z = self.brickPhysics.brick
        self.brickPose = Point(x=x, y=y, z=z)
        response.success = True
        response.message = f'Brick @ ({request.x}, {request.y}, {request.z})'
        brickLocation = BrickLocation()
        brickLocation.x = x
        brickLocation.y = y
        brickLocation.z = z
        self.brickLocationPublisher.publish(brickLocation)
        return response

    def brickCallback(self):
        """Update the brick's location and publish it."""
        x, y, z = 0.0, 0.0, 0.0
        if self.brickPose is not None:
            if self.fall:
                self.fall = self.brickPhysics.drop()
                if self.fall is False and self.caught is True:
                    tilt = Tilt()
                    tilt.tilt = 0.0
                    self.tilt_publisher.publish(tilt)
            if self.caught:
                x = self.turtleLocation.x
                y = self.turtleLocation.y
                z = self.platformHeight + self.brickTolerance
                tilt_angle = self.tilt
                self.brickPhysics.stickToPlatform(x, y, z, tilt_angle)
            else:
                x, y, z = self.brickPhysics.brick

            self.brickPose = Point(x=x, y=y, z=z)
            self.publishBrick(
                self.brOrientation, self.brickPose, self.brScale, self.brRgba
            )

    def handle_tilt(self, msg):
        """Set the tilt based on the received message.

        Parameters
        ----------
        msg : Tilt
            The message containing the tilt value.
        """
        self.print('received tilt!!')
        self.tilt = msg.tilt
        self.fall = True
        self.caught = False
        self.brickPhysics.start_falling()

    def publishBrick(self, orientation, position, scale, rgba):
        """Publish the brick's marker in RViz.

        Parameters
        ----------
        orientation : Quaternion
            The orientation of the brick in the world frame.
        position : Point
            The position of the brick in the world frame.
        scale : list
            3D scaling factors [x, y, z] for the brick dimensions.
        rgba : list
            RGBA color values for the brick in the format [R, G, B, A].
        """
        brickMarker = Marker()
        brickMarker.header.frame_id = self.referenceFrame
        brickMarker.header.stamp = self.get_clock().now().to_msg()
        brickMarker.ns = 'brick'
        brickMarker.id = 3
        brickMarker.type = Marker.CUBE
        brickMarker.action = Marker.ADD

        brickMarker.pose.position = position
        brickMarker.pose.orientation = orientation

        brickMarker.scale.x = scale[0]
        brickMarker.scale.y = scale[1]
        brickMarker.scale.z = scale[2]
        brickMarker.color.r = rgba[0]
        brickMarker.color.g = rgba[1]
        brickMarker.color.b = rgba[2]
        brickMarker.color.a = rgba[3]

        self.brickPublisher.publish(brickMarker)
        brickLocation = BrickLocation()
        brickLocation.x = position.x
        brickLocation.y = position.y
        brickLocation.z = position.z
        self.brickLocationPublisher.publish(brickLocation)

    def publishMarker(self):
        """Publish walls along the x-axis."""
        self.GenerateWall(
            self.xWallCoordinates[0],
            self.xWallCoordinates[1],
            'x_wall',
            0,
            self.xWallPublisher,
        )

    def publishMarker2(self):
        """Publish walls along the y-axis."""
        self.GenerateWall(
            self.yWallCoordinates[0],
            self.yWallCoordinates[1],
            'y_wall',
            1,
            self.yWallPublisher,
        )

    def GenerateWall(
        self, firstWallPositon, secondWallPosition, givenFrame, _id, publisher
    ):
        """Create and publish a wall marker.

        Parameters
        ----------
        firstWallPosition : list
            Starting point [x, y, z] for the wall.
        secondWallPosition : list
            Ending point [x, y, z] for the wall.
        givenFrame : str
            Reference frame for the marker (e.g., 'x_wall' or 'y_wall').
        id : int
            Unique identifier for each wall marker.
        publisher : Publisher
            Publisher to publish the wall marker.
        """
        marker = Marker()
        marker.header.frame_id = self.referenceFrame
        marker.header.stamp = self.get_clock().now().to_msg()

        angle = math.radians(90 * _id)
        marker.pose.orientation = self.create_quaternion_from_yaw(angle)
        marker.pose.position.z = self.zPoseAboveTheGrid

        marker.ns = givenFrame
        marker.id = _id
        marker.type = Marker.CUBE_LIST
        marker.action = Marker.ADD

        marker.lifetime.sec = 0
        marker.lifetime.nanosec = 0

        cube_positions = [
            Point(x=firstWallPositon[0],
                  y=firstWallPositon[1],
                  z=firstWallPositon[2]),
            Point(
                x=secondWallPosition[0],
                y=secondWallPosition[1],
                z=secondWallPosition[2],
            ),
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
        """Create a quaternion representing a rotation around the z-axis.

        Parameters
        ----------
        yaw : float
            Angle in radians for rotation around the z-axis.

        Returns
        -------
        Quaternion
            Quaternion representing the yaw rotation.
        """
        q = tf_transformations.quaternion_from_euler(0, 0, yaw)
        return Quaternion(x=q[0], y=q[1], z=q[2], w=q[3])


def main(args=None):
    """Initialize and spin the Arena node."""
    rclpy.init(args=args)
    node = Arena()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
