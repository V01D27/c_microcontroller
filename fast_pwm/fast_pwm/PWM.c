/*
 * PWM.c
 *
 * Created: 18.09.2024 10:55:50
 *  Author: admin
 */ 
#include "PWM.h"
#include <avr/io.h>

void PWM_init()
{
	TCCR0 = (1<<WGM00) | (1<<WGM01)/*Fast PWM*/ | (1<<COM01) /*Non inverted*/| (1<<CS02)/*Prescaler*/;
	DDRB|=(1<<PB3);  //PB3 output
}

void PWM_set_duty(float prozent)
{
	OCR0 = (2.55 * prozent);
}