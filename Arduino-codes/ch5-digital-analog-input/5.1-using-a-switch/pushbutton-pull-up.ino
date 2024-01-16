/*
  Pushbutton sketch a switch connected to pin 2 lights the LED on pin 13
  Pull-up resistor version
*/

const int buttonPin = 2;     // the number of the pushbutton pin

void setup() {
  pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input
  pinMode(LED_BUILTIN, OUTPUT);       // initialize the LED pin as an output
}

void loop() {
  int buttonState = digitalRead(buttonPin); // read the state of the pushbutton value
  if (buttonState == HIGH) {                // check if the pushbutton is pressed.
    digitalWrite(LED_BUILTIN, LOW);        // turn LED on
  } else {
    digitalWrite(LED_BUILTIN, HIGH);       // turn LED off
  }
}