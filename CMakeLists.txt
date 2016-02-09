cmake_minimum_required(VERSION 2.8.3)
project(dotbot_app)

find_package(catkin REQUIRED COMPONENTS
  dotbot_msgs
  geometry_msgs
  roscpp
  rospy
  std_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(dotbot_app_node src/node.cpp)
add_dependencies(dotbot_app_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(dotbot_app_node
  ${catkin_LIBRARIES}
)
