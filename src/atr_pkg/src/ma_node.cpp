#include<ros/ros.h>
#include<std_msgs/String.h>

void chao_callback(std_msgs::String msg){
    //ROS_INFO(msg.data.c_str());
    printf(msg.data.c_str());
    printf("\n");
}

void chao_callback2(std_msgs::String msg){
    printf("ABCD");
    ROS_WARN(msg.data.c_str());
    printf("\n");
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"zh_CN_UTF-8");
    int i=0;
    ros::init(argc,argv,"ma_node");
    //
    ros::NodeHandle nh;
    ros::Subscriber ss =nh.subscribe("qqwwee",10,chao_callback);
    ros::Subscriber ssyao =nh.subscribe("yao",10,chao_callback2);
    
    
    while (ros::ok())//
    {
        ros::spinOnce();
    }
    
    printf("====\n"); 
    return 0;
}
