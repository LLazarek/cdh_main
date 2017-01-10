#ifndef MESSAGE_PASS_H_
#define MESSAGE_PASS_H_

#include <memory>
#include "ros/ros.h"

class MessagePass {
private:
  std::shared_ptr<void> mData;
  ros::NodeHandle mNodeHandle;
  //void (*mCallBack)(void*&);
  void (&mCallBack)(const void*&);
public:
  MessagePass();
  ~MessagePass();
  std::shared_ptr<void> getData();
  std::shared_ptr<void> setData(std::shared_ptr<void> data);
  void* setCallBack(void (*callBack)(void*));
  void* getCallBack();
  ros::NodeHandle getNodeHandle();
  ros::NodeHandle setNodeHandle(ros::NodeHandle nodeHandle);
};
#endif  // MESSAGE_PASS_H_
