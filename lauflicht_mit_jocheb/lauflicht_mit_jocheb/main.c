/*
 * lauflicht_mit_jocheb.c
 *
 * Created: 16.09.2024 08:11:40
 * Author : admin
 */ 

// Definiert die CPU-Frequenz auf 16 MHz
#define F_CPU 16000000UL

// Inkludiert notwendige AVR-Bibliotheken
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Konfiguriert alle Pins des Port B als Ausgänge
    DDRB = 0xFF;
    
    // Setzt initial alle Pins des Port B auf LOW
    PORTB = 0x00;

    // Hauptschleife des Programms
    while (1) 
    {
        // Erste Schleife: LEDs nacheinander einschalten (von links nach rechts)
        for(uint8_t i = 0; i < 8; i++)
        {
            // Schaltet die i-te LED ein
            PORTB |= (1 << i);
            // Wartet 100 Millisekunden
            _delay_ms(100);
        }

        // Zweite Schleife: LEDs nacheinander ausschalten (von links nach rechts)
        for(uint8_t i = 0; i < 8; i++)
        {
            // Schaltet die i-te LED aus
            PORTB &= ~(1 << i);
            // Wartet 100 Millisekunden
            _delay_ms(100);
        }
        
        // Dritte Schleife: LEDs nacheinander einschalten (von rechts nach links)
        for(int8_t i = 7; i >= 0; i--)
        {
            // Schaltet die i-te LED ein
            PORTB |= (1 << i);
            // Wartet 100 Millisekunden
            _delay_ms(100);
        }        
        
        // Vierte Schleife: LEDs nacheinander ausschalten (von rechts nach links)
        for(int8_t i = 7; i >= 0; i--)
        {
            // Schaltet die i-te LED aus
            PORTB &= ~(1 << i);
            // Wartet 100 Millisekunden
            _delay_ms(100);
        }
    }
}
