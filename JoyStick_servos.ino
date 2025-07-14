#include <Servo.h>  
Servo servoX, servoY;  // X/Y axis servos  

void setup() {  
  servoX.attach(9);   // X-axis servo on D9  
  servoY.attach(10);  // Y-axis servo on D10  
}  

void loop() {  
  int xValue = analogRead(A0);  // Read X-axis (0-1023)  
  int yValue = analogRead(A1);  // Read Y-axis (0-1023)  

  // Map analog input to servo angles (0-180°)  
  int servoXAngle = map(xValue, 0, 1023, 0, 180);  
  int servoYAngle = map(yValue, 0, 1023, 0, 180);  

  servoX.write(servoXAngle);  
  servoY.write(servoYAngle);  

  delay(20); 
}  