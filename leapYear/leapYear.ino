/*
From p 105 of 'Beginning C for Arduino' book.

User types a year into Serial monitor to test.  Return is int 1 if 
the year is a leap year and int 0 if it is not.

Rational is you can use this ther function in a formula.

To test with the Arduino CLI, make sure 'New Line' is selected on the Message line of the Serial Monitor window.
*/

#include "IsLeapYear.c"

// int IsLeapYear(int yr);    // This is a function prototype for IsLeapYear()

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {     // is there a string of characters waiting to be processed
    int bufferCount;
    int year;
    char myData[20];

    bufferCount = ReadLine(myData);  // read what is in the serial buffer into a variable 

    year = atoi(myData);  // convert the characters returned to an int

    Serial.print(year);
    Serial.print("\t");
    Serial.println(IsLeapYear(year));
  }
}

/*****
  Purpose: Read data from serial port until a newline character is read ('\n')
  Parameters:
    char str[]    character array which is treated as a numm terminated array.  The string in the buffer is placed here.
  Return value:
  int             the number of characters read for the string
****/

int ReadLine(char str[]) {
  char c;
  int index = 0;

  while (true) {
    if (Serial.available() > 0) {       // Serial.available() returns the number of bytes available to be read
      c = Serial.read();


      if (c != '\n') {
        str[index++] = c;
      } else {
        str[index] = '\0';  // null termination character
        break;
      }
    }
  }
  return index;
}
