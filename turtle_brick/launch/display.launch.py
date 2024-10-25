import launch
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import LaunchConfiguration
import os
import launch_ros

def generate_launch_description():
    pkgPath = FindPackageShare('turtle_brick').find('turtle_brick')
    urdfModelPath = os.path.join(pkgPath, 'my_robot.urdf')
    rvizConfigPath = os.path.join(pkgPath,'my_robot_config.rviz')

    # Read URDF file contents
    with open(urdfModelPath, 'r') as infp:
        robot_desc = infp.read()

    params = {'robot_description': robot_desc}

    # Robot State Publisher Node
    robot_state_publisher_node = launch_ros.actions.Node(
        package="robot_state_publisher",
        executable='robot_state_publisher',
        output='screen',
        parameters=[params]
    )
    
    # Joint State Publisher Node
    joint_state_publisher_node = launch_ros.actions.Node(
        package="joint_state_publisher",
        executable='joint_state_publisher',
        condition=launch.conditions.IfCondition(LaunchConfiguration('gui'))
    )

    # Joint State Publisher GUI Node
    joint_state_publisher_gui_node = launch_ros.actions.Node(
        package="joint_state_publisher_gui",
        executable='joint_state_publisher_gui',
        output='screen',
        condition=launch.conditions.IfCondition(LaunchConfiguration('gui'))
    )

    # RViz2 Node
    rviz_node = launch_ros.actions.Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=["-d", rvizConfigPath],  # Load the RViz config
        output='screen'
    )

    turtle_robot_node = launch_ros.actions.Node(
        package="turtle_brick",
        executable="turtle_robot",
        name="turtle_robot",
        output="screen"
    )

    arena_node = launch_ros.actions.Node(
        package="turtle_brick",
        executable="arena",
        name="arena",
        output="screen"
    )

    turtle_sim = launch_ros.actions.Node(
        package="turtlesim",
        executable="turtlesim_node",
        name="sim",
        output="screen"
    )

    # Launch Description
    return launch.LaunchDescription([
        # Launch argument for GUI
        launch.actions.DeclareLaunchArgument(
            name='gui', default_value='True',
            description='Flag to enable joint state publisher GUI'),

        # Launch argument for model path
        launch.actions.DeclareLaunchArgument(
            name='model', default_value=urdfModelPath,
            description='Absolute path to robot URDF file'),

        robot_state_publisher_node,
        joint_state_publisher_node,
        joint_state_publisher_gui_node,
        rviz_node,
        turtle_robot_node,
        turtle_sim,
        arena_node
    ])
