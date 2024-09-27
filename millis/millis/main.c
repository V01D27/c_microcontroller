#include <avr/io.h>
#include "millis.h"
#include <avr/interrupt.h>

int main(void)
{
	DDRB = 0xFF;
	millis_init();
	sei();
	uint64_t speicher = millis_get();
	
	while(1)
	{
		if (millis_get() >= speicher+ 100)
		{
			PORTB = ~PORTB;
			speicher = millis_get();
		}
	}
	
	return 0;
}
