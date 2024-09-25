/*
 * uart.h
 *
 * Created: 18.09.2024 14:14:15
 * Author: admin
 */ 

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

// Definierte Baud-Raten für gängige Übertragungsgeschwindigkeiten
#define BAUD_9600 9600
#define BAUD_19200 19200
#define BAUD_38400 38400
#define BAUD_76800 76800

#ifndef F_CPU
#warning "F_CPU not defined, using default value of 16MHz"
#define F_CPU 16000000UL
#endif

/**
 * @brief Initialisiert die UART-Schnittstelle
 * @param baud Die gewünschte Baud-Rate
 * @return Keine Rückgabe
 * 
 * Konfiguriert die UART-Schnittstelle mit der angegebenen Baud-Rate.
 */
void uart_init(int baud);

/**
 * @brief Sendet ein einzelnes Zeichen über UART
 * @param value_to_send Das zu sendende Zeichen (8-Bit)
 * @return Keine Rückgabe
 * 
 * Sendet ein einzelnes Byte über die UART-Schnittstelle.
 */
void uart_send_char(uint8_t value_to_send);

/**
 * @brief Sendet einen String über UART
 * @param value_to_send Der zu sendende String
 * @return Keine Rückgabe
 * 
 * Sendet einen Null-terminierten String über die UART-Schnittstelle.
 */
void uart_send_string(char *value_to_send);

/**
 * @brief Sendet einen Integer-Wert als String über UART
 * @param value_to_send Der zu sendende Integer-Wert
 * @return Keine Rückgabe
 * 
 * Konvertiert einen Integer-Wert in einen String und sendet ihn über UART.
 */
void uart_send_int(int value_to_send);

/**
 * @brief Sendet einen Double-Wert als String über UART
 * @param value_to_send Der zu sendende Double-Wert
 * @return Keine Rückgabe
 * 
 * Konvertiert einen Double-Wert in einen String und sendet ihn über UART.
 */
void uart_send_double(double value_to_send);

/**
 * @brief Sendet einen Zeilenumbruch über UART
 * @return Keine Rückgabe
 * 
 * Sendet einen Zeilenumbruch (\n\r) über die UART-Schnittstelle.
 */
void uart_send_newline(void);

#endif /* UART_H_ */
