# gazebo_ros_denso
A Denso package in Gazebo and Rviz.

##Introduction
The aim of this package is to provide a simulated environment for **Visual Servoing** purpose. As you run the code, you will see a camera attached to the the robot end-effector (flange).

##Dependencies
Please make sure that all the dependencies are up to date

`sudo apt-get update`

Install ros_control from debian packages 

`sudo apt-get install ros-indigo-ros-control ros-indigo-ros-controllers`

## How to run it on Rviz
`roslaunch denso_description denso_rviz.launch`

## How to run it on Gazebo
1) Launch the robot into gazebo.

`roslaunch vs060_gazebo vs060_gazebo.launch`

2) If you want to command the robot and see the performance, you can run the following line

`roslaunch vs060_gazebo vs060_rqt.launch`

## How to run it on Rviz
If you want to see the image of the camera, open a new terminal and run the following

`rosrun image_view image_view image:=/vs060/camera/image_raw`
