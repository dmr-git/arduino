// Variable storage class test

extern int externVar;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  doNothing();
  delay(2000);
}

void doNothing() {
  static int counter = 0;  // static storage class will survive instantiations of this function.  gets initialized to 0, but we set it there to be explicit.
                           // static variables are only initialized the first time the function is called
  Serial.println(counter);
  counter = counter + 1;
  Serial.println(externVar);

  if (counter == 5) {
    delay(2000);
    exit(0);
  }
}