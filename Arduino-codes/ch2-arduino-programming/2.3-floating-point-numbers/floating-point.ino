/*
  Floating-point numbers
  This sketch initialized a float value to 1.1
  It repeatedly reduces the value by 0.1 until the value is 0
*/

#include <Arduino.h>

float value = 1.1;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  value = value - 0.1;
  if (value == 0)
  {
    Serial.println("The value is exactly zero");
  }
  else if (almostEqual(value, 0))
  {
    Serial.print("The value ");
    Serial.print(value,7);
    Serial.println(" is almost to zero, restarting countdown");
    value = 1.1;
  }
  else
  {
    Serial.println(value);
  }
  delay(250);
}

bool almostEqual(float a, float b)
{
  const float DELTA = 0.00001;
  if (a == 0) return fabs(b) <= DELTA;
  if (b == 0) return fabs(a) <= DELTA;
  return fabs((a- b) / max(fabs(a), fabs(b))) <= DELTA;
}