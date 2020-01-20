#ifndef LED_h
#define LED_h

#include <Arduino.h>

class LED 
{
public:
  LED(int channel, int* pins);
  void BlinkAll(int delay_ms);
  void LeftToRight(int numberofLEDs, int delay_ms);
  void RightToLeft(int numberofLEDs, int delay_ms);
  void BlinkAlternate(int delay_ms);
private:
  int _channel;
  int _pins[16];
};

#endif
