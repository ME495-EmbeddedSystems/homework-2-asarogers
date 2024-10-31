cmake_minimum_required(VERSION 3.8)
project(turtle_brick_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
# Uncomment the following section in order to fill in further dependencies manually.
# find_package(<dependency> REQUIRED)

# Tell CMake what files to generate interface definitions for
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/ProvideGoalPose.srv"    # Service file
  "srv/Place.srv"
  "srv/StopGravity.srv"
  "msg/Tilt.msg"               # Message files
  "msg/TurtleLocation.msg"
  "msg/BrickLocation.msg"
  "msg/BrickDropped.msg"
  DEPENDENCIES geometry_msgs    # Dependency on geometry_msgs
)

# Export a dependency on rosidl_default_runtime
ament_export_dependencies(rosidl_default_runtime)

# Install directory for generated interfaces
install(
  DIRECTORY srv/
  DESTINATION share/${PROJECT_NAME}/srv
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # The following line skips the linter which checks for copyrights.
  # Comment the line when a copyright and license is added to all source files.
  set(ament_cmake_copyright_FOUND TRUE)
  # The following line skips cpplint (only works in a git repo).
  # Comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files.
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
