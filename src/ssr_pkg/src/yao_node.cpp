#include<ros/ros.h>
#include<std_msgs/String.h>
#include"qq_msgs/Carry.h"

int main(int argc, char *argv[])
{
    int i=0;
    ros::init(argc,argv,"yao_node");
  
    ros::NodeHandle nh;
    //ros::Publisher p= nh.advertise<std_msgs::String>("yao",10);
    ros::Publisher p= nh.advertise<qq_msgs::Carry>("yao",10);
    
    ros::Rate rrr(1);
    //std_msgs::String msg;
    qq_msgs::Carry msg;
   
    while (ros::ok())//
    {
         printf("====%d,\n",i);
         msg.data="yaoaaaaaaaaa";
         p.publish(msg);
         i++;
         rrr.sleep();
    }
    
    printf("====\n"); 
    return 0;
}
