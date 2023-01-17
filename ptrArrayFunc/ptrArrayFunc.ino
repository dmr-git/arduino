/* Example from p. 165 of "Beginning C for Arduino"
*  Purpose: Shows how to use an array of functions to perform different actions based on a reading
*/

enum temperatures { TOOCOLD,
                    TOOHOT,
                    JUSTRIGHT };  // TOOCOLD = 0; TOOHOT = 1; JUSTRIGHT = 2

enum temperatures whichAction;  // whichAction is a variable which can only have the values 0, 1, or 2

const int COLD = 235;
const int HOT = 260;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(millis()));
}

void loop() {
  // put your main code here, to run repeatedly:
  static void (*funcPtr[])() = { TurnUpTemp, TurnDownTemp, PourCandy };  // creates and iniaitalizes an array named funcPtr that
                                                                         // is an array of pointers to functions
  static int iterations = 0;
  int temp;

  temp = ReadVatTemp();  // this is the heart of this program

  whichAction = (enum temperatures)WhichOperation(temp);  // pass temp to WhichAction, cast the return value into the enum variable

  (*funcPtr[whichAction])();  // call the appropriate function

  //  this if just controls the number ot tests to do prior to exiting the program
  if (iterations++ > 20) {
    Serial.println("===========================");
    Serial.flush();
    exit(0);
  }
}
/*
  Purpose: return a value that determines whether to turn up the heat, turn down the heart
  or if the vat is ready. Pourable candy is between COLD and HOT (as defined above)

  Parameter: int temp = the current vat temperature

  Return (0 = temp too cold, 1 = temp too high, 2 = just right)
*/
int WhichOperation(int temp) {
  Serial.print("temp is ");
  Serial.print(temp);
  if (temp < COLD) {
    return TOOCOLD;
  } else {
    if (temp > HOT) {
      return TOOHOT;
    } else {
      return JUSTRIGHT;
    }
  }
}

/*
  Purpose: simulate reading a vat's temperature.  Values are constrained between 100 and 325 degrees
  
  Parameter list:
    void
  Return value: int = the temperature
*/
int ReadVatTemp() {
  return random(100, 326);
}

void TurnUpTemp() {
  Serial.println(" in TurnUpTemp()");
}

void TurnDownTemp() {
  Serial.println(" in TurnDownTemp()");
}

void PourCandy() {
  Serial.println(" in PourCandy()");
}
