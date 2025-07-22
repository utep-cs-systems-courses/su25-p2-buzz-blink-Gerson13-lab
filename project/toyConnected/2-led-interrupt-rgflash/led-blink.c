//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

short state = 0;
short ledState = 0;
short secCount = 0;
short redState= 0;


void led_init(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;
}

void advance_250th(){
  static short secCount=0;
  static short ledState=0;
  secCount++;
  if(secCount == 250){ /*one second has passed */
    secCount = 0;
    switch(ledState){
    case 0: P1OUT |= LED_RED; P1OUT &=~LED_GREEN; ledState=1; break;
    case 1: P1OUT |= LED_GREEN; P1OUT &=~LED_RED; ledState=0; break;
    }
  }
}
void red_dance(){
  static short secCount = 0;
  static short redState = 0;
  P1OUT |= LED_RED;
  secCount++;
  if(secCount == 10){
    secCount = 0;
    switch (redState){
    case 0: P1OUT |= LED_GREEN; redState=1; break;
    case 1: P1OUT &= ~LED_GREEN;redState =0; break;
    }
  }
}
