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


2,cmake:
add_executable(${PROJECT_NAME}_node src/ssr_pkg_node.cpp)：格式：add_executable(执行节点名字（最后与节点名一致） 节点路径)：

##指定实现方法依赖，对于chao_node节点，
target_link_libraries(chao_node
  ${catkin_LIBRARIES}
)

3,ros方法：
ros::ok()　　响应外部（如终端）的各种中断．如：ctrl+c
![Uploading image.png…]()

