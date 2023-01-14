/*
Read a potentiometer on pin A0.

Read a light dependent resistor (LDR) on pin A1. The sensor is connected from 5V to a 10K ohm resistor.
The resistor is then connected to ground.  Connect to pin A1 between the two.

Read a TMP36 temperature sensor on pin A2.  Use 3.3v analog reference for the TMP sensor.

Write the values to the Serial port to confirm it is working.
*/
#define aref_voltage 3.3  // we tie 3.3V to ARef

const int potPin = A0;
const int ldrPin = A1;
const int tempPin = A2;
int tempReading;   // the analog reading from thge temp sensor


void setup() {
  pinMode(potPin, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(tempPin, INPUT);
  analogReference(EXTERNAL);  //isn't necessary as this is the default
  Serial.begin(9600);
}

void loop() {

  Serial.print(analogRead(ldrPin));
  Serial.print("\t");
  Serial.print(analogRead(potPin));
  Serial.print("\t");
  Serial.print(analogRead(tempPin));

  

  // converting that reading to voltage, which is based off the reference voltage
  float voltage = tempReading * aref_voltage;
  voltage /= 1024.0; 
 
  // print out the voltage
  Serial.print(" - ");
  Serial.print(voltage); Serial.println(" volts");
 
  // now print out the temperature
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree with 500 mV offset
                                               //to degrees ((volatge - 500mV) times 100)
  Serial.print(temperatureC); Serial.println(" degrees C");
 
  // now convert to Fahrenheight
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF);
  Serial.println(" degrees F");
 

  delay(500);
}