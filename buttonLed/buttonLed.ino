/*
Use a push button to toggle a LED on and off.
This example uses a debounce function.
*/

const int BUTTON = 8;
const int LED = 6;

boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
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

void loop() {
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) {  // if button pressed...
    ledOn = !ledOn;                                  // toggle the Led
  }
  lastButton = currentButton;  //reset button value
  digitalWrite(LED, ledOn);
}