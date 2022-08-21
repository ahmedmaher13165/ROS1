#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <sstream>


int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "pub_int_num");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("pub_int_num", 50);
  ros::Rate loop_rate(5);
int count = 0;
  while (ros::ok())
  {
  
    std_msgs::Int32 msg;
    
   int num=20;
    
for(num;num<=100;num++)
{   
    msg.data = num;
    ROS_INFO("%i", msg.data);
    chatter_pub.publish(msg);  
}   
 

    ros::spinOnce();

    loop_rate.sleep();
++count;
 }

  return 0;
}