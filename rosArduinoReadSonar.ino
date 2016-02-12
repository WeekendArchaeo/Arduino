/*
 * Gets measurements from the ultrasonic sensor HC-SR04 and publishes them in a topic.
 * 
 * Based on UltrasonicDemo.pde - Ultrasonic sensor Ranging measure Demo
 * @Author:dragon
 * @DATA:2013-8-7
 * Company website:www.elecfreaks.com
 *
 * Based on http://wiki.ros.org/rosserial_arduino/Tutorials/Hello%20World
 *
 * Ana Cruz Martin, 2016
 */
 
#include <ros.h>
#include <Ultrasonic.h>
#include <std_msgs/Float32.h>


ros::NodeHandle nh;

std_msgs::Float32 distance;    // measured distance (cm.)
long microsec;     // measured time
int trigpin = 2;   // trigger pin
int echopin = 3;   // echo pin

ros::Publisher sonar_reader("sonar_topic", &distance);
Ultrasonic ultrasonic(trigpin,echopin);

void setup()
{
  Serial.begin(9600); 
  nh.initNode();
  nh.advertise(sonar_reader);
}

void loop()
{
  microsec = ultrasonic.timing();
  distance.data = ultrasonic.CalcDistance(microsec,Ultrasonic::CM);
  sonar_reader.publish(&distance);
  nh.spinOnce();
  delay(1000);
}
