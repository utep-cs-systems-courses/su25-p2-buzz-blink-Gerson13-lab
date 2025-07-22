#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles);
void buzz_pattern(void);
void buzz_pattern_2(void);
extern short secsCount;
extern short buzzState;



#endif // included
