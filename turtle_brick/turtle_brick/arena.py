import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster
import tf_transformations
from visualization_msgs.msg import Marker
from geometry_msgs.msg import Point, Quaternion
import math

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

    """

    def __init__(self):
        """Creates Arena node """
        super().__init__('arena')
        self.frequency = 0.01
        self.referenceFrame = "world"
        #             X     Y    Z
        self.scale =[0.25, 10.25, 2.5]
        self.rgba = [0.0, 0.0, 0.0, 1.0]
        self.zPose = 1.0

        # Create a TransformBroadcaster
        self.tf_broadcaster = TransformBroadcaster(self)
        self.markerPublisher = self.create_publisher(Marker, "visualization_marker", 4)
        self.timer = self.create_timer(self.frequency, self.publishMarker)
        self.timer2 = self.create_timer(self.frequency, self.publishMarker2)

    def publishMarker(self):
        """Publishes two wall along the x-axis"""
        self.GenerateWall([-5.0, 0.0,0.0], [5.0, 0.0, 0.0], "x_wall", 0)

    def publishMarker2(self):
        """Publishes two walls along the y-axis"""
        self.GenerateWall([-5.0, 0.0,0.0], [5.0, 0.0, 0.0], "y_wall", 1)

    def GenerateWall(self, firstWallPositon, secondWallPosition, referenceFrame, id):
        """
        Creates and publishes a wall market given the two endpoints

        Parameters
        ----------
        firstWallPosition : list - starting point [x, y, z] for the wall.
        secondWallPosition : list - ending point [x, y, z] for the wall.
        referenceFrame : str - reference frame for the marker (e.g., "x_wall" or "y_wall").
        id : int - unique identifier for each wall marker.
        """
        marker = Marker()
        marker.header.frame_id = self.referenceFrame
        marker.header.stamp = self.get_clock().now().to_msg()

        angle = math.radians(48 * id)
        marker.pose.orientation = self.create_quaternion_from_yaw(angle)
        marker.pose.position.z = self.zPose

        marker.ns= referenceFrame
        marker.id = id
        marker.type = Marker.CUBE_LIST
        marker.action = Marker.ADD

        marker.lifetime.sec = 0
        marker.lifetime.nanosec = 0

        cube_positions = [
            Point(x = firstWallPositon[0], y = firstWallPositon[1], z = firstWallPositon[2]),
            Point(x = secondWallPosition[0], y = secondWallPosition[1], z = secondWallPosition[2])
        ]

        marker.scale.x = self.scale[0]
        marker.scale.y = self.scale[1]
        marker.scale.z = self.scale[2]
        marker.points.extend(cube_positions)

        marker.color.r = self.rgba[0]
        marker.color.g = self.rgba[1]
        marker.color.b = self.rgba[2]
        marker.color.a = self.rgba[3]

        self.markerPublisher.publish(marker)
    
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
        q = Quaternion()
        q.x = 0.0
        q.y = 0.0
        q.z = yaw 
        return q

def main(args=None):
    rclpy.init(args=args)
    node = Arena()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
