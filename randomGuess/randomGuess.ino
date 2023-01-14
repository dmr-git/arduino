/*
This is my take on the program presented on page 85 of 'Beginning C for Arduino'.
*/

#define RED 7
#define GREEN 8
#define MIN 0l
#define MAX 50000L

#define TARGET 2500L
#define MAX_LOOP_COUNT 5;

int cycleCount = 0;
int loopCount = 0;
long guess;
long totalGuesses = 0l;

void setup() {
  randomSeed(millis());
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(9600);
}

long getRandom() {
  return (random(MIN, MAX + 1L));
}

void loop() {
  while (true) {
    guess = getRandom();
    totalGuesses++;

    if (guess == TARGET) {
      // light GREEN LED for one second and report the value of the loop counter
      digitalWrite(GREEN, HIGH);
      delay(1000);
      digitalWrite(GREEN, LOW);
      Serial.print("Number of guesses: ");
      Serial.println(totalGuesses);
      Serial.print("Number was: ");
      Serial.println(guess);
      delay(5000);
      exit(0);
    }

    loopCount++;

    if (loopCount < 0) {
      // we have went past the top of what an int can hold
      // light the RED LED for one second and display how many tomes we recycled the int loop
      loopCount = 0;
      cycleCount++;
      digitalWrite(RED, HIGH);
      delay(1000);
      digitalWrite(RED, LOW);
      Serial.print("Cycle count: ");
      Serial.println(cycleCount);
    }

    if (cycleCount == 5) {
      Serial.print("We have exceeded MAX_LOOP_COUNT of ");
      Serial.println(cycleCount);
      delay(5000);
      exit(EXIT_FAILURE);
    }
  }
}
