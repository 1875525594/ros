# ros
ros笔记

1,ros命令：

roscore

rosrun rqt_robot_steering rqt_robot_steering

roslaunch wpr_simulation wpb_simple.launch

catkin_create_pkg:创建软件包，格式：catkin_create_pkg 包名字　依赖项目列表　如：catkin_create_pkg　ssr_pkg rospy roscpp std_msgs

roscd:在终端中进入指定软件包的文件地址．如进入上面的依赖roscpp：roscd　roscpp．

rostopic list:查看消息列表．
![image](https://github.com/1875525594/ros/assets/109819399/2b3b6459-12a2-4a87-aac2-5adeb9912062)

 
rqt_graph：节点之间通讯关系图

![image-20230706174920002](/home/gdm0/snap/typora/82/.config/Typora/typora-user-images/image-20230706174920002.png)


2,cmake:
add_executable(${PROJECT_NAME}_node src/ssr_pkg_node.cpp)：格式：add_executable(执行节点名字（最后与节点名一致） 节点路径)：

##指定实现方法依赖，对于chao_node节点，
target_link_libraries(chao_node
  ${catkin_LIBRARIES}
)



3,ros方法：
ros::ok()　　响应外部（如终端）的各种中断．如：ctrl+c
![Uploading image.png…]()


消息发布与订阅

发布

​	ros::NodeHandle nh;

​    ros::Subscriber ss =nh.subscribe("qqwwee",10,chao_callback);

​    ros::Subscriber ssyao =nh.subscribe("yao",10,chao_callback2);

订阅

​	ros::NodeHandle nh;

​	ros::Subscriber ss =nh.subscribe("qqwwee",10,chao_callback);

​	ros::spinOnce();



打印：

printf(msg.data.c_str())与ROS_WARN(msg.data.c_str())，ROS_INFO(msg.data.c_str());没有多大区别．


功能包查看位置:
cd /opt/ros/noetic/share/



launch文件应用：
launch文件中param、rosparam以及arg之间的区别？
param与rosparam两个参数调用差不多，都是把launch文件中的一些参数直接设置到rosmaster（ros中的节点管理器）里面以便于各个节点的使用，主要不同在于param只对一个参数进行操作，
  使用方式如下：
  1，如：
    <param name="name"   value="ture"/>
    
  2，如：
  
    <launch>
        <arg name="xxx" />
        <param name="param" value="$(arg xxx)" />
    </launch>

    命令行调用：
    roslaunch hello.launch xxx:=值

rosparam可以对多个参数进行操作，前提时把这些参数放到.yaml文件中，使用方式如下：
 <rosparam file="param.yaml" command="load"/>


arg是把参数用在launch文件内部来使用，把launch文件看作是脚本的话，arg类似这个脚本里面设置变量的语法、语句，
 使用方式如下：
 
  ` <arg name="name"  default="value" />



这只是基本的使用方式，里面还可以添加其它的，比如ns（命名空间），也可以将arg嵌套param当中，
 如下：
 
 <rosparam file="$(find xpkg)param.yaml" command="load" ns="params"/>
 <param name="name"   value="$(arg xxx)"/>

 
