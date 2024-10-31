"""
Setup configuration for the `turtle_brick` ROS2 package.

This script configures the installation, dependencies, and entry points for the
`turtle_brick` package, which provides simulation and control tools for 
a turtle robot in a ROS2 environment.

Package Contents
----------------
- name : str
    The name of the package.
- version : str
    The current version of the package.
- packages : list
    A list of packages to include, excluding the `test` directory.
- data_files : list
    Specifies data files to be installed, including package resources,
      launch files,
    URDF files, and configuration files for the robot and RViz.
- install_requires : list
    A list of dependencies required to install the package.
- zip_safe : bool
    Indicates whether the package can be used in zipped form.
- maintainer : str
    The name of the maintainer.
- maintainer_email : str
    Contact email for the maintainer.
- description : str
    A brief description of the package.
- license : str
    License declaration for the package.
- tests_require : list
    Specifies dependencies required for testing.
- entry_points : dict
    Defines command-line entry points for ROS2 nodes in the package.

Entry Points
------------
The following entry points are provided to launch nodes for
different components of the `turtle_brick` package:
- turtle_robot : Launches the `turtle_robot` node from 
`turtle_brick.turtle_robot`.
- arena : Launches the `arena` node from `turtle_brick.arena`.
- catcher : Launches the `catcher` node from `turtle_brick.catcher`.

This setup configuration supports installation with `colcon` 
in a ROS2 workspace
and defines the required dependencies, data files, and entry 
points for easy use.
"""


from setuptools import find_packages, setup

package_name = 'turtle_brick'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        (
            'share/' + package_name,
            [
                'package.xml',
                'launch/show_turtle.launch.py',
                'urdf/turtle.urdf.xacro',
                'config/my_robot_config.rviz',
                'config/turtle.yaml',
            ],
        ),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='asaace00',
    maintainer_email='cyberasasoftware@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'turtle_robot = turtle_brick.turtle_robot:main',
            'arena = turtle_brick.arena:main',
            'catcher = turtle_brick.catcher:main',
        ],
    },
)
