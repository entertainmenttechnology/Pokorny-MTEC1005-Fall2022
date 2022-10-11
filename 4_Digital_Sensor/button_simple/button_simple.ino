const int LEDpin = 13;        // declaring a constant integer named LEDpin w/ a value of 13
const int buttonPin = 2;      // declaring a constant integer named buttonpin w/ a value of 2

bool buttonState = LOW;       // declaring a bool (1-bit) named buttonState w/ a value of 0 or LOW

void setup()                  // Setup runs once at beginning of sketch
{
  pinMode(LEDpin, OUTPUT);    // set LED pin to output
  pinMode(buttonPin, INPUT);  // set button pin to input

  Serial.begin(38400);        // set rate of Serial port (needs to match Serial Monitor rate)
}

void loop()                   // Loop runs forever, until power off or reset
{
  buttonState = digitalRead(buttonPin);   // button state equals button pin input
  delay(10);                              // wait 10ms for button to "settle down", debounce
  
  Serial.println(buttonState);            // print current button state to Serial Monitor

  if (buttonState == HIGH)                // if button is pressed...
  {
    digitalWrite(LEDpin, HIGH);           // turn on LED
  }
  else                                    // unless button is not pressed, then...
  {
    digitalWrite(LEDpin, LOW);            // turn off LED
  }

}                             // end of loop
