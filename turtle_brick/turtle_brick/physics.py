"""Physics simulation for a falling brick in a 3D environment.

This module defines the World class, which tracks the position and movement
of a brick within a simulated environment under gravity. The class provides
methods to handle brick dropping, sticking to a platform, and calculating
distances from a platform center. The simulation includes tilt effects, and
parameters like gravity and timestep for realistic motion.

Classes:
- World: Manages the physics of a brick in the 3D environment.

Authors:
- Asa Rogers
- Date: 2024-10-30
"""

import math


class World:
    """Keep track of the physics of the world."""

    def __init__(self, brick, gravity, radius, dt):
        """Initialize the world.

        Args:
        brick - The (x,y,z) location of the brick
        gravity - the acceleration due to gravity in m/s^2
        radius - the radius of the platform
        dt - timestep in seconds of the physics simulation
        """
        self.brick = brick
        self.gravity = gravity
        self.radius = radius
        self.dt = dt
        self.location = brick
        self.velocity = 0
        self.horizontal_velocity = [0, 0]
        self.isOnPlatform = False
        self.tiltAngle = 0.0

    @property
    def brick(self):
        """Get the brick's location.

        Return:
            (x,y,z) location of the brick
        """
        return self.location

    @brick.setter
    def brick(self, location):
        """Set the brick's location.

        Args:
           location - the (x,y,z) location of the brick
        """
        self.location = location

    def drop(self):
        """Update the brick's location by it fall in gravity for 1 timestep."""
        self.velocity += -self.gravity * self.dt

        # ----------------------------[7] begin_citation ------------------- #
        x, y, z = self.location
        # ----------------------------[7] begin_citation ---------------------#

        x_new = x + (1 / 2) * self.gravity * self.dt**2 * math.sin(
            self.tiltAngle
        ) * math.cos(self.tiltAngle)
        gravityDiff = (1 / 2) * self.gravity * self.dt**2
        y_new = y - gravityDiff * math.sin(self.tiltAngle) ** 2

        # ---------------------------- begin_citation ----------------------- #
        new_z = z + self.velocity * self.dt  # Update the z-coordinate

        self.location = (x_new, y_new, new_z)
        # ---------------------------- begin_citation ----------------------- #
        return new_z > 0

    def stopGravity(self):
        """When called, stop the brick's gravity."""
        self.gravity = 0
        self.isOnPlatform = True

    def stickToPlatform(self, platform_x, platform_y, platform_z, tilt_angle):
        """Stick the brick to the platform's position and angle.

        Args:
            platform_x, platform_y, platform_z - platform's location
        """
        self.location = (platform_x, platform_y, platform_z)
        self.isOnPlatform = True

    def start_falling(self):
        """Reset gravity and velocity."""
        self.horizontal_velocity = [0, 0]
        self.isOnPlatform = False
        self.gravity = 9.81
        self.velocity += -self.gravity * self.dt

    def distance_from_platform_center(self, platform_x, platform_y):
        """Calculate the distance of the brick from the platform center.

        Args:
            platform_x, platform_y - platform center coordinates

        Returns:
            float - distance from the platform center
        """
        x, y, _ = self.location
        return math.sqrt((x - platform_x) ** 2 + (y - platform_y) ** 2)
