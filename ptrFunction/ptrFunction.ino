/* Example from p. 163 of "Beginning C for Arduino".
*  Purpose: To show how pointers to functions work.
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  int number = 50;
  int (*funcPtr)(int n);   // this defines a pointer to a function
                           // funcPtr is a pointer to a function which has a single argument of int, and it returns an int
                           // the type specifier for a function pointer is dictated by the return value of the function 
 
  funcPtr = DisplayValue;  // this copies the lvalue of DisplayValue function
 
  number = (*funcPtr)(number);  //calls the function and passes the argiment into it. return value is stored in the variabe number.

  Serial.print("After return from function, number = ");
  Serial.println(number);
  Serial.flush();
  exit(0);
}

int DisplayValue(int val) {
  Serial.print("In function, val = ");
  Serial.println(val);
  return (val * val);
}