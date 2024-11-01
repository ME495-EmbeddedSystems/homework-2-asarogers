<!--########################## Begin_Citation [14] ############################ -->


# ME495 Embedded Systems Homework 2
Author: Asa Rogers

This package, `turtle_brick`, simulates a turtle robot that interacts with an arena and brick within the ROS 2 environment. The turtle attempts to catch a falling brick by coordinating its movements in the arena based on physics and real-time positioning. The simulation utilizes RViz for visualization and integrates a variety of ROS 2 services and messages to control the turtle's actions and the environment.

## Quickstart

1. **Launch the Simulation**:
   - Use the following command to launch the arena and turtle simulation:
     ```bash
     colcon clean workspace -y && colcon build && source install/setup.bash && ros2 launch turtle_brick show_turtle.launch.py
     ```
   - This will start the turtle simulation in the RViz environment, along with the `arena`, `catcher`, and `turtle_robot` nodes.

2. **Place the brick**:
   - Use this command to place the brick in the arena at a x, y, z position:
     ```bash
     source install/setup.bash && ros2 service call /place turtle_brick_interfaces/srv/Place "{x: 5.0, y: 1.0, z: 10.0}" 
     ```
3. **Drop the Brick**:
   - Use this command to drop the brick:
     ```bash
     ros2 service call /drop std_srvs/srv/Empty
     ```
   - This initiates the brick’s descent, which the turtle will attempt to catch if it is within reachable range.

3. **Videos**:
   - Here are videos demonstrating the turtle's behavior under different scenarios:

     - **Brick within Catching Range**: 


https://github.com/user-attachments/assets/f1b761af-260b-4811-ad84-d7fab31af753



     - **Brick Out of Reach**: 



https://github.com/user-attachments/assets/f6450228-a2dd-4671-998b-92e5491f5306


## Functionality Overview

The package defines nodes and services as follows:

- **Arena** (`arena` node): Initializes the arena environment in RViz, including walls and a platform. It also provides services for placing, dropping, and stopping the brick’s gravity to simulate sticking on the turtle platform.

- **Catcher** (`catcher` node): Controls the turtle’s movements to attempt catching the brick. It calculates reachability based on brick and turtle positions and uses the `stop_gravity` service to catch the brick if reachable.

- **Turtle Robot** (`turtle_robot` node): Manages turtle robot simulation within the arena, handling dynamic frames, transformations, and velocities for movement control.

<!--########################## End_Citation [14] ############################ -->
