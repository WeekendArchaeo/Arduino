/*--------------------------------------------------------------
 * This sketch gets the readings of an analog pin and publishes
 * them to a topic.
 * 
 * It is based on the rosserial Publisher Example
 * http://wiki.ros.org/rosserial_arduino/Tutorials/Hello%20World
 *
 * Ana Cruz-Martin 2015
 *-------------------------------------------------------------*/

#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle nh;

std_msgs::Int16 int_msg;
ros::Publisher chatter("chatter",&int_msg);
int analogPin = 0;

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  int_msg.data = analogRead(analogPin);
  chatter.publish(&int_msg);
  nh.spinOnce();
  delay(100);
}
