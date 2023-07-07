#include<ros/ros.h>
#include<sensor_msgs/LaserScan.h>
#include<geometry_msgs/Twist.h>
//catkin_create_pkg lidar_pkg roscpp rospy sensor_msgs
//rosrun wpr_simulation demo_lidar_data
ros::Publisher vel_pl;

void lidar_callback(sensor_msgs::LaserScan msg){
    printf("ABCD");
    float distance =  msg.ranges[180];
    ROS_INFO("distance:%f",distance);

    geometry_msgs::Twist vel_cmd;
    if(distance<1){
         printf("_____");
        vel_cmd.angular.z=0.5;
    }else{
         printf("++++++");
        vel_cmd.linear.x=0.1;
    }
    vel_pl.publish(vel_cmd);
    printf("\n");
}

int main(int argc, char *argv[])
{
    //setlocale(LC_ALL,"zh_CN_UTF-8");
    setlocale(LC_ALL,"");
    int i=0;
    ros::init(argc,argv,"lidar_node");
    //
    ros::NodeHandle nh;

    //带有＂／＂的是固定发布和订阅的标志号,如：/scan和 /cmd_vel
    ros::Subscriber ss =nh.subscribe("/scan",10,&lidar_callback);
    vel_pl=nh.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    ros::spin();

    // while (ros::ok())//
    // {
    //     ros::spinOnce();
    // }
    printf("====\n"); 
    return 0;
}