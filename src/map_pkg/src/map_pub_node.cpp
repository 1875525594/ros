#include<ros/ros.h>

#include<nav_msgs/OccupancyGrid.h>

// rosrun map_pkg map_pub_node
// rviz
int main(int argc, char *argv[])

{

   //setlocale(LC_ALL,"zh_CN_UTF-8");

   // setlocale(LC_ALL,"");

   int i=0;

   ros::init(argc,argv,"map_pub_node");

    //
    ros::NodeHandle nh;
    ros::Publisher pub=nh.advertise<nav_msgs::OccupancyGrid>("/map",10);
    ros::Rate r(4);
    nav_msgs::OccupancyGrid msg;
   while (ros::ok()){ 
      msg.header.frame_id="map";
      // 地图描述信息
      msg.info.origin.position.x=0;
      msg.info.origin.position.y=0;
      msg.info.width=4;
      msg.info.height=2;
      // 地图数据
      msg.data.resize(4*2);
      msg.data[0]=100;
      msg.data[1]=100;
      msg.data[2]=0;
      msg.data[3]=-1;

      pub.publish(msg);
      printf("====%d,\n",i);
      i++;
      r.sleep();
  }
  printf("====\n"); 

 return 0;
}