/*
 * pwm.c
 *
 * Created: 18.09.2024 10:51:29
 * Author: admin
 */ 

#include "pwm.h"

/**
 * Initialisiert den PWM-Modus (Fast PWM).
 * 
 * Konfiguriert Timer0 für Fast PWM-Modus, setzt den Ausgangspin und initialisiert den Duty Cycle.
 */
void pwm_init(void)
{
    // Konfiguriert Timer0 für Fast PWM-Modus, nicht-invertierend, Prescaler 256
    TCCR0 = (1 << WGM01) | (1 << WGM00) | (1 << COM01) | (1 << CS02);
    
    // Setzt PB3 als Ausgang (OC0 Pin)
    DDRB |= (1 << PB3);
    
    // Initialisiert den Duty Cycle auf 0
    OCR0 = 0;
}

/**
 * Setzt den Duty Cycle des PWM-Signals.
 * 
 * @param prozent Der gewünschte Duty Cycle in Prozent (0-100).
 */
void pwm_set_duty(float prozent)
{
    // Berechnet und setzt den OCR0-Wert basierend auf dem Prozentwert
    OCR0 = (uint8_t)((255.0 * prozent) / 100.0);
}

/**
 * Initialisiert den PWM-Modus (Phase Correct PWM).
 * 
 * Konfiguriert Timer0 für Phase Correct PWM-Modus, setzt den Ausgangspin und initialisiert den Duty Cycle.
 */
void pwm_phase_init(void)
{
    // Konfiguriert Timer0 für Phase Correct PWM-Modus, nicht-invertierend, Prescaler 256
    TCCR0 = (1 << WGM00) | (1 << COM01) | (1 << CS02);
    
    // Setzt PB3 als Ausgang (OC0 Pin)
    DDRB |= (1 << PB3);
    
    // Initialisiert den Duty Cycle auf 0
    OCR0 = 0;
}
