#include "LED.h"

int const LED_pins[8]={2,3,4,8,9,10,11,12};
int const No_of_LED = 8; 

LED led(8,LED_pins);

void setup()
{
  Serial.begin(9600);
}
void loop()
{
//  led.BlinkAll(500);
  delay(1000);
  for (int i = 0 ; i < 3 ; i ++)
  {
  led.RightToLeft(2,500);
  led.LeftToRight(2,200);
  }
  delay(1000);
  for (int i = 0 ; i < 3; i ++)
  {
  led.BlinkAlternate(300);
  }
}
