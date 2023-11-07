/*
  array sketch
  an array of switches controls an array of LEDs
*/

#include <Arduino.h>

int inputPins[] = {2, 3, 4, 5};
int ledPins[] = {10, 11, 12, 13};

void setup() {
  for (int index = 0; index < 4; index++) {
    pinMode(inputPins[index], INPUT);
    pinMode(ledPins[index], OUTPUT);
  }
}

void loop() 
{
  for (int index = 0; index < 4; index++) 
  {
    int val = digitalRead(inputPins[index]);
    if (val == LOW)
    {
      digitalWrite(ledPins[index], HIGH);
    }
    else
    {
      digitalWrite(ledPins[index], LOW);
    }
  }
}