#include <arduino.h>

const int outputPin = 9;
const int sensorPin = A0;

const int low = 200;
const int high = 800;

const int minDuration = 100;
const int maxDuration = 1000;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  int sensorReading = analogRead(sensorPin);

  int delayval = map(sensorReading, low, high, minDuration, maxDuration);
  delayval = constrain(delayval, minDuration, maxDuration);

  digitalWrite(outputPin, HIGH);
  delay(delayval);
  digitalWrite(outputPin, LOW);
  delay(delayval);
}