#ifndef NODELET_BASE_H
#define NODELET_BASE_H

// ros
#include <ros/ros.h>
#include <nodelet/nodelet.h>

#include <std_msgs/String.h>

namespace nodelet_base
{
    class NodeletBase : public nodelet::Nodelet
    {
    public:
        NodeletBase();
        ~NodeletBase();
        virtual void onInit();

    private:
        ros::Publisher  _pub;
        ros::Subscriber _sub;
        ros::Timer      _timer;

        void callbackMsg(const std_msgs::StringConstPtr msg);
        void callbackTimer(const ros::TimerEvent &event);
    };
}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(nodelet_base::NodeletBase, nodelet::Nodelet);

#endif// NODELET_BASE_H
