#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "july_talker");
    ros::NodeHandle n;
    ros::Publisher july_pub = n.advertise<std_msgs::String>("/july_talk", 10);
    ros::Rate loop_rate(10);
	int count = 0;
	while (ros::ok())
	{
		std_msgs::String msg;
		std:stringstream ss;
		ss << "hello world " << count;
		count++;
		msg.data = ss.str();
		july_pub.publish(msg);
		loop_rate.sleep();
	}
    
    return 0;
}