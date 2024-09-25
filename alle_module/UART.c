/*
 * uart.c
 *
 * Created: 18.09.2024 14:16:57
 * Author: admin
 */ 

#include "UART.h"               // Inkludiere die Header-Datei für UART
#include <avr/interrupt.h>      // Inkludiere die AVR Interrupt-Bibliothek
#include <stdlib.h>            // Inkludiere die Standardbibliothek für Konvertierungsfunktionen

/**
 * @brief Interrupt-Service-Routine für den Empfang von UART-Daten
 * 
 * Diese Funktion wird aufgerufen, wenn ein Byte über UART empfangen wird.
 * Das empfangene Byte wird sofort zurückgesendet (Echo-Funktion).
 */
ISR(USART_RXC_vect)
{
    uint8_t value = UDR;       // Lese das empfangene Byte aus dem UART-Datenregister
    UDR = value;               // Sende das empfangene Byte zurück
}

/**
 * @brief Initialisiert die UART-Schnittstelle
 * @param baud Die gewünschte Baud-Rate
 * 
 * Konfiguriert die UART-Schnittstelle mit der angegebenen Baud-Rate,
 * aktiviert den Empfänger, Sender und den Empfangs-Interrupt.
 */
void uart_init(int baud)
{
    unsigned int ubrr = (F_CPU / (baud * 16UL)) - 1; // Berechnung des UBRR-Wertes

    UBRRH = (ubrr >> 8);     // Setze die oberen 8 Bits des UBRR-Wertes
    UBRRL = ubrr;            // Setze die unteren 8 Bits des UBRR-Wertes
    
    UCSRB |= (1 << RXEN) | (1 << TXEN) | (1 << RXCIE); // Aktiviere Empfänger, Sender und Empfangs-Interrupt
    
    UCSRC |= (1 << UCSZ1) | (1 << UCSZ0) | (1 << URSEL); // Setze das Frame-Format: 8 Datenbits, 1 Stoppbit
}

/**
 * @brief Sendet ein einzelnes Zeichen über UART
 * @param value_to_send Das zu sendende Zeichen (8-Bit)
 * 
 * Diese Funktion sendet ein einzelnes Byte über die UART-Schnittstelle.
 */
void uart_send_char(uint8_t value_to_send)
{
    while (!(UCSRA & (1 << UDRE))); // Warte, bis das Datenregister leer ist
    UDR = value_to_send;            // Schreibe das Zeichen in das Datenregister
}

/**
 * @brief Sendet einen String über UART
 * @param value_to_send Der zu sendende String
 * 
 * Diese Funktion sendet einen Null-terminierten String über die UART-Schnittstelle.
 */
void uart_send_string(char *value_to_send)
{
    while (*value_to_send)          // Solange das Ende des Strings nicht erreicht ist
    {
        uart_send_char(*value_to_send++); // Sende jedes Zeichen im String einzeln
    }
}

/**
 * @brief Sendet einen Integer-Wert als String über UART
 * @param value_to_send Der zu sendende Integer-Wert
 * 
 * Diese Funktion konvertiert einen Integer-Wert in einen String und sendet ihn über UART.
 */
void uart_send_int(int value_to_send)
{
    char buffer[12];               // Puffer für den konvertierten String
    itoa(value_to_send, buffer, 10); // Konvertiere den Integer in einen String (Basis 10)
    uart_send_string(buffer);      // Sende den konvertierten String über UART
}

/**
 * @brief Sendet einen Double-Wert als String über UART
 * @param value_to_send Der zu sendende Double-Wert
 * 
 * Diese Funktion konvertiert einen Double-Wert in einen String und sendet ihn über UART.
 */
void uart_send_double(double value_to_send)
{
    char buffer[20];               // Puffer für den konvertierten String
    dtostrf(value_to_send, 6, 2, buffer); // Konvertiere den Double in einen String mit 6 Gesamtstellen und 2 Nachkommastellen
    uart_send_string(buffer);      // Sende den konvertierten String über UART
}

/**
 * @brief Sendet einen Zeilenumbruch über UART
 *
 * Diese Funktion sendet einen Zeilenumbruch (\n\r) über die UART-Schnittstelle.
 */
void uart_send_newline(void)
{
    char buffer[3] = "\n\r";       // Puffer für Zeilenumbruch-Zeichenfolge
    uart_send_string(buffer);      // Sende den Zeilenumbruch über UART
}

/**
 * @brief Sendet einen Wagenrücklauf über UART
 *
 * Diese Funktion sendet ein Wagenrücklaufzeichen (\r) über die UART-Schnittstelle.
 */
void uart_send_carriage_return(void)
{
    char buffer[2] = "\r";         // Puffer für Wagenrücklauf-Zeichenfolge
    uart_send_string(buffer);      // Sende das Wagenrücklaufzeichen über UART
}
