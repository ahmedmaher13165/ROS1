#include "ros/ros.h"
#include "first/person_data.h"

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "pub_person_data");
  ros::NodeHandle n;
  ros::Publisher pub_person = n.advertise<first::person_data>("pub_person_data", 50);
  ros::Rate loop_rate(10);
 
  while (ros::ok())
  {
    first::person_data person_data;

    person_data.name="ahmed maher";
    person_data.age=22;
    person_data.color="blue";
    pub_person.publish(person_data);

  
    ros::spinOnce();

    loop_rate.sleep();

 }

  return 0;
}
