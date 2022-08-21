#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"

float number ;
void chatterCallback(const std_msgs::Int32& msg)
{
  
  
  number=(float)(msg.data);
  
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

  std_msgs::Float32 result;
  float res;
  res=number/2;
  result.data=res;
  ROS_INFO("result: [%.2f]", result.data);
  divide_pub.publish(result);

   ros::spin();
   loop_rate.sleep();
  }

  return 0;
}
