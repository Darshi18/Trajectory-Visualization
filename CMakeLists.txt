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
find_package(tf2_geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate service interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/SaveTrajectory.srv"
  DEPENDENCIES std_msgs geometry_msgs nav_msgs
)

# Include directories
include_directories(include)

# Library for saver
add_library(trajectory_saver_lib
  src/trajectory_saver.cpp
)
ament_target_dependencies(trajectory_saver_lib
  rclcpp
  std_msgs
  nav_msgs
  geometry_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
  visualization_msgs
)
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(trajectory_saver_lib ${cpp_typesupport_target})

# Executable node for saver
add_executable(trajectory_saver_node src/main_saver.cpp)
target_link_libraries(trajectory_saver_node trajectory_saver_lib)

# Library for reader
add_library(trajectory_reader_lib
  src/trajectory_reader.cpp
)
ament_target_dependencies(trajectory_reader_lib
  rclcpp
  std_msgs
  nav_msgs
  geometry_msgs
  visualization_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
)

# Executable node for reader
add_executable(trajectory_reader_node src/main_reader.cpp)
target_link_libraries(trajectory_reader_node trajectory_reader_lib)

# Install targets
install(TARGETS
  trajectory_saver_node
  trajectory_reader_node
  trajectory_saver_lib
  trajectory_reader_lib
  DESTINATION lib/${PROJECT_NAME}
)

# Install headers
install(DIRECTORY include/
  DESTINATION include/
)

# Export interfaces and dependencies
ament_export_include_directories(include)
ament_export_dependencies(
  rclcpp
  std_msgs
  nav_msgs
  geometry_msgs
  visualization_msgs
  tf2
  tf2_ros
  rosidl_default_runtime
)

ament_package()
