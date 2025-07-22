#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

short buzzState = 0;
short secsCount = 0;

void buzz_pattern(){
  secsCount++;
  if(secsCount==250){
    secsCount=0;
    switch(buzzState){
    case 0: buzzer_set_period(1000);buzzState =1; break;
    case 1: buzzer_set_period(0); buzzState=0; break;
    }
  }
}

void buzz_pattern_2(){
  buzzer_set_period(1000);
}

 
