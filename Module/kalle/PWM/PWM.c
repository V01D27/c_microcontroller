/*
 * PWM.c
 *
 * Created: 18.09.2024 10:51:29
 *  Author: admin
 */ 

#include "PWM.h"

void PWM_fast_init()
{
	TCCR0 = (1 << WGM01)|(1 << WGM00)|(1 << COM01)|(1 << CS02);
	DDRB |= (1 << PB3);
	OCR0 = 0;
}

void PWM_setduty_percent(float prozent)
{
	OCR0 = 2.55*prozent;
}

void PWM_phase_init()
{
	TCCR0 = (1 << WGM00)|(1 << COM01)|(1 << CS02);
	DDRB |= (1 << PB3);
	OCR0 = 0;
}

void PWM_setduty_8bit (uint8_t value)
{
	OCR0 = value;
}
