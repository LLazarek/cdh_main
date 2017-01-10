#include "../include/CDH_core/MessagePass.h"
#include <memory>
#include "ros/ros.h"

MessagePass::MessagePass() {
  mData = NULL;
  mCallBack = NULL;
  mNodeHandle = NULL;
}

MessagePass::~MessagePass() {

}

std::shared_ptr<void> MessagePass::getData() {
  return mData;
}

ros::NodeHandle MessagePass::getNodeHandle() {
  return mNodeHandle;
}


std::shared_ptr<void> MessagePass::setData(std::shared_ptr<void> data) {
  mData = data;
}
  void* MessagePass::setCallBack(void (*callBack)(void*)); {
  mCallBack = callback;
}
void* MessagePass::getCallBack() {
  return mCallBack;
}

ros::NodeHandle setNodeHandle(ros::NodeHandle nodeHandle) {
  mNodeHandle = nodeHandle;
}
