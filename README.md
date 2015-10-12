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

![v060-rviz](https://cloud.githubusercontent.com/assets/12606874/10432637/4dcf4b44-7119-11e5-834f-582ff2cda70a.png)

## How to run it on Gazebo
1) Launch the robot into gazebo.

`roslaunch vs060_gazebo vs060_gazebo.launch`

![first_view](https://cloud.githubusercontent.com/assets/12606874/10413387/e0b8f2dc-6fb3-11e5-885c-e73ce78b07fb.png)

2) If you want to command the robot and see the performance, you can run the following line

`roslaunch vs060_gazebo vs060_rqt.launch`

You can command each joint seperately. Simply mark the joint on the right-side of the following figure. To see the changes of the signals you can change the tabe according to the joint number from the below sidbar, as the highlighed circle shows.
![rqt](https://cloud.githubusercontent.com/assets/12606874/10413389/eac86604-6fb3-11e5-9966-1c2eabebc263.png)
By selecting all the commands from the right-side of the previous picture (where all joints are commanded to 1 rad), you will see the following picture.
![settingcommands](https://cloud.githubusercontent.com/assets/12606874/10413390/f0bf67c4-6fb3-11e5-8daa-acc9bc80c174.png)

## How to see the camera window
If you want to see the image of the camera, open a new terminal and run the following

`rosrun image_view image_view image:=/vs060/camera/image_raw`

![camera-view](https://cloud.githubusercontent.com/assets/12606874/10413393/f619bdb4-6fb3-11e5-9960-db0924781790.png)
