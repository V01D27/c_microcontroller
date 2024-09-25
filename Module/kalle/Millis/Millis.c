/*
 * Millis.c
 *
 * Created: 17.09.2024 14:21:49
 *  Author: admin
 */ 
#include "Millis.h"

volatile static uint64_t milliseconds;

ISR(TIMER2_COMP_vect)
{
	milliseconds++;
}

void millis_init(){
	milliseconds = 0;
	
	OCR2 = 124;
	TCCR2 = (1 << WGM21)|(1 << CS22)|(1 << CS20);		//CTC Mode with 128 Prescaler
	TIMSK |= (1 << OCIE2);
}

uint64_t millis_get(){
	return milliseconds;
}