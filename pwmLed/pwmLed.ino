
/*
 * put a LED on pin 6
 */

const int led = 6;

void setup()
  {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  }

void loop()
  {
     for(int i=0;i<255;i = i + 5)
        {
          analogWrite(led, i);
          delay(40);
        }       
   }
 
