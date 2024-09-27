/*
* Zwei__taster.c
*
* Created: 17.09.2024 08:45:36
* Author : admin
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <avr/interrupt.h>
void register_setzten();


ISR (INT0_vect)
{
	PORTB = 0xFF;
}

ISR (INT1_vect)
{
	PORTB = 0x00;
}

int main(void)
{
	register_setzten();
	DDRB = 0xFF;
	
	/* Replace with your application code */
	while (1)
	{

	}
}



void register_fuer_interrupt()
{
	DDRD = 0x00;
	PORTD |= (1<<PD2) | (1<<PD3);
	GICR |= (1<<INT0) | (1<<INT1); 
	MCUCR |= (1<<ISC00) | (1<<ISC01) | (1<<ISC10) | (1<<ISC11);
	sei();
}



