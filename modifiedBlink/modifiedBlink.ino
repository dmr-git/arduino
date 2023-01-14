/* Example from Chapter 4 of 'Beginning C in Arduino' book.
Turns on one LED for one second while the other is off, then reverses the LED's for
one second, repeatedly.
*/

#define redLed 13
#define greenLed 12
#define delayPeriod 750


void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
  delay(delayPeriod);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  delay(delayPeriod);
}
