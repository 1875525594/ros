/*
    注意命名空间的使用。
    修改参数服务器中turtlesim的颜色.

*/
#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "color");

    // 注意服务器/话题节点的名称，可以使用rosservice list或者rostopic list查看
    ros::NodeHandle nh("turtlel0");
    // ros::NodeHandle nh;

    // ros::param::set("/turtlesim/background_r",0);
    // ros::param::set("/turtlesim/background_g",0);
    // ros::param::set("/turtlesim/background_b",0);

    nh.setParam("background_r", 0);
    nh.setParam("background_g", 0);
    nh.setParam("background_b", 0);

    return 0;
}
