"""Module containing unit tests for the physics.World class.

This module tests various functionalities of the physics.World class, including
initialization, gravity manipulation, dropping bricks, and calculating
distances.
"""

import math

import pytest

# Replace 'your_module' with the actual module name
from turtle_brick import physics


def test_initialization():
    """Test the initialization of the physics.World class.

    Ensure all attributes are initialized with the correct values.
    """
    brick_location = (0, 0, 10)
    gravity = 9.81
    radius = 5
    dt = 0.1

    world = physics.World(brick_location, gravity, radius, dt)

    assert world.location == brick_location
    assert world.gravity == gravity
    assert world.radius == radius
    assert world.dt == dt
    assert world.velocity == 0
    assert world.horizontal_velocity == [0, 0]
    assert world.isOnPlatform is False
    assert world.tiltAngle == 0.0


def test_brick_property():
    """Test getting and setting the brick location.

    Ensure the brick location can be set and retrieved correctly.
    """
    world = physics.World((0, 0, 10), 9.81, 5, 0.1)
    assert world.brick == (0, 0, 10)

    new_location = (1, 1, 5)
    world.brick = new_location
    assert world.location == new_location


def test_drop():
    """Test the drop method to ensure it updates the z position correctly.

    Verify that the brick's z position changes correctly when gravity is
    applied and the drop method is called.
    """
    initial_location = (0, 0, 10)
    gravity = 9.81
    dt = 0.1
    world = physics.World(initial_location, gravity, 5, dt)

    result = world.drop()
    x, y, z = world.location
    expected_z = initial_location[2] + world.velocity * dt

    assert z == pytest.approx(expected_z, rel=1e-2)
    assert result == (z > 0)  # Should be True if above ground level


def test_stop_gravity():
    """Test the stopGravity method to ensure gravity is stopped.

    Verify that gravity is set to zero and the brick is on the platform.
    """
    world = physics.World((0, 0, 10), 9.81, 5, 0.1)
    world.stopGravity()

    assert world.gravity == 0
    assert world.isOnPlatform


def test_start_falling():
    """Test the start_falling method to ensure gravity is applied again.

    Verify that gravity is restored and the brick starts falling.
    """
    world = physics.World((0, 0, 10), 0, 5, 0.1)  # Start with gravity = 0
    world.start_falling()

    assert world.gravity == 9.81
    assert world.isOnPlatform is False
    assert world.horizontal_velocity == [0, 0]


def test_distance_from_platform_center():
    """Test distance_from_platform_center method for accuracy.

    Verify that the calculated distance from the brick to the platform center
    is accurate.
    """
    brick_location = (4, 3, 10)
    platform_center_x = 0
    platform_center_y = 0
    world = physics.World(brick_location, 9.81, 5, 0.1)

    distance = world.distance_from_platform_center(platform_center_x,
                                                   platform_center_y)
    expected_distance = math.sqrt(
        (brick_location[0] - platform_center_x) ** 2
        + (brick_location[1] - platform_center_y) ** 2
    )

    assert distance == pytest.approx(expected_distance, rel=1e-2)