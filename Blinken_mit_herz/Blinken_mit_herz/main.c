/*
 * Blinken_mit_herz.c
 *
 * Created: 17.09.2024 13:23:27
 * Author : admin
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMP_vect)
{
	PORTB = ~PORTB;
}

int main(void)
{
	DDRB = 0xFF;
	PORTB = 0x00;

	
	TCCR0 |= (1<<WGM01);
	OCR0 = 70;
	sei();
	TCCR0 |= (1<<CS02);
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

