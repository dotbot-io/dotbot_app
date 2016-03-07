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

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(EXISTS ${curdir}/${child}/.dotbot_ros)
        LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

MESSAGE(STATUS "current dir     " ${CMAKE_CURRENT_SOURCE_DIR})
SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
FOREACH(subdir ${SUBDIRS})
  MESSAGE(STATUS "Found Executable dotbot     " ${subdir}_dotbot_app_node)

  add_executable(${subdir}_dotbot_app_node ${subdir}/node.cpp)
  add_dependencies(${subdir}_dotbot_app_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
  target_link_libraries(${subdir}_dotbot_app_node ${catkin_LIBRARIES})
ENDFOREACH()
