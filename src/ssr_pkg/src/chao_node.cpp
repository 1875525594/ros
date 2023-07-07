#include<ros/ros.h>
#include<std_msgs/String.h>

int main(int argc, char *argv[])
{
    int i=0;
    ros::init(argc,argv,"chao_node");
  
    ros::NodeHandle nh;
    ros::Publisher p= nh.advertise<std_msgs::String>("qqwwee",10);
    
    ros::Rate rrr(1);
    std_msgs::String msg;
   
    while (ros::ok())//
    {
         printf("====%d,\n",i);
         msg.data="guoguoguoj";
         p.publish(msg);
         i++;
         rrr.sleep();
        /* code */
    }
    
    printf("====\n"); 
    return 0;
}
