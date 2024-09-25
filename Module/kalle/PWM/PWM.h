/*
 * PWM.h
 *
 * Created: 18.09.2024 10:50:48
 *  Author: admin
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

// Initialisiert den Timer im Fast PWM-Modus
void PWM_fast_init();

// Setzt die Pulsweite des PWM-Signals in Prozent (0-100%)
void PWM_setduty_percent(float prozent);

// Initialisiert den Timer im Phase Correct PWM-Modus
void PWM_phase_init();

// Setzt die Pulsweite des PWM-Signals mit einem 8-Bit-Wert (0-255)
void PWM_setduty_8bit (uint8_t value);         

#endif /* PWM_H_ */