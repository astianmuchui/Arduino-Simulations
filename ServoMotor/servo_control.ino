#include <Servo.h>
// Instantiate object
Servo servo; 
Servo servo_two;
int pos = 3;    
int pos_two = 10;


void setup() {
  // Set up pins for the motors
  // Almost the same as pinMode function
  servo.attach(3);  
  servo_two.attach(10);
}

void loop() {
  
  // Read potentiometer value 
  int val = analogRead(A0);

  // Map values since the motor might need 
  int mapped = map(val,0,1023,0,255);

  servo.write(mapped);
  servo_two.write(mapped);
}

