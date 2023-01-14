/*
This program blinks a LED with varying delays based on a potentiometer reading.
Wire up a single LED on pin 6.
Wire up a POT to pin A0;
*/

const int LED = 6;
const int POT_PIN = A0;
const int MAX_DELAY = 9500;  // at the highest setting, blinls the LED every 10 seconds

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(POT_PIN, INPUT);
  analogReference(DEFAULT);
}

void loop() {
    long val = analogRead(POT_PIN);
     val = map(val, 0,1023, 0, MAX_DELAY);

    Serial.println(val);
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(val);

}
