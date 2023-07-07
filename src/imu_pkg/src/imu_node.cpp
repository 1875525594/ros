#include<ros/ros.h>
#include"sensor_msgs/Imu.h"
#include"tf/tf.h"
ros::Publisher vel_pub;

void imucallback(sensor_msgs::Imu msg){
    if(msg.orientation_covariance[0]<0){
        return;
    }
    tf::Quaternion q(
        msg.orientation.x,
        msg.orientation.y,
        msg.orientation.z,
        msg.orientation.w
    );

    double roll,pitch,yaw;
    tf::Matrix3x3(q).getRPY(roll,pitch,yaw);
    roll=roll*180/M_PI;
    pitch=pitch*180/M_PI;
    yaw=yaw*180/M_PI;
    ROS_INFO("Roll:%f,-,pitch:%f,-,yaw:%f\n,-,roll:%f",roll,pitch,yaw);
    double target_yaw=90;
    double diff_angle= target_yaw-yaw;
    geometry_msgs::Twist vel_cmd;
    vel_cmd.linear.z=diff_angle*0.1;
    vel_pub.publish(vel_cmd);
}

int main(int argc, char *argv[])
{
    int i=0;
    setlocale(LC_ALL,"zh_CN_UTF-8");
    ros::init(argc,argv,"imu_node");
  
    ros::NodeHandle nh;
    ros::Subscriber imu_sub = nh.subscribe("/imu/data",10,imucallback);
    vel_pub= nh.advertise<geometry_msgs::Twist>("/cmd_vel",10);

    ros::spin();
    // printf("====\n"); 
    return 0;
}
