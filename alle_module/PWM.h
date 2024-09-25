/*
 * pwm.h
 *
 * Created: 18.09.2024 10:50:48
 * Author: admin
 */ 

#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

/**
 * Initialisiert den PWM-Modus (Fast PWM).
 * 
 * Konfiguriert Timer0 für Fast PWM-Modus, setzt den Ausgangspin und initialisiert den Duty Cycle.
 * 
 * Eingabe: Keine
 * Ausgabe: Keine
 */
void pwm_init(void);

/**
 * Setzt den Duty Cycle des PWM-Signals.
 * 
 * Eingabe:
 *   - prozent: float, der gewünschte Duty Cycle in Prozent (0.0 - 100.0)
 * Ausgabe: Keine
 */
void pwm_set_duty(float prozent);

/**
 * Initialisiert den PWM-Modus (Phase Correct PWM).
 * 
 * Konfiguriert Timer0 für Phase Correct PWM-Modus, setzt den Ausgangspin und initialisiert den Duty Cycle.
 * 
 * Eingabe: Keine
 * Ausgabe: Keine
 */
void pwm_phase_init(void);

#endif /* PWM_H_ */
