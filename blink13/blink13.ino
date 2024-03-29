// This is a global variable meaning it can be accessed by any
// code in the whole program (Use as few as possible)
 
// Define an integer that will always have the value of 13
// This is a constant
// Integer Values : -32,768 to 32,767
const int ledPin = 13;
 
void setup() {
  // Opens a serial port and sets how many bits per second
  // 9600 is 960 characters per second
  Serial.begin(9600);
  
  // Set to use pin 13 for output
  pinMode(ledPin, OUTPUT);
 
/* 3. 
  // A for loop performs an action multiple times
  // Each time through the loop we decrement i as long as it is > 0
  // You can use > < >= <=
  for(int i = 3; i > 0; i--){
    Serial.print(i);
    Serial.print(", ");
  }
  Serial.println("GO...\n");
*/
  // 4. Call the function and pass a parameter
  countDown(5);
 
  // 3. You can loop in the same way with while
  // This is a local variable that can only be accessed in the setup
  // function
  int j = 3;
  while(j > 0){
    Serial.print(j);
    Serial.print(", ");
    j--;
  }
  Serial.println("GO...\n");
 
  // 5. Add floating point numbers
  Serial.print("3.11111111 + 4.11111111 = ");
 
  // You can define how many decimals to print, but precision is 
  // lost after 6 digits
  Serial.println(addFloats(3.11111111, 4.11111111), 8);
 
  // Add doubles (Double & Floats are the same)
  Serial.print("3.11111111 + 4.11111111 = ");
  Serial.println(addDoubles(3.11111111, 4.11111111), 8);
 
  // Booleans have a value of true or false
  bool canVote = true;
 
  // The ternary operator returns the 1st value if the condition 
  // is true and other wise the 2nd
  Serial.print("Can I Vote? ");
  Serial.println(((canVote == true) ? "Yes" : "No"));
 
  // chars can hold any of 256 single characters
  // They must be surrounded by ' and you can't add numbers
  char letD = 'D';
  Serial.println(letD);
 
  // Other data types
  // byte : 0 - 255
  // unsigned int : 0 - 65535
  // long : -2,147,483,648 - 2,147,483,647
  // unsigned long : 0 - 4,294,967,295
  
  // End of 5
  
}
 
void loop() {
  // These are local variables
  // The amount of time to delay between actions
  
  // 2. Each time loop executes delayPeriods value would be reset to
  // 100 unless it is marked as static
  // static means to only initialize this variable 1 time
  static int delayPeriod = 100;
 
  // Used to increase/decrease the delayPeriod
  static int countDir = 1;
  
  // Turn pin 13 on
  digitalWrite(ledPin, HIGH);
 
  // Wait 1/10th a second
  delay(delayPeriod);
 
  // Turn pin 13 off
  digitalWrite(ledPin, LOW);
 
  // Wait 1/10th a second
  delay(delayPeriod);
 
  // 2. Change direction with a function
  countDir = checkDirChange(delayPeriod, countDir);
 
  /*
  // Switches the direction of the increment when limits are hit
  // || means we should execute code if the 1st condition OR the other is true
  // && is true only if both conditions are true
  if((delayPeriod == 1000) || (delayPeriod == 0)) {
    direction *= -1;
 
    // You can use > < >= <= ==, or !=
    if(direction < 0){
      Serial.println("Going Down");
    } else {
      Serial.println("Going Up");
    }
  }
  */
 
  // Increase / descrease the delay period depending of current direction
  delayPeriod += 100 * countDir;
  
  // Print to the serial monitor
  Serial.print("New Wait Time : ");
  Serial.println(delayPeriod);
}
 
// 2. This function receives 2 int parameters and returns 1 int
int checkDirChange(int delayPeriod, int countDir){
  if((delayPeriod == 1000) || (delayPeriod == 0)) {
    countDir *= -1;
 
    if(countDir < 0){
      Serial.println("Going Down");
    } else {
      Serial.println("Going Up");
    }
  }
  return countDir;
}
 
// 4. Receive a parameter and adjust the for loop
// void means this function returns no value
void countDown(int max){
  for(int i = max; i > 0; i--){
    Serial.print(i);
    Serial.print(", ");
  }
  Serial.println("GO...\n");
}
 
// 5. Adds and returns floats
float addFloats(float num1, float num2){
  return num1 + num2;
}
 
// 5. Add and return a double
double addDoubles(double num1, double num2){
  return num1 + num2;
}