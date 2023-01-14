
String inBytes;
const int led = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop()
{
  if (Serial.available() > 0)
  {
    inBytes = Serial.readStringUntil('\n');
    if (inBytes == "on")
    {
      digitalWrite(led, HIGH);
      Serial.write("Led on");
    }
    else if (inBytes == "off")
    {
      digitalWrite(led, LOW);
      Serial.write("Led off");
    }
    else
    {
      Serial.write("Invalid input.");
    }
  }

}
