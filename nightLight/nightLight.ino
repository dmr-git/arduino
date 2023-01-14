/*
Night Light - gets brighter as room gets darker
*/

const int LED = 6;
const int LIGHT = A1;
const int MIN_LIGHT = 100;
const int MAX_LIGHT = 980;
const int THRESHOLD = 70;
int val = 0;  // analog reading

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LIGHT, INPUT);
}

void loop() {
  val = analogRead(LIGHT);
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);
  val = constrain(val,0,255);
  
  if (val > THRESHOLD) {
    analogWrite(LED, val);
  }
  else {
    analogWrite(LED, 0);
  }
  delay(1000);
}
