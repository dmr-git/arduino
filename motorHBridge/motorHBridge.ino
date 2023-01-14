/* Motor H-Bridge control
Refer Exploring Arduino by Jeremy Blum, chapter 4
*/

 #define EN 9
 #define MC1 3
 #define MC2 2
 #define POT 0

 int val = 0;  // stores the reading from the POT
 int velocity = 0; // stores desired velocity

// motor goes forward at given rate (from 0 to 255)
void forward (int rate) {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, HIGH);
  digitalWrite(MC2, LOW);
  analogWrite(EN, rate);
  Serial.print("forward\t");
  Serial.println(rate);
}
// motor goes backward at given rate (from 0 to 255)
void backward (int rate) {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, HIGH);
  analogWrite(EN, rate);
  analogWrite(EN, rate);
  Serial.print("backward\t");
  Serial.println(rate);
}
// stop motor
void brake() {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, LOW);
  digitalWrite(EN, HIGH);
  Serial.println("brake");
} 

void setup() {
  Serial.begin(9600);
  pinMode(EN, OUTPUT);
  pinMode(MC1, OUTPUT);
  pinMode(MC2, OUTPUT);
  brake();

}

void loop() {
  val = analogRead(POT);
  // Serial.println(val);

  // go forward
  if (val > 562) {
    velocity = map(val, 563, 1023, 0, 255);
    forward(velocity);
  }
  // go backward
  else if (val < 462) {
    velocity = map(val, 461, 0, 0, 255);
    backward(velocity);
  }
  // brake
  else {
    brake();
  }

}
