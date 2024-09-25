/*
 * UART.c
 *
 * Created: 18.09.2024 14:16:57
 *  Author: admin
 */ 

#include "UART.h"



ISR (USART_RXC_vect)
{
	uint8_t value = UDR;
	UDR = value;
}

void UART_init(int BAUD)
{
	UBRRH = (MYUBBR >> 8);
	UBRRL = MYUBBR;
	
	UCSRB |= (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
	
	UCSRC |= (1 << UCSZ1) | (1 << UCSZ0) | (1 << URSEL);
}

void UART_send_Char(uint8_t valuetosend)
{
	while (!(UCSRA & (1 << UDRE)));
	UDR = valuetosend;
}

void UART_send_String(char *valuetosend)
{
	while(*valuetosend)
	{
		UART_send_Char(*valuetosend++);
	}
}

void UART_send_INT(int valuetosend)
{
	char buffer[12];
	itoa(valuetosend, buffer, 10);
	UART_send_String(buffer);
}

void UART_send_double(double valuetosend)
{
	char buffer[20];
	dtostrf(valuetosend, 6, 2, buffer);
	UART_send_String(buffer);
}

void UART_send_NEWLINE()
{
	char buffer[3] = "\r\n";
	UART_send_String(buffer) ;
}
