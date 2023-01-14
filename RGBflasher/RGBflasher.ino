/*
Flash through RGB colors on a common anode multi-color LED.  This LED has all the positive leads connected
to one pin. From the flat side of the LED, the leads are red(cathode), common anode(+), green(cathode),
and blue(cathode). The common anode is the longest lead.
Use a 220 ohm resistor from each cathode to the Arduino.
In this example we set the Arduino pins to low to allow current to flow back into the Arduino.
*/
const int redLed = 9;
const int grnLed = 10;
const int bluLed = 11;

void setup() {
  // define the pins as outputs
  pinMode(redLed, OUTPUT);
  pinMode(grnLed, OUTPUT);
  pinMode(bluLed, OUTPUT);
  // turn RGB outputs off
  digitalWrite(redLed, HIGH);
  digitalWrite(grnLed, HIGH);
  digitalWrite(bluLed, HIGH);
}

void loop() {
  digitalWrite(redLed, LOW);
  delay(1000);
  digitalWrite(redLed, HIGH);
  delay(1000);
  digitalWrite(grnLed, LOW);
  delay(1000);
  digitalWrite(grnLed, HIGH);
  delay(1000);
  digitalWrite(bluLed, LOW);
  delay(1000);
  digitalWrite(bluLed, HIGH);
  delay(1000);
}
