#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <sstream>


int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "pub_int_num");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("pub_int_num", 50);
  ros::Rate loop_rate(10);
<<<<<<< HEAD
 int num=20;
  while (ros::ok() && num<=100)
  {
  
    std_msgs::Int32 msg;
    
  
    
//for(num;num<=100;num++)
//{   
    msg.data = num;
    ROS_INFO("%i", msg.data);
    chatter_pub.publish(msg); 
   
//}   
 
num++;
    ros::spinOnce();

    loop_rate.sleep();

 }
=======

 

    std_msgs::Int32 msg;
    chatter_pub.publish(msg);
   int num=20;
    
for(num;num<=100;num++)
{
    msg.data = num;
    ROS_INFO("%i", msg.data);
    
}   
   

    ros::spinOnce();

    loop_rate.sleep();
 
>>>>>>> bd220d2fbfc63381af80c30541a4858afcfe28ac

  return 0;
}
