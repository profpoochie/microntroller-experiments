/*
  Debounce sketch
  a switch connected to pin 2 lights the LED on pin 13
  debounce logic prevent misreading of switch state
*/

#include <Arduino.h>

const int inputPin = 2;    // the number of the input pin
const int debounceDelay = 50;    // the debounce time; increase if the output flickers
bool last_button_state = LOW;    // the previous reading from the input pin
int ledState = LOW;             // the current state of the output pin

// debounce returns the state when the switch is stable
bool debounce(int pin)
{
  bool state
  bool previous_state = digitalRead(pin);
  for(int counter = 0; counter < debounceDelay; counter++)
  {
    delay(1);   // wait 1 ms
    state = digitalRead(pin);  // read the input pin
    if(state != previous_state)
    {
      counter = 0; // reset counter
      previous_state = state; // update previous state
    }
  }
  return state;
}

void setup()
{
  pinMode(inputPin, INPUT); // initialize the input pin
  pinMode(LED_BUILTIN, OUTPUT);       // initialize the LED pin as an output
}

void loop()
{
  bool button_state = debounce(inputPin); // read the state of the input pin
  if (last_button_state != button_state && button_state == HIGH) // check if the input is pressed
  {
    ledState = !ledState; // if it is, change the state of the LED.
    digitalWrite(LED_BUILTIN, ledState); // set the LED with the ledState of the variable:
  }
  last_button_state = button_state; // save the current state as the last state, for next time through the loop
}