#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc, char **argv) {

	ros::init(argc, argv, "g4gekkouga_numbers");

	ros::NodeHandle n;

	ros::Publisher topic_Numbers = n.advertise<std_msgs::Int64>("topic_numbers", 1000);

	ros::Rate loop_rate(1);

	int count = 0;
	
	while (ros::ok()) {	

		count++;
		
		std_msgs::Int64 msg;
		msg.data = count;

		topic_Numbers.publish(msg);

		ROS_INFO("Number Published %d", msg.data);

		loop_rate.sleep();
	}

	return 0;
}



