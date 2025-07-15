#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main() {
    configureClocks();
 
    buzzer_init();

    while(1){/* start buzzing!!! 2MHz/1000 = 2kHz*/
      buzzer_set_period(4000);
      __delay_cycles((2000000)*2); /* Sounds like a one second delay */
      buzzer_set_period(0); /*kills sound for one second*/
      __delay_cycles((2000000)*2);
      
      buzzer_set_period(500); /*change pitch*/
      __delay_cycles((2000000));
      buzzer_set_period(0);
      __delay_cycles((2000000));
      
       buzzer_set_period(500); /*change pitch*/
      __delay_cycles((2000000));
      buzzer_set_period(0);
      __delay_cycles((2000000));

       buzzer_set_period(500); /*change pitch*/
      __delay_cycles((2000000));
      buzzer_set_period(0);
      __delay_cycles((2000000)*2);
      
    }


    or_sr(0x18);          // CPU off, GIE on
}
