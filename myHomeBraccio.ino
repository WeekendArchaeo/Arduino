/*
  myHomeBraccio.ino
  
  This sketch runs Braccio.begin() in the setup function.
  After that, the sketch moves every joint of the Braccio along its whole range of movement.
  
  Based on testBraccio90.ino by Andrea Martino.
  
  Created on 07 November 2018 by Ana Cruz Martin

 */

#include <Braccio.h>
#include <Servo.h>

#define MINDEGBASE 0
#define MAXDEGBASE 180
#define MINDEGSHOULDER 15
#define MAXDEGSHOULDER 165
#define MINDEGELBOW 0
#define MAXDEGELBOW 180
#define MINDEGWRIST_V 0
#define MAXDEGWRIST_V 180
#define MINDEGWRIST_R 0
#define MAXDEGWRIST_R 180
#define MINDEGGRIPPER 10
#define MAXDEGGRIPPER 73

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

void setup() {  
  Serial.begin(9600);
  //Initialization functions and set up the initial position for Braccio
  //All the servo motors will be positioned in the "safety" position:
  //Base (M1):90 degrees
  //Shoulder (M2): 45 degrees
  //Elbow (M3): 180 degrees
  //Wrist vertical (M4): 180 degrees
  //Wrist rotation (M5): 90 degrees
  //gripper (M6): 10 degrees
  Braccio.begin();
}

void loop() {
  /*
   Step Delay: a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
   M1=base degrees. Allowed values from 0 to 180 degrees
   M2=shoulder degrees. Allowed values from 15 to 165 degrees
   M3=elbow degrees. Allowed values from 0 to 180 degrees
   M4=wrist vertical degrees. Allowed values from 0 to 180 degrees
   M5=wrist rotation degrees. Allowed values from 0 to 180 degrees
   M6=gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.
  */
  
  // the arm is aligned upwards  and the gripper is closed
  //(step delay, M1, M2, M3, M4, M5, M6);
  
  int degrees;
    
  Serial.println("Arm aligned upwards, gripper closed");
  Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 73);
  delay(1000);
  
  Serial.println("Base movement (0-180 degrees)");
  degrees = MINDEGBASE;
  while(degrees <= MAXDEGBASE)
  {
    Braccio.ServoMovement(20, degrees, 90, 90, 90, 90, 73);
    degrees=degrees+1;
  }
  Serial.println("Arm aligned upwards, gripper closed");
  Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 73);
  delay(1000);

  Serial.println("Shoulder movement (15-165 degrees)");
  degrees = MINDEGSHOULDER;
  while(degrees <= MAXDEGSHOULDER)
  {
    Braccio.ServoMovement(20, 90, degrees, 90, 90, 90, 73);
    degrees=degrees+1;
  }
  Serial.println("Arm aligned upwards, gripper closed");
  Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 73);
  delay(1000);

  Serial.println("Elbow movement (0-180 degrees)");
  degrees = MINDEGELBOW;
  while(degrees <= MAXDEGELBOW)
  {
    Braccio.ServoMovement(20, 90, 90, degrees, 90, 90, 73);
    degrees=degrees+1;
  }
  Serial.println("Arm aligned upwards, gripper closed");
  Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 73);
  delay(1000);

  Serial.println("Wrist vertical movement (0-180 degrees)");
  degrees = MINDEGWRIST_V;
  while(degrees <= MAXDEGWRIST_V)
  {
    Braccio.ServoMovement(20, 90, 90, 90, degrees, 90, 73);
    degrees=degrees+1;
  }
  Serial.println("Arm aligned upwards, gripper closed");
  Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 73);
  delay(1000);

  Serial.println("Wrist rotation movement (0-180 degrees)");
  degrees = MINDEGWRIST_R;
  while(degrees <= MAXDEGWRIST_R)
  {
    Braccio.ServoMovement(20, 90, 90, 90, 90, degrees, 73);
    degrees=degrees+1;
  }
  Serial.println("Arm aligned upwards, gripper closed");
  Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 73);
  delay(1000);

  Serial.println("Gripper movement (10-73 degrees)");
  degrees = MINDEGGRIPPER;
  while(degrees <= MAXDEGGRIPPER)
  {
    Braccio.ServoMovement(20, 90, 90, 90, 90, 90, degrees);
    degrees=degrees+1;
  }
  Serial.println("Arm aligned upwards, gripper closed");
  Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 73);
  delay(1000);
}
