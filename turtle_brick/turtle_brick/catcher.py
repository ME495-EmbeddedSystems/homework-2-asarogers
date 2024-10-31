"""Catcher ROS2 Node for Catching a Falling Brick.

This module defines the Catcher class, a ROS2 node that controls a robot
to catch a falling brick by coordinating the robot’s movements and
handling updates on the brick’s location and status.

Authors:
- [Your Name]
- Date: YYYY-MM-DD
"""

import math

from geometry_msgs.msg import Point, PoseStamped, Quaternion

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy, QoSProfile


import yaml

from turtle_brick_interfaces.msg import (
    BrickDropped,
    BrickLocation,
    Tilt,
    TurtleLocation,
)
from turtle_brick_interfaces.srv import ProvideGoalPose, StopGravity


class Catcher(Node):
    """Node that controls the robot to catch the brick."""

    def __init__(self):
        """Initialize the Catcher node."""
        super().__init__('catcher')

        # Variables
        self.frequency = 0.01  # Check location every second
        self.location = None
        self.print = self.get_logger().info
        self.turtleLocation = None
        self.canReach = False
        self.gravity = 0.0
        self.platformHeight = 0.0
        self.maxVelocity = 0.0
        self.turtleAccel = 0.0
        self.platformRadius = 0.0
        self.brickTolerance = 0.0
        self.homePositon = Point(x=5.544445, y=5.544445, z=0.0)

        config = self.declare_parameter('config_path', '')
        # Load configurations
        self.config_path = (
            config.get_parameter_value().string_value
        )
        if self.config_path:
            with open(self.config_path, 'r') as configFile:
                config = yaml.safe_load(configFile)
            self.gravity = config['robot']['gravity_accel']
            self.platformHeight = config['robot']['platform_height']
            self.maxVelocity = config['robot']['max_velocity']
            self.turtleAccel = config['robot']['turtle_accel']
            self.platformRadius = config['robot']['platform_radius']
            self.brickTolerance = config['robot']['platform_tolerance']
        else:
            self.get_logger().error('Config path not provided')

        # Set QoS profile with transient local durability and depth of 1
        qos_profile = QoSProfile(
            depth=1, durability=QoSDurabilityPolicy.TRANSIENT_LOCAL
        )

        # Subscribers
        self.create_subscription(
            TurtleLocation, 'turtle_location', self.handleBotLoc, qos_profile
        )
        self.create_subscription(
            BrickLocation, 'brick_location', self.handleBrLocation, qos_profile
        )
        self.create_subscription(
            BrickDropped, 'brick_dropped', self.handleBrickDropped, qos_profile
        )
        self.tilt_publisher = self.create_publisher(Tilt, '/tilt', qos_profile)

        # Service clients
        self.client = self.create_client(ProvideGoalPose, '/provide_goal_pose')
        self.stopGravityCl = self.create_client(StopGravity, '/stop_gravity')

        # Publishers
        self.goalPublisher = self.create_publisher(
            PoseStamped, '/goal_pose', qos_profile
        )

    def canCatch(self):
        """Determine if the robot can catch the brick in time.

        Calculates if the robot can reach the brick before it falls past
        the robot's platform height.

        Returns
        -------
        bool
            True if the robot can catch the brick, False otherwise.
        """
        height = self.brickLocation.z
        brickX = self.brickLocation.x
        brickY = self.brickLocation.y
        bias = 1.7

        turtleX = self.turtleLocation.x
        turtleY = self.turtleLocation.y

        Vmax = self.maxVelocity
        a = self.turtleAccel
        platformHeight = self.platformHeight
        timeTilBrickIsBelowTurtle = math.sqrt(
            (2 * (height - platformHeight)) / self.gravity
        )
        xDiff = brickX - turtleX
        yDiff = brickY - turtleY
        distanceFromBrick = math.sqrt((xDiff) ** 2 + (yDiff ** 2))

        timeUntilMaxVelocity = Vmax / a
        distanceCoveredDuringAccel = (1 / 2) * a * timeUntilMaxVelocity**2
        timeTilTurtleReachesBrick = 0

        if distanceCoveredDuringAccel >= distanceFromBrick:
            timeTilTurtleReachesBrick = math.sqrt((2 * distanceFromBrick) / a)
        else:
            timeTilTurtleReachesBrick = (
                timeUntilMaxVelocity
                + (distanceFromBrick - distanceCoveredDuringAccel) / Vmax
            )

        return timeTilBrickIsBelowTurtle + bias >= timeTilTurtleReachesBrick

    def sendGoalPose(self, x, y, z):
        """Send a goal pose to the service to move the robot.

        Parameters
        ----------
        x : float
            X-coordinate of the goal position.
        y : float
            Y-coordinate of the goal position.
        z : float
            Z-coordinate of the goal position.
        """
        request = ProvideGoalPose.Request()
        request.goal_pose.header.frame_id = 'odom'
        request.goal_pose.pose.position = Point(x=x, y=y, z=z)
        q = Quaternion(x=0.0, y=0.0, z=0.0, w=1.0)
        request.goal_pose.pose.orientation = q

        future = self.client.call_async(request)
        future.add_done_callback(self.handle_response)

    def handle_response(self, future):
        """Handle the response from the goal pose service call.

        Parameters
        ----------
        future : rclpy.task.Future
            The future object containing the service call result.
        """
        try:
            response = future.result()
            if response.success:
                self.get_logger().info('sent successfully!')
            else:
                self.get_logger().info('Failed to set goal pose.')
        except Exception as e:
            self.get_logger().error(f'Service call failed: {e}')

    def handleBrickDropped(self, msg):
        """React to a brick being dropped by setting the robot's goal position.

        Parameters
        ----------
        msg : BrickDropped
            Message indicating the brick has been dropped.
        """
        self.canReach = self.canCatch()
        self.sendGoalPose(
            self.brickLocation.x, self.brickLocation.y, self.brickLocation.z
        )

    def checkTolerance(self, value1, value2, tolerance):
        """Check if two values are within a specified tolerance.

        Parameters
        ----------
        value1 : float
            The first value to compare.
        value2 : float
            The second value to compare.
        tolerance : float
            The acceptable difference between the two values.

        Returns
        -------
        bool
            True if the values are within tolerance, False otherwise.
        """
        return abs(value1 - value2) <= tolerance

    def handleBotLoc(self, msg):
        """Update the robot's location based on a received TurtleLocation msg.

        Parameters
        ----------
        msg : TurtleLocation
            The turtle location message containing updated coordinates.
        """
        self.turtleLocation = msg

    def handleBrLocation(self, msg):
        """Handle updates to the brick location and take action if reachable.

        Parameters
        ----------
        msg : BrickLocation
            The brick location message containing updated coordinates.
        """
        self.brickLocation = msg
        if self.canReach:
            if self.checkTolerance(
                self.platformHeight, self.brickLocation.z, self.brickTolerance
            ):
                self.print('caught!')
                request = StopGravity.Request()
                request.stopped = True
                future = self.stopGravityCl.call_async(request)
                future.add_done_callback(self.handle_response)

                # Move robot to home position after catching the brick
                x, y, z = self.homePositon.x, self.homePositon.y, 1.0
                self.sendGoalPose(x, y, z)

            # Tilt platform if brick is near home position
            if self.brickLocation:
                if self.checkTolerance(
                    self.brickLocation.x, self.homePositon.x, 0.2
                ) and self.checkTolerance(
                    self.brickLocation.y, self.homePositon.y, 0.2
                ):
                    tilt = Tilt()
                    tilt.tilt = 0.5
                    self.tilt_publisher.publish(tilt)
                    self.canReach = False


def main(args=None):
    """Initialize and run the Catcher node."""
    rclpy.init(args=args)
    node = Catcher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
