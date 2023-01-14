/* Example from Chapter 4 of 'Beginning C in Arduino' book.

Simulate a coin flip and display by turning on red LED for heads and green LED for tails.
Turn off both for a few seconds, then turn on the appropriate LED based on random number
generator.  Assume odd number is heads and even numbers is tails. 

I added counters to track how random the flips are and plot the percentage of heads on the Serial Plotter.

*/

#define headsLed 13
#define tailsLed 12
#define delayPeriod 10
#define lightPeriod 5

long randNumber;
bool flippedHeads;
long numHeads = 0L;
long numTails = 0L;
int passes = 0;
long totHeads = 0l;
long totTails = 0L;

void setup() {
  // initialize serial port for troubleshooting
  Serial.begin(9600);
  if (!Serial) {
    ;
  }

  pinMode(headsLed, OUTPUT);
  pinMode(tailsLed, OUTPUT);

  randomSeed(analogRead(0));  // set randomSeed by input reading voltage on pin 0 and mapping it to a number between 0 and 1023
}

void loop() {

  randNumber = random(1, 1000001);  // generate random number between 1 and 1,000,000
  flippedHeads = (randNumber % 2);  //

  if (flippedHeads) {
    numHeads++;
    totHeads++;
    digitalWrite(headsLed, HIGH);
    digitalWrite(tailsLed, LOW);
    delay(lightPeriod);
  } else {
    numTails++;
    totTails++;
    digitalWrite(headsLed, LOW);
    digitalWrite(tailsLed, HIGH);
    delay(lightPeriod);
  }

  digitalWrite(headsLed, LOW);
  digitalWrite(tailsLed, LOW);
  delay(delayPeriod);

  passes++;

  if (passes % 100 == 0) {
    // Serial.print("Heads = ");
    // Serial.println(numHeads);
    // Serial.print("\tTails = ");
    // Serial.println(numTails);
    // Serial.print("\tTotal Heads = ");
    // Serial.println(totHeads);
    // Serial.print("\tTotal Tails = ");
    // Serial.println(totTails);
    Serial.println((float(totHeads)) / (totHeads + totTails), 4);

    numHeads = 0;
    numTails = 0;
    passes = 0;
  }
}
