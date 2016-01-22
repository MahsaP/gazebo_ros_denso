#include <ros/ros.h>        
#include <std_msgs/Float64.h>

#define Num_Joint 6

using namespace std;

class SetPoseRobot{
public:
    SetPoseRobot();
    void setInitialJointPositions(double initial_positions, int i);
    void getInputs(double initial_pose[]);
    
private:  
    ros::NodeHandle ph_;
    ros::Publisher joint_pub_[6];
};
SetPoseRobot::SetPoseRobot()
{
    for(int k=0;k<6;k++)
    {
        std::stringstream pub_topic;
        pub_topic << "/vs060/joint" << k+1 << "_position_controller/command";
        joint_pub_[k]=ph_.advertise<std_msgs::Float64>(pub_topic.str().c_str(),10);
    }
}
void SetPoseRobot::getInputs(double initial_pose[])
{
    double a;
    cout << "Enter joints pose in radian: " << endl;
    for(int i=0;i<Num_Joint;i++){
	while (cout << "joint["<<i<<"]=" && !(cin >> a))
	{
	    cout << "That's not a valid input. Try again" << endl;
	    cin.clear(); // Reset fail bit
	    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //reset bad input flag
	    // Next request the user to reinput
        }
        initial_pose[i]=a;         
    }
    printf("\n***********");
    for(int i=0;i<6;i++){
        printf("\njoint[%d]=%f",i,initial_pose[i]);
    }
    printf("\n***********\n");  
}
void SetPoseRobot::setInitialJointPositions(double initial_positions, int i)
{    
        std_msgs::Float64 msg;
        msg.data=initial_positions;
        joint_pub_[i].publish(msg);
}   
int main(int argc, char** argv)
{
    ros::init(argc, argv, "Initial_Pose_Robot");
    SetPoseRobot d;
    double initial_pose[Num_Joint];
    d.getInputs(initial_pose);
    
    ros::Rate loop_rate(10); 
    
    while(ros::ok())
    {
       for(int i=0;i<6;i++){
           d.setInitialJointPositions(initial_pose[i],i);
       }
       loop_rate.sleep();
    }
    ros::spin();
    return(0);
}
