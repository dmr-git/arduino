/*
This example controls the LED from the serial port.  Type 1 to turn on, 0 to turn off from the 
Arduino ISE Serial Monitor.  Make sure it says 'No Line Ending' in the Serial Monitor.
Hook up LED to pin 6.
*/

const int ledPin = 6;

void serialFlush()
{
  while (Serial.available() > 0)
  {
    char t = Serial.read();
  }
   delay(2000);
}

void setup()
{
  // create serial object
  Serial.begin(9600);
  pinMode (ledPin, OUTPUT);
}

void loop()
{
  // have the arduino wait to receive input
  while (Serial.available() == 0);

  // read the input and convert to int
  int val = (Serial.read() - '0');

  if (val == 1)
  {
    Serial.println("Led is On.");
    digitalWrite(ledPin, HIGH);
  }
  else if (val == 0)
  {
    Serial.println("Led is off.");
    digitalWrite(ledPin, LOW);
  }
  else
  {
    Serial.println("Invalid");
  }

  serialFlush();
}
  
