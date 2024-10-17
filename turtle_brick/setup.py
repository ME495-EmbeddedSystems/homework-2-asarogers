from setuptools import find_packages, setup

package_name = 'turtle_brick'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml', 'launch/display.launch.py', 'urdf/my_robot.urdf', 'config/my_robot_config.rviz']),
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
            'baselinkToRobot = turtle_brick.baselinkToRobot:main',
            'worldFrameToBaseFootprint = turtle_brick.worldFrameToBaseFootprint:main'
        ],
    },
)
