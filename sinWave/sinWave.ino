/*
Print sin wave
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(float i = 0.0; i <= 2.0 * PI; i += 0.1) {
    Serial.print(sin(i));
  }
}
