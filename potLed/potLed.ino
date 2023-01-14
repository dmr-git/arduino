/*
Read a POT on pin A0 to control a LED on pin 6 via PWM
The code maps the analog input values (0-1023) to analog output values (0 - 255)
Writes the mapped values to serial port for demonstration purpose
*/

const int analogInPin = A0;
const int analogOutPin = 6;
int sensorValue = 0;
int outputValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  analogWrite(analogOutPin, outputValue);

  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  delay(2);
}
