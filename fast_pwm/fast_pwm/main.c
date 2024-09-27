/*
* fast_pwm.c
*
* Created: 18.09.2024 09:22:29
* Author : admin
*/

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
void PWM_init();

int main(void)
{
	PWM_init();
	OCR0 = 0;
	uint8_t duty = 0;
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

