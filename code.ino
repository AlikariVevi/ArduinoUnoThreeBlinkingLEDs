
// Pins
int ledPinRed = 12;
int ledPinGreen = 13;
int ledPinBlue = 11;

// leds states initiallization
int ledStateRed = LOW;
int ledStateGreen =HIGH;
int ledStateBlue = LOW;




//store time variables
unsigned long previousMilSec = 0;
const long blingInterval = 2000; //milliseconds

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  unsigned long currentMilSec = millis();
  if(currentMilSec - previousMilSec >= blingInterval){
    previousMilSec = currentMilSec;
  }
  if(currentMilSec - previousMilSec < blingInterval/3){
      if(ledStateRed == LOW){
          ledStateRed = HIGH;
          ledStateGreen = LOW;
          ledStateBlue = LOW;
        }
      digitalWrite(ledPinRed, ledStateRed);
      digitalWrite(ledPinGreen, ledStateGreen); 
      digitalWrite(ledPinBlue, ledStateBlue);
   }
   if(currentMilSec - previousMilSec>= blingInterval/3 && currentMilSec - previousMilSec < blingInterval*2/3){
      if(ledStateBlue == LOW){
          ledStateRed = LOW;
          ledStateGreen = LOW;
          ledStateBlue = HIGH;
        }
      digitalWrite(ledPinRed, ledStateRed);
      digitalWrite(ledPinGreen, ledStateGreen); 
      digitalWrite(ledPinBlue, ledStateBlue);
   }
  if(currentMilSec - previousMilSec >= blingInterval*2/3){
    
      if(ledStateGreen == LOW){
          ledStateRed = LOW;
          ledStateGreen = HIGH;
          ledStateBlue = LOW;
        }
      digitalWrite(ledPinRed, ledStateRed); 
      digitalWrite(ledPinGreen, ledStateGreen); 
      digitalWrite(ledPinBlue, ledStateBlue);
   }

   
}
