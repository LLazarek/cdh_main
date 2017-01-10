#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

void logMessageCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("Received Message: [%s]", msg ->data.c_str());
}

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "logger");
  ros::NodeHandle rosNodeHandle;

  ros::Subscriber light_sensor_subscriber =
    rosNodeHandle.subscribe("logging", 1000, logMessageCallback);

  ros::spin();
    return 0;
}
