#include <Arduino.h>


int main(void)
{
  init();
  initVariant();


#if defined(USBCON)
  USBDevice.attach();
#endif
   
    setup();
      
    for (;;) {
      loop();
      if (serialEventRun) serialEventRun();
    }
          
    return 0;

}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
}