#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <iostream>
#include <memory>

#include "../include/CDH_core/MessagePass.h"



void systemStatusMessageCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("Received Message: [%s]", msg ->data.c_str());

}

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "system_ctl");
  ros::NodeHandle rosNodeHandle;

  MessagePass systemStatusMessagePass;
  systemStatusMessagePass.setNodeHandle(rosNodeHandle);
  systemStatusMessagePass.setCallBack(systemStatusMessageCallback);

  ros::Subscriber system_status_subscriber =
    rosNodeHandle.subscribe("system_status", 1000, systemStatusMessageCallback);

  ros::Rate loop_rate(1);
  while(ros::ok()) {

    ros::spinOnce();
    loop_rate.sleep();
  }
    return 0;
}
