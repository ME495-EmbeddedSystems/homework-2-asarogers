cmake_minimum_required(VERSION 3.8)
project(turtle_brick_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# Tell Cmake what files to generate interface definitions for
rosidl_generate_interfaces(${PROJECT_NAME}
    #  "msg/MessageType.msg" # Whatever message file you've defined
     "srv/ProvideGoalPose.srv" # Whatever service file you've defined
     DEPENDENCIES geometry_msgs  # in this example we depend on geometry_msgs
     )
# Export a dependency on the ros_idl_runtime
ament_export_dependencies(rosidl_default_runtime)

# Install directory for generated interfaces
install(
  DIRECTORY srv/
  DESTINATION share/${PROJECT_NAME}/srv
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
