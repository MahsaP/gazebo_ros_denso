cmake_minimum_required(VERSION 2.8.3)
project(vs060_gazebo)

find_package(catkin REQUIRED COMPONENTS std_msgs roscpp)

catkin_package()

install(DIRECTORY config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY worlds
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
  
include_directories(include ${catkin_INCLUDE_DIRS})
add_executable(poseCommand src/poseCommand.cpp)
target_link_libraries(poseCommand ${catkin_LIBRARIES})
