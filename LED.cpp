#include <Arduino.h>
#include "LED.h"

LED::LED(int channel, int* a){
  _channel = channel;
  for(int i = 0 ; i < channel; i ++)
  {
    _pins[i] = a[i] ;
    pinMode(_pins[i],OUTPUT);
  }
}
void LED :: BlinkAll(int delay_ms)
{
   for (int i = 0 ; i<_channel;i++)
   {
    digitalWrite(_pins[i],HIGH);
   }
   delay(delay_ms);
   for (int i = 0 ; i<_channel;i++)
   {
    digitalWrite(_pins[i],LOW);
   }
   delay(delay_ms);
}
void LED :: LeftToRight(int numberofLEDs, int delay_ms)
{
//  Setting All the LED to LOW on Start
  for(int i =0 ;i<_channel; i++)
  {
    digitalWrite(_pins[i], LOW);
  }
//  looping within the given LED channel limit -Steps of LED progress
  for(int i = 0 ;i<_channel; i =i+numberofLEDs)
  {
    for(int k =0 ;k<_channel; k++)
   {
    digitalWrite(_pins[k], LOW);
   }
//  Setting given numberof LEDs to glow on each step
    for (int j=i; j< (i+numberofLEDs) ;j++)
    {
    digitalWrite(_pins[j], HIGH);
    }
    delay(delay_ms);
  }
}
void LED :: RightToLeft(int numberofLEDs,int delay_ms)
{
    for(int i =_channel-1 ;i>=0; i--)
  {
    digitalWrite(_pins[i], LOW);
  }
  for(int i = _channel-1 ;i>=0; i=i-numberofLEDs )
  {
    for(int k =0 ;k<_channel; k++)
   {
    digitalWrite(_pins[k], LOW);
   }
   for (int j = i ; j > (i-numberofLEDs); j--)
   {
    digitalWrite(_pins[j], HIGH);
   }
    delay(delay_ms);
  }
}
void LED :: BlinkAlternate(int delay_ms)
{
  for (int i= 0 ; i < _channel;i ++)
  {
    digitalWrite(_pins[i], LOW);
  }
  for (int i = 0 ; i < _channel;i ++)
  {
    if (i % 2 == 0)
    {
      digitalWrite(_pins[i],HIGH);
    }
  }
  delay(delay_ms);
  for (int i=0 ; i < _channel;i ++)
  {
    digitalWrite(_pins[i], LOW);
  }
  for (int i = 0 ; i < _channel;i ++)
  {
    if (i % 2 != 0)
    {
      digitalWrite(_pins[i],HIGH);
    }
  }
  delay(delay_ms);
}
