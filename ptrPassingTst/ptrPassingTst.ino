/* Example code from page 142 of 'Beginning C for Arduino'
*/

#include <stdio.h>

#define READINGSPERDAY 24
#define VERYHIGHTEMPERATURE 200
#define VERYLOWTEMPERATURE -200

int todaysReadings[] = { 62, 64, 65, 68, 70, 70, 71, 72, 74, 75, 76, 78, 79,
                         79, 78, 73, 70, 70, 69, 68, 64, 63, 61, 59 };

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lowTemp;
  int highTemp;
  int retVal;

  Serial.println("=== Before function call ===");
  Serial.print("The lvalue for lowTemp is ");
  Serial.println((long)&lowTemp, DEC);
  Serial.print("The rvalue for lowTemp is ");
  Serial.println((long)lowTemp, DEC);

  Serial.print("The lvalue for highTemp is ");
  Serial.println((long)&highTemp, DEC);
  Serial.print("The rvalue for highTemp is ");
  Serial.println((long)highTemp, DEC);

  retVal = CalculateMinMax(todaysReadings, &lowTemp, &highTemp);  // passing the lvalue for lowTemp and highTemp to pass these by reference as opposed to pass by value

  Serial.println("=== After function call ===");
  Serial.print("The lvalue for lowTemp is ");
  Serial.println((long)&lowTemp, DEC);
  Serial.print("The rvalue for lowTemp is ");
  Serial.println((long)lowTemp, DEC);

  Serial.print("The lvalue for highTemp is ");
  Serial.println((long)&highTemp, DEC);
  Serial.print("The rvalue for highTemp is ");
  Serial.println((long)highTemp, DEC);
  Serial.println("\n");

  Serial.flush();  // make sure all the data is sent
  exit(0);
}

int CalculateMinMax(int temps[], int *minTemp, int *maxTemp) {
  int j;
  *minTemp = VERYHIGHTEMPERATURE;
  *maxTemp = VERYLOWTEMPERATURE;

  for (j = 0; j < READINGSPERDAY; j++) {
    if (temps[j] >= *maxTemp) {
      *maxTemp = temps[j];
    }
    if (temps[j] <= *minTemp) {
      *minTemp = temps[j];
    }
  }
}
