#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

int main(int argc, char *argv[])
{
    int i=0;
    ros::init(argc,argv,"vel_node");
  
    ros::NodeHandle nh;
    ros::Publisher p= nh.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    
    ros::Rate rrr(30);
    //roslaunch wpr_simulation wpb_simple.launch,
    //killall gzserver 
    //rosrun vel_pkg vel_node
    //rosrun lidar_pkg lidar_node
  
    geometry_msgs::Twist vel_msg;
    vel_msg.linear.x=0;
    vel_msg.linear.y=0;
    vel_msg.linear.z=0;
    vel_msg.angular.x=0;
    vel_msg.angular.y=0;
    vel_msg.angular.z=0.5;
   
    while (ros::ok())//
    {
         printf("====%d,\n",i);
         p.publish(vel_msg);
         i++;
         rrr.sleep();
    }
    
    printf("====\n"); 
    return 0;
}
