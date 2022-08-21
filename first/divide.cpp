#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"

std_msgs::Float32 result;
void chatterCallback(const std_msgs::Int32& msg)
{
  float number=0.0 ,res;
  
  number=(float)(msg.data);
  res=number/2;
  result.data=res;
  ROS_INFO("result: [%.2f]", result.data);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "divide");

  
  ros::NodeHandle nh;
  ros::NodeHandle n;
  
 
  
  ros::Subscriber sub = nh.subscribe("pub_int_num", 1000,chatterCallback);
  ros::Publisher divide_pub = n.advertise<std_msgs::Float32>("result", 50);

  ros::Rate loop_rate(5);
  while (ros::ok())
  {
   
   divide_pub.publish(result);

   ros::spin();
   loop_rate.sleep();
  }

  return 0;
}
