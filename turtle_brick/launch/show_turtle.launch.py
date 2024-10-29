import os
import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import xacro 
import yaml

def generate_launch_description():
    # Package paths
    pkgPath = FindPackageShare('turtle_brick').find('turtle_brick')
    urdfModelPath = os.path.join(pkgPath, 'turtle.urdf.xacro')
    rvizConfigPath = os.path.join(pkgPath, 'my_robot_config.rviz')
    configPath = os.path.join(pkgPath, 'turtle.yaml')

    with open(configPath, 'r') as configFile:
        config = yaml.safe_load(configFile)

    # Read URDF file contents
    robot_desc = xacro.process_file(
        urdfModelPath,
        mappings={
            'platform_height': str(config['robot']['platform_height']),
            'wheel_radius': str(config['robot']['wheel_radius']),
            'max_velocity': str(config['robot']['max_velocity']),
            'gravity_accel': str(config['robot']['gravity_accel'])
        }
    ).toxml()

    # Launch arguments
    jsp_arg = DeclareLaunchArgument(
        'use_jsp',
        default_value='gui',
        description=(
            'Controls which joint state publisher to start:\n'
            '"gui" for joint_state_publisher_gui\n'
            '"jsp" for joint_state_publisher\n'
            '"none" for no joint state publisher'
        )
    )

    rviz_config_arg = DeclareLaunchArgument(
        'rviz_config',
        default_value=rvizConfigPath,
        description='Path to the RViz config file'
    )

    params = {'robot_description': robot_desc}

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable='robot_state_publisher',
        output='screen',
        parameters=[params]
    )
    

    joint_state_publisher_node = Node(
        package="joint_state_publisher",
        executable='joint_state_publisher',
        condition=IfCondition(PythonExpression(["'", LaunchConfiguration('use_jsp'), "' == 'jsp'"]))
    )


    joint_state_publisher_gui_node = Node(
        package="joint_state_publisher_gui",
        executable='joint_state_publisher_gui',
        output='screen',
        condition=IfCondition(PythonExpression(["'", LaunchConfiguration('use_jsp'), "' == 'gui'"]))
    )

    # RViz Node
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', LaunchConfiguration('rviz_config')],
        output='screen'
    )

    # Additional nodes
    turtle_robot_node = Node(
        package="turtle_brick",
        executable="turtle_robot",
        name="turtle_robot",
        output="screen",
        parameters=[{'config_path': configPath}]
    )

    arena_node = Node(
        package="turtle_brick",
        executable="arena",
        name="arena",
        output="screen",
        parameters=[{'config_path': configPath}]
    )

    catcher_node = Node(
        package="turtle_brick",
        executable="catcher",
        name="catcher",
        output="screen",
        parameters=[{'config_path': configPath}]
    )


    turtle_sim = Node(
        package="turtlesim",
        executable="turtlesim_node",
        name="sim",
        output="screen",
        parameters=[{
            'holonomic': True  # This sets the holonomic parameter to True
        }]
    )

    # Launch Description
    return LaunchDescription([
        jsp_arg,
        rviz_config_arg,
        robot_state_publisher_node,
        joint_state_publisher_node,
        joint_state_publisher_gui_node,
        rviz_node,
        turtle_robot_node,
        arena_node,
        turtle_sim,
        catcher_node
    ])
