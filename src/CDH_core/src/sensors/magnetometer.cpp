#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <sstream>
#include <iostream>
// will need to include all necessary sensor libraries

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "magnetometer");
  ros::NodeHandle rosNodeHandle;

  ros::Publisher magnetometer_publisher =
    rosNodeHandle.advertise<std_msgs::Int32>("magnetometer_data", 1000);
  ros::Rate loop_rate(2);
  while(ros::ok()) {
    std_msgs::Int32 msg;
    // send a meaningless test message for now
    msg.data = 16;

    ROS_INFO("Sending magnetic field value: %d", msg.data);

    magnetometer_publisher.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }

return 0;

}
