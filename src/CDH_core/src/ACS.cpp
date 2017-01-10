#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

#include <sstream>
void luminosityMessageCallback(const std_msgs::Int32::ConstPtr& msg) {
  ROS_INFO("Received Luminosity Value: [%d]", msg ->data);
}

void magnetometerMessageCallback(const std_msgs::Int32::ConstPtr& msg) {
  ROS_INFO("Received Magnetic Field Value: [%d]", msg ->data);
}

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "ACS");
  ros::NodeHandle rosNodeHandle;

  ros::Subscriber light_sensor_subscriber =
    rosNodeHandle.subscribe("light_sensor_data", 1000, luminosityMessageCallback);

  ros::Subscriber magnetometer_subscriber =
    rosNodeHandle.subscribe("magnetometer_data", 1000, magnetometerMessageCallback);


  ros::Publisher system_status_publisher =
    rosNodeHandle.advertise<std_msgs::String>("system_status", 1000);
  ros::Rate loop_rate(1);
  while(ros::ok()) {
    std_msgs::String msg;
    // send a meaningless test message for now
    msg.data = "Magnetorquers Rotated the Satellite";

    ROS_INFO("Sending system_status message: %s", msg.data.c_str());

    system_status_publisher.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
    return 0;
}
