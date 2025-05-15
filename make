cmake_minimum_required(VERSION 3.8)
project(trajectory_tools)

# Required dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(rosidl_default_generators REQUIRED)

## Service definition
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/SaveTrajectory.srv"
  DEPENDENCIES std_msgs
)

# Include directories
include_directories(include)

# Executable nodes
add_executable(trajectory_saver_node src/trajectory_saver.cpp)
ament_target_dependencies(trajectory_saver_node
  rclcpp
  std_msgs
  geometry_msgs
  nav_msgs
  visualization_msgs
  tf2
  tf2_ros
)

add_executable(trajectory_reader_node src/trajectory_reader.cpp)
ament_target_dependencies(trajectory_reader_node
  rclcpp
  std_msgs
  geometry_msgs
  nav_msgs
  visualization_msgs
  tf2
  tf2_ros
)

# Link service generation
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(trajectory_saver_node ${cpp_typesupport_target})
target_link_libraries(trajectory_reader_node ${cpp_typesupport_target})

install(TARGETS
  trajectory_saver_node
  trajectory_reader_node
  DESTINATION lib/${PROJECT_NAME}
)

# Export package
ament_export_dependencies(rosidl_default_runtime)
ament_package()

