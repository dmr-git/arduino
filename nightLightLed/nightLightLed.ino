/*
Use a push button to toggle through several night light colors on a RGB LED.
Use a potentiometer to control the brightness of the RGB LED. When rotated counterclockwise.
hook ground to the pin on the left.
*/

const int BUTTON = 8;
const int BLED = 11;
const int GLED = 10;
const int RLED = 9;
const int POT = A0;
const int LDR = A1;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;  //cycle between LED states

void setup() {
  // Serial.begin(9600);   //uncommentfor debugging
  analogReference(DEFAULT);
  pinMode(BUTTON, INPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(POT, INPUT);
  pinMode(LDR, INPUT);
}

/*
Debounce function.  Pass it the previous button state,
and get back the current debounced button state.
*/
boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);  //read the button state
  if (last != current) {
    delay(5);                       // wait to givetime for the button to stop bouncing
    current = digitalRead(BUTTON);  // read it again
  }
  return current;
}

/*
LED Mode Selection: Pass a number for the LED state and set it accordingly.
Note: this script assumes the use of a common anode RGB led - thus we set the cathode pin
LOW to turn on each color
*/
void setMode(int mode) {
  // determine the percent brightness by reading the POT
  int val = analogRead(POT); 
  int ledLevel = map(val,0, 1023, 255, 0);  // map backwards as we are working with a common anode RGB LED
  
  // RED
  if (mode == 1) {
      analogWrite(RLED, ledLevel);
      digitalWrite(GLED, HIGH);
      digitalWrite(BLED, HIGH);
    }
  // GREEN
  else if (mode == 2) {
    digitalWrite(RLED, HIGH);
    analogWrite(GLED, ledLevel);
    digitalWrite(BLED, HIGH);
  }
  // BLUE
  else if (mode == 3) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    analogWrite(BLED, ledLevel);
  }
  // CYAN
  else if (mode == 4) {
    digitalWrite(RLED, HIGH);
    analogWrite(GLED, ledLevel);
    analogWrite(BLED, ledLevel);
  }
  // MAGENTA
  else if (mode == 5) {
    analogWrite(RLED, ledLevel);
    digitalWrite(GLED, HIGH);
    analogWrite(BLED, ledLevel);
  }
  // YELLOW
  else if (mode == 6) {
    analogWrite(RLED, ledLevel);
    analogWrite(GLED, ledLevel);
    digitalWrite(BLED, HIGH);
  }
  // WHITE (GREEN + RED + BLUE)
  else if (mode == 7) {
    analogWrite(RLED, ledLevel);
    analogWrite(GLED, ledLevel);
    analogWrite(BLED, ledLevel);
  }
  // OFF  (mode == 0)
  else {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
}

void loop() {
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) {  // if button pressed...
    ledMode++;                                       // increment the LED value
  }
  lastButton = currentButton;  //reset button value
  
  // reset counter to 0 if we have cycled through all options
  if (ledMode == 8) ledMode = 0;

  setMode(ledMode);
}