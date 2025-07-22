# makfile configuration
COMMON_OBJECTS  = main.o buzzer-project/buzzer.o buzzer-project/buzz-1.o 2-led-interrupt-rgflash/led-blink.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I. -I./2-led-interrupt-rgflash -I./buzzer-project -I./timerLib
LDFLAGS		= -L/opt/ti/msp430_gcc/include 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toyMain.elf

#additional rules for files
toyMain.elf: ${COMMON_OBJECTS} 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ lib/libTimer.a

load: toyMain.elf
	msp430loader.sh toyMain.elf

clean:
	rm -f *.o */*.o *.elf

buzzer-project/buzzer.o: buzzer-project/buzzer.c buzzer-project/buzzer.h
buzzer-project/buzz-1.o: buzzer-project/buzz-1.c buzzer-project/buzzer.h
2-led-interrupt-rgflash/led-blink.o: 2-led-interrupt-rgflash/led-blink.c 2-led-interrupt-rgflash/led.h



