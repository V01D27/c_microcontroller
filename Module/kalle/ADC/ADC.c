/*
 * ADC.c
 *
 * Created: 19.09.2024 12:31:35
 *  Author: admin
 */ 

#include "ADC.h"

void ADC_Init()
{
	DDRA=0x00;
	ADCSRA = (1 << ADEN)|(1 << ADPS0)|(1 << ADPS1)|(1 << ADPS2);
	ADMUX = (1 << REFS0);
	
}

uint16_t ADC_Read(uint8_t channel)
{
	uint16_t result;
	
	ADMUX &= 0xf0;
	ADMUX |=(channel & 0x0f);

	ADCSRA |= (1<<ADSC);
	while((ADCSRA&(1<<ADIF))==0);
	
	_delay_us(10);
	result = (uint16_t)ADCL;
	result |= (uint16_t)(ADCH << 8);
	
	
	return(result);
}


double ADC_voltage(uint8_t channel)
{
	uint16_t value;
	value = ADC_Read(channel);
	double voltage = 0.00488 * value;
	return voltage;
}

double ADC_PWM_percent(uint8_t channel)
{
	uint16_t value;
	value = ADC_Read(channel);
	double ocr = 0.0976 * value;
	return ocr;
}
