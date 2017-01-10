#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <iostream>

class SubAndPub {
public:
  SubAndPub() {
    pub = node.advertise<std_msgs::String>("logger", 1000);
    sub = node.subscribe("system_status", 1000, &SubAndPub::callback, this);
  }
  void callback(const std_msgs::String::ConstPtr& msg) {
    std::cout << "Msg received: " << msg->data << std::endl;
    std_msgs::String pub_msg;
    pub_msg.data = "Hello world";
    pub.publish(pub_msg);
    ros::spinOnce();
  }
private:
  ros::NodeHandle node;
  ros::Publisher pub;
  ros::Subscriber sub;
};

// void systemStatusMessageCallback(const std_msgs::String::ConstPtr& msg) {
//   ROS_INFO("Received Message: [%s]", msg ->data.c_str());
//   ros::NodeHandle rosNodeHandle;
//
//   /*ros::Publisher light_sensor_publisher =
//       rosNodeHandle.advertise<std_msgs::Int32>("light_sensor_data", 1000);
//   std_msgs::Int32 msg;
//   // send a meaningless test message for now
//   msg.data = 42;
//   light_sensor_publisher.publish("Hello world")*/
// }

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "system_ctl");
  ros::NodeHandle rosNodeHandle;
  SubAndPub spub;
  ros::spin();
  // ros::Subscriber system_status_subscriber =
  //   rosNodeHandle.subscribe("system_status", 1000, systemStatusMessageCallback);
  //
  // ros::Rate loop_rate(1);
  // while(ros::ok()) {
  //
  //   ros::spinOnce();
  //   loop_rate.sleep();
  // }
    return 0;
}
