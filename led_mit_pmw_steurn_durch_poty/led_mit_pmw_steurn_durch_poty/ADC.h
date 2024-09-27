/*
 * adc.h
 *
 * Created: 19.09.2024 12:31:19
 * Author: admin
 */ 

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <avr/delay.h>

/**
 * Initialisiert den Analog-Digital-Wandler (ADC).
 * 
 * Eingabe: Keine
 * Ausgabe: Keine
 */
void adc_init(void);

/**
 * Liest den ADC-Wert vom angegebenen Kanal.
 * 
 * Eingabe: 
 *   - channel: uint8_t, der zu lesende ADC-Kanal (0-7)
 * Ausgabe: 
 *   - uint16_t, der gelesene ADC-Wert (0-1023)
 */
uint16_t adc_read(uint8_t channel);

/**
 * Konvertiert den ADC-Wert des angegebenen Kanals in Spannung.
 * 
 * Eingabe:
 *   - channel: uint8_t, der zu lesende ADC-Kanal (0-7)
 * Ausgabe:
 *   - double, die berechnete Spannung in Volt
 */
double adc_voltage(uint8_t channel);

/**
 * Konvertiert den ADC-Wert des angegebenen Kanals in PWM-Prozent.
 * 
 * Eingabe:
 *   - channel: uint8_t, der zu lesende ADC-Kanal (0-7)
 * Ausgabe:
 *   - double, der berechnete PWM-Prozentwert (0-100)
 */
double adc_pwm_percent(uint8_t channel);

#endif /* ADC_H_ */
