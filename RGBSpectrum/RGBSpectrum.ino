/*
Produce colors of visible light spectrum through RGB colors on a common anode multi-color LED.
Cycles through Roy G Biv.
This LED has all the positive leads connected to one pin. From the flat side of the LED
the leads are red(cathode), common anode(+), green(cathode), and blue(cathode). The common anode is the
longest lead. Use a 220 ohm resistor from each cathode to the Arduino.
In this example we set the Arduino pins to low to allow current to flow back into the Arduino.
*/

#define RED 9
#define GREEN 10
#define BLUE 11
#define DELAY 20

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // fade from red to green
  for (int i = 0; i < 255; i++) {
    analogWrite(RED, i);          // red initially on
    analogWrite(GREEN, 255 - i);  // green initially off
    analogWrite(BLUE, 255);       // blue off
    delay(DELAY);
  }

  // fade from green to blue
  for (int i = 0; i < 255; i++) {
    analogWrite(RED, 255);       // red off
    analogWrite(GREEN, i);       // green initially on
    analogWrite(BLUE, 255 - i);  // blue initially off
    delay(DELAY);
  }

  // fade from blue to red
  for (int i = 0; i < 255; i++) {
    analogWrite(RED, 255 - i);  // red initially off
    analogWrite(GREEN, 255);    // green off
    analogWrite(BLUE, i);       // blue initially on
    delay(DELAY);
  }
}