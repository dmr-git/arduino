/*
Code to run a motor hooked up to pin 6 via a transistor.  Can hook up 9V battery to the barrel connector
on the Arduino, and then run a pass through of the 9V to the breadboard from the VIN pin.
Parts needed are: 1K resistor; motor, 0.1uF capacitor, 1N4001 diode, and PN2222 NPN bipolar junction transistor (BJT)
*/

const int MOTOR = 6;

void setup() {
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(MOTOR, i);
    delay(10);
  }
  delay(2000);
  for (int i = 255; i >= 0; i--) {
    analogWrite(MOTOR, i);
    delay(10);
  }
  delay(4000);
}
