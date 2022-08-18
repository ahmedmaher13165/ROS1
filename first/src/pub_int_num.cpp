#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <sstream>


int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "pub_int_num");

 
  ros::NodeHandle n;

  
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("pub_int_num", 50);

  ros::Rate loop_rate(10);

 
  int count = 0;
  while (ros::ok())
  { 
    
    std_msgs::Int32 msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}