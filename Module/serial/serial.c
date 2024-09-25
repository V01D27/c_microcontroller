
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "serial.h"
#define F_CPU 16000000UL
#define BAUD9600 9600
#define MYUBRR ((F_CPU/16L/BAUD)-1)
static charhandler fptr;

ISR(USART_RXC_vect)
{
	if(fptr != NULL)
		fptr(UDR);
}

void serial_init(charhandler myfunction, int BAUD)
{
	fptr = myfunction;
		// Baudrate setzen
	UBRRH = (MYUBRR >> 8);  // Obere 8 Bits des Baud-Rate-Wertes
	UBRRL = (MYUBRR);       // Untere 8 Bits des Baud-Rate-Wertes

	// USART Empfänger und Sender aktivieren sowie Empfangs-Interrupt einschalten
	UCSRB |= (1<<RXEN) | (1<<TXEN) | (1<<RXCIE);

	// Rahmenformat einstellen: 8 Datenbits, 1 Stoppbit, keine Parität
	UCSRC |= (1 << UCSZ1) | (1 << UCSZ0)| (1 << URSEL);
	
}

void serial_send_char(uint8_t value_to_send)
{
	while (!(UCSRA & (1 << UDRE)));
	UDR = value_to_send;
}

void serial_send_string(char * string_to_send)
{
	while(*string_to_send)
	{
		serial_send_char(*string_to_send ++);
	}
}

void serial_send_int(int value_to_send)
{
	char send_buffer[12];
	itoa(value_to_send, send_buffer, 10);
}

void serial_send_double(double value_to_send)
{
	char send_buffer[20];
	dtostrf(value_to_send, 6, 2, send_buffer);
	serial_send_string(send_buffer);
}

void serial_send_string_nl(char * string_to_send)
{
	serial_send_string(string_to_send);
	serial_send_string("/r/n");
}
