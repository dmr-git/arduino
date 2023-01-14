/* Drive a servo motor.  Refer to 'Exploring Arduino' by Jeremy Blum, Chapter 4. 
   Put the servo on a seperate 5V power supply.

#include <Servo.h>
#define SERVO 9
#define POT 0

Servo myServo;
int val = 0;  // for storing the reading from the POT

void setup() {
  myServo.attach(SERVO);
}

void loop() {
  val = analogRead(POT);
  val = map(val, 0, 1013, 0, 179);  // scale the reading to servo range
  myServo.write(val);
  delay(15);
}
