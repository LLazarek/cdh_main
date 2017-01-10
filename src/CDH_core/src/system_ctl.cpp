#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <iostream>
#include <memory>

//#include "../include/CDH_core/MessagePass.h"

//ros::NodeHandle rosNodeHandleGlobal;
/*
to get this to work, needs a class to pass NodeHandle around

*/

void system_statusMessageCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("Received Message: [%s]", msg ->data.c_str());

/*
  ros::Publisher logging_publisher =
    rosNodeHandleGlobal.advertise<std_msgs::String>("logging", 1000);
  // log what was sent from ACS

  std::cout<<"Sending recieved message to log..."<<std::endl;

  logging_publisher.publish(msg);
  */
}

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "system_ctl");
  ros::NodeHandle rosNodeHandle;

  //MessagePass systemStatusMessagePass();
//  rosNodeHandleGlobal = rosNodeHandle;

  ros::Subscriber system_status_subscriber =
    rosNodeHandle.subscribe("system_status", 1000, system_statusMessageCallback);

  ros::Rate loop_rate(1);
  while(ros::ok()) {

    ros::spinOnce();
    loop_rate.sleep();
  }
    return 0;
}
