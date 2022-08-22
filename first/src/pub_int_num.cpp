#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <sstream>


int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "pub_int_num");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("pub_int_num", 50);
  ros::Rate loop_rate(5);

  while (ros::ok() && num<=99)
  {
  
    std_msgs::Int32 msg;
    
   int num=20;
    
for(num;num<=100;num++)
{   
    msg.data = num;
    ROS_INFO("%i", msg.data);
    chatter_pub.publish(msg); 
    sleep(1) ;
}   
 

    ros::spinOnce();

    loop_rate.sleep();

 }
num=100;
  return 0;
}