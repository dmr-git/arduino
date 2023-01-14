/* Use a POT to control the speed of a motor
*/

#define MOTOR 6
#define POT A0

int val = 0;

void setup() {
  pinMode(MOTOR, OUTPUT);
  pinMode(POT, INPUT);
}

void loop() {
  val = analogRead(POT);
  val = map(val,0,1023,0,255);
  analogWrite(MOTOR, val);
}
