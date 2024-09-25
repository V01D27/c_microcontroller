/*
 * UART.h
 *
 * Created: 18.09.2024 14:14:15
 *  Author: admin
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

// Definierte Baudrate-Konstanten
#define BAUD9600 9600
#define BAUD19200 19200
#define BAUD38400 38400
#define BAUD76800 76800

// Überprüfung und Definition von F_CPU, falls nicht definiert
#ifndef F_CPU
# warning  "F_CPU not defined "
# define F_CPU 16000000UL
#endif

// Berechnung des UBRR-Wertes basierend auf F_CPU und BAUD
#define MYUBBR (F_CPU / (BAUD * 16UL) - 1)

#ifndef UART_H
// Initialisiert die UART-Schnittstelle mit der angegebenen Baudrate
void UART_init(int BAUD);

// Sendet ein einzelnes Byte über UART
void UART_send_Char(uint8_t valuetosend);

// Sendet einen String über UART
void UART_send_String(char *valuetosend);

// Sendet einen Integer-Wert über UART
void UART_send_INT(int valuetosend);

// Sendet einen Double-Wert über UART
void UART_send_double(double valuetosend);

// Sendet einen Zeilenumbruch über UART
void UART_send_NEWLINE();



#endif /* UART_H_ */