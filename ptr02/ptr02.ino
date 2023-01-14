/* Using ponteres in two dimensional arrays
*/
#define DAYSINWEEK 7
#define CHARSINDAY 10

void setup() {
  Serial.begin(9600);
}

void loop() {
  // define as static to not eat up valuable SRAM space and to ensure with each pass of loop we do not regenerate the variables;
  static char days[DAYSINWEEK][CHARSINDAY] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
  
  int i, j;

  for (i = 0; i < DAYSINWEEK; i++) {
    Serial.print((int)&days[i][0]);  // show the lvalue
    Serial.print(" ");
    for (j = 0; days[i][j]; j++) {  // RDC - uses the fact that strings are null terminated
      Serial.print(days[i][j]);     // print one char
    }
    Serial.println();
  }
  Serial.flush();
  exit(0);
}
