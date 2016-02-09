#include "ros/ros.h"
#include "dotbot_msgs/Speed.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "speed_controller_node");

  ros::NodeHandle n;
  ros::Publisher speed_pub = n.advertise<dotbot_msgs::Speed>("/dotbot/speed", 1000);

  ros::Rate loop_rate(20);

  int count = 0;
  while (ros::ok())
  {
    dotbot_msgs::Speed msg;

    msg.sx = count%200-100;
    msg.dx = -(count%200-100);

    speed_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }
  return 0;
}
