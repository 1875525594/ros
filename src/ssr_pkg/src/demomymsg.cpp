#include<ros/ros.h>
#include<std_msgs/String.h>
#include"qq_msgs/Carry.h"

int main(int argc, char *argv[])
{
    int i=0;
    ros::init(argc,argv,"chao_node");
  
    ros::NodeHandle nh;
    ros::Publisher p= nh.advertise<qq_msgs::Carry>("aaaaa",10);
    
    ros::Rate rrr(1);
    qq_msgs::Carry msg;
   
    while (ros::ok())//
    {
         printf("====%d,\n",i);
         msg.grade="msgs--110--msgs";
         p.publish(msg);
         i++;
         rrr.sleep();
    }
    
    printf("====\n"); 
    return 0;
}
