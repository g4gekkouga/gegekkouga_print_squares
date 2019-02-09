#include "ros/ros.h"
#include "std_msgs/Int64.h"

ros::Publisher topic_Squares;

void squareCalc(const std_msgs::Int64::ConstPtr& msgr) {
    
	ROS_INFO("Number Received : %d \n", msgr->data);
    
    std_msgs::Int64 msgp;
    msgp.data = (msgr->data)*(msgr->data);
   
	topic_Squares.publish(msgp);

    ROS_INFO("Number Published : %d \n", msgp.data);
     
   }

 int main(int argc, char **argv) {
 
 	ros::init(argc, argv, "g4gekkouga_squares");
   
    ros::NodeHandle n;
  
    topic_Squares = n.advertise<std_msgs::Int64>("topic_squares", 1000);

    ros::Subscriber topic_Numbers = n.subscribe<std_msgs::Int64>("topic_numbers", 1000, squareCalc);
  
    ros::spin();
  
    return 0;
}
