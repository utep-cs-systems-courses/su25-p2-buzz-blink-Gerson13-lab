//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"

#define BUTTON1 BIT0
#define BUTTON2 BIT1
#define BUTTON3 BIT2
#define BUTTON4 BIT3
#define BUTTONS (BUTTON1 | BUTTON2 | BUTTON3 | BUTTON4)

//STATES
typedef enum{FLASH, BUZZ_1, BUZZ_2, DANCE, IDLE} State;
volatile State current_state = IDLE;

void button_init(){

  P2REN |= BUTTONS;
  P2OUT |= BUTTONS;
  P2DIR &= ~BUTTONS;
  P2IE |= BUTTONS;
  P2IES |= BUTTONS;
  P2IFG &= ~BUTTONS;
  P2IES |= BUTTONS;
}
int buttonPressed(int bit){
  return !(P1IN & bit);
}

int main(void){
  WDTCTL = WDTPW | WDTHOLD;
  configureClocks();
  timerAUpmode();
  enableWDTInterrupts();
  buzzer_init();
  led_init();
  button_init();
  or_sr(0x18);
  return 0;
  
}

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  switch(current_state) {
  case BUZZ_2: P1OUT &= ~(LED_RED | LED_GREEN); buzz_pattern();break;
  case FLASH: buzzer_set_period(0); advance_250th(); break;
  case BUZZ_1: buzzer_set_period(1000); P1OUT &= ~(LED_RED | LED_GREEN);  break;
  case DANCE: P1OUT &= ~(LED_RED | LED_GREEN); buzzer_set_period(0); red_dance(); break;
  case IDLE: P1OUT &= ~(LED_RED | LED_GREEN); buzzer_set_period(0); break;
  }
}

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & BUTTON1){
    current_state = FLASH;
  }else if(P2IFG & BUTTON2){
    current_state = BUZZ_1;
  }else if (P2IFG & BUTTON3){
    current_state = BUZZ_2;
    buzzState = 0;
    secsCount = 0;
  }else if(P2IFG & BUTTON4){
    current_state = DANCE;
  }
  P2IFG &= ~BUTTONS;
  P2IES |= BUTTONS;
}
