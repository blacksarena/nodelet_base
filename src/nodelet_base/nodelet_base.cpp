#include "nodelet_base.h"

using namespace nodelet_base;

NodeletBase::NodeletBase()
{
    NODELET_INFO("constructor");
}

NodeletBase::~NodeletBase()
{
    NODELET_INFO("destructor");
}

void NodeletBase::onInit()
{
    NODELET_INFO("init");

    // get nodehandle
    ros::NodeHandle nh = ros::NodeHandle();

    // create publisher
    _pub = nh.advertise<std_msgs::String>("chatter", 1000);

    // create subscriber
    _sub = nh.subscribe("chatter", 1000, &NodeletBase::callbackMsg, this);

    // create timer
    _timer = nh.createTimer(ros::Duration(1.0), &NodeletBase::callbackTimer, this);
}

void NodeletBase::callbackMsg(const std_msgs::StringConstPtr msg)
{
    // Be sure to use a const-pointer for the argument of nodelet's message callback function.
    NODELET_INFO("receive: [%s]", msg->data.c_str());
}

void NodeletBase::callbackTimer(const ros::TimerEvent &event)
{
    std_msgs::String msg;
    msg.data = "hello world!";
    _pub.publish(msg);
}
