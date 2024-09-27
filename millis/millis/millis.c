/*
 * millis.c
 *
 * Created: 17.09.2024 14:28:53
 *  Author: admin
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
static volatile uint64_t zaehler = 0;

ISR(TIMER2_COMP_vect)
{
	zaehler++; 
}

void millis_init()
{
	TCCR2 |= (1<<WGM21);
	TCCR2 |= (1 << CS22); //| (1 << CS22);  // Prescaler 64
	OCR2 = 250;  // (16MHz / 64 / 1000) - 1
	TIMSK |= (1<<OCIE2);

}

uint64_t millis_get()
{
	return zaehler;
}
