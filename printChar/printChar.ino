/* Using this to test concepts as I learn C for Arduino
Note: for the negative numbers, the representation is two's complement + 1.
*/

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;  
  }
}

void loop() {
  for (char myChar = -128; myChar <= 127; myChar++) {
    Serial.write(myChar);
    Serial.print(" : ");
    Serial.print(myChar, DEC);
    Serial.print(" : ");
    Serial.print(myChar, HEX);
    Serial.print(" : ");
    Serial.println(myChar, BIN);

    if (myChar == 127) {
      // code to run forever so we only print the above once
      while (true) {
        continue;
      }
    }
  }
}
