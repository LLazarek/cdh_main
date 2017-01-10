#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <sstream>
#include <iostream>
// will need to include all necessary sensor libraries

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "light_sensors");
  ros::NodeHandle rosNodeHandle;

  ros::Publisher light_sensor_publisher =
    rosNodeHandle.advertise<std_msgs::Int32>("light_sensor_data", 1000);
  ros::Rate loop_rate(2);
  while(ros::ok()) {
    std_msgs::Int32 msg;
    // send a meaningless test message for now
    msg.data = 42;

    ROS_INFO("Sending luminosity value: %d", msg.data);

    light_sensor_publisher.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }

return 0;

}
