#define LCD_DATA PORTB
#define LCD_DDR DDRB
#define rs PB0
#define rw PB1
#define en PB2
#define LCD_D4 PB4
#define LCD_D5 PB5
#define LCD_D6 PB6
#define LCD_D7 PB7

#define F_CPU 16000000UL

#define CLEAR 0b00000001
#define INSERT_MODE 0b00000110
#define TWO_LINES 0b00101000
#define DISPLAY_ON 0b00001100
#define DDRAMADRESS_1 0b00110011
#define DDRAMADRESS_2 0b00110010
#define OFF 0b00001000
#define ON 0b00001110
#define NEXT_LINE 0b11000000
#define SECOND_LINE 0b11000000
#define FIRST_LINE 0b10000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#ifndef LCD_LIB_H
#define LCD_LIB_H

// Sendet einen Befehl an das LCD im 4-Bit-Modus
void LCD4_cmd(unsigned char cmd);

// Initialisiert das LCD im 4-Bit-Modus
void LCD4_init();

// Schreibt ein einzelnes Zeichen auf das LCD
void LCD4_write(unsigned char data);

// Schreibt eine Zeichenkette auf das LCD
// Wechselt automatisch zur zweiten Zeile, wenn die Zeichenkette 16 Zeichen überschreitet
void LCD4_write_string(const char *data);

// Bewegt den Cursor an die angegebene Position
// x: Spalte (0-15), y: Zeile (0-1)
void LCD4_gotoxy(int x, int y);

// Löscht die LCD-Anzeige
void LCD4_clear();

// Hilfsfunktion zur Erzeugung eines Enable-Impulses für das LCD
// Diese Funktion wird intern von anderen Funktionen verwendet
void LCD4_enable();

// Interne Hilfsfunktion zum Senden von Daten oder Befehlen an das LCD
// data: zu sendende Daten
// mode: 0 für Befehl, 1 für Daten
static void LCD4_send(uint8_t data, uint8_t mode);

// Schreibt eine Ganzzahl auf das LCD
void LCD4_write_integer(int data);

// Schreibt eine Gleitkommazahl auf das LCD
void LCD4_write_double(double data);

#endif // LCD_LIB_H