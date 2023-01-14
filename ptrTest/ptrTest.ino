/*  Testing pointers.  They are useful if we have a function where we need to manipulate values in.
*/

#include <stdio.h>      //  The NULL symbolic constant is defined in this header file.

int k;
int num = 1575;
int *ptr_num = NULL;    // the asterisk indicated this is a pointer type variable
                        // the pointer's type specifier indicated the type of data to use with that pointer

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  
  prtStuff();

  ptr_num = &num;       // address of operator: take the address of num and copy it to the rvalue for ptr_num
                        // here we are assigning the address of variable num to ptr_num
  prtStuff();

  *ptr_num = 428;      // here the asterisk is an 'indirection' operator.
                       // change the value of num indirectly through the pointer (ptr_num)
                       // get the rvalue of ptr_num, go to that address, and copy the value 428 there,
  prtStuff();

  k = *ptr_num;        //  go to address in the rvalue of ptr_num, get the value, and assign it to the variable k;

  Serial.print("The rvalue for k = ");
  Serial.println(k, DEC);

  // exit the program
  Serial.flush();    // ensures that all data is sent to the serial monitor before the progtam exits
  exit(0);
}

// Function to print out items
void prtStuff() {
  Serial.print("The lvalue for ptr_num = ");
  Serial.println((long) &ptr_num, DEC);

  Serial.print("The rvalue for ptr_num = ");
  Serial.println((long) ptr_num, DEC);

  Serial.print("The lvalue for num = ");
  Serial.println((long) &num, DEC);

  Serial.print("The rvalue for num = ");
  Serial.println((long) num, DEC);

  Serial.print("\n");
}