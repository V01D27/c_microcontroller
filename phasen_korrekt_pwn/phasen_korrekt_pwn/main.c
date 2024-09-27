/*
 * PWM.c
 *
 * Created: 18.09.2024 10:55:50
 *  Author: admin
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
void PWM_init()
{
	TCCR0 = (1<<WGM00) /*Fast PWM*/ | (1<<COM01) /*Non inverted*/| (1<<CS01)/*Prescaler*/;
	DDRB|=(1<<PB3);  //PB3 output
}

void PWM_set_duty(float prozent)
{
	OCR0 = (2.55 * prozent);
}



int main(void)
{
	PWM_init();
	OCR0 = 0;
	int64_t duty = 0;
	int8_t direction = 1;

	
	/* Replace with your application code */
	while (1)
	{
		OCR0 = duty;
		duty += direction;
		_delay_ms(10);
		if (duty == 255 || duty == 0)
		{
			direction *= -1;
		}
	}
}

