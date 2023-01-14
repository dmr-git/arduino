void setup() {
  Serial.begin(9600);
}

void loop() {
 char greet[6];

greet[0] = 'H';
greet[1] = 'e';
greet[2] = 'l';
greet[3] = 'l';
greet[4] = 'o';
 greet[5] = '\0';

 int i;

 for (i = 0; i < 5; i++) {
   Serial.print(*(greet + i));  // this is dumb code to show how to reference memory locations
 }

 Serial.print("\n");
 Serial.println(greet);        // the name of an array is the same as the lvalue of the array
 
 Serial.flush();
 exit(0);
}


