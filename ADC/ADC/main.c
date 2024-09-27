/*
 * ADC.c
 *
 * Created: 19.09.2024 10:45:03
 * Author : admin
 */ 

#define F_CPU 16000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "UART.h"
#define MYUBRR (F_CPU/16L/BAUD)-1

void ADC_Init()
{
	DDRA=0x0;			/* Make ADC port as input */
	ADCSRA = 0x87;			/* Enable ADC, fr/128  */
	ADMUX = 0x40;			/* Vref: Avcc, ADC channel: 0 */
	
}

uint16_t ADC_Read(char channel)
{
	uint16_t Ain,AinLow;
	
	ADMUX &= 0xF0;
	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */

	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */
	
	_delay_us(10);
	AinLow = (uint16_t)ADCL;		/* Read lower byte*/
	Ain = (uint16_t)ADCH*256;		/* Read higher 2 bits and 
					Multiply with weight */
	Ain = Ain | AinLow;				
	return(Ain);			/* Return digital value*/
}

 
int main()
{
	ADC_Init();
	UART_init(BAUD9600);
	
	while(1)
	{
		UART_sendINT(ADC_Read(0));
		UART_sendChar(" ");
		_delay_ms(100);
	}
	return 0;
}