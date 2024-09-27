/*
* led_mit_pmw_steurn_durch_poty.c
*
* Created: 19.09.2024 12:54:57
* Author : admin
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#include "UART.h"
#include "PWM.h"


#define TOLERANCE 0.15

float calculateDifference(float a, float b) {
	return fabs(a - b) / ((a + b) / 2);
}

int main(void)
{
	adc_init();
	pwm_init();
	uart_init(BAUD_9600);
	float old_temp = -1.0;
	
	while (1)
	{
		_delay_ms(10);
		float temp = adc_pwm_percent(0);
		pwm_set_duty(temp);
		
		
		if (old_temp == -1.0 || calculateDifference(temp, old_temp) > TOLERANCE)
		{
			uart_send_string("LED in Prozent: ");
			uart_send_double(temp);
			uart_send_carriage_return();
			
			old_temp = temp;
		}
	}
}