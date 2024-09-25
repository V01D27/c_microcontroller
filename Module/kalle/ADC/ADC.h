/*
 * ADC.h
 *
 * Created: 19.09.2024 12:31:19
 *  Author: admin
 */ 
#include <avr/io.h>
#include <util/delay.h>

#ifndef ADC_H_
#define ADC_H_


// Initialisiert den ADC
// Setzt ADCSRA und ADMUX Register für ADC-Betrieb
void ADC_Init();

// Liest den ADC-Wert vom angegebenen Kanal
// Parameter: channel - ADC-Kanal (0-7)
// Rückgabe: 16-Bit ADC-Wert
uint16_t ADC_Read(uint8_t channel);

// Konvertiert den ADC-Wert in eine Spannung
// Parameter: channel - ADC-Kanal (0-7)
// Rückgabe: Spannung in Volt
double ADC_voltage(uint8_t channel);

// Konvertiert den ADC-Wert in einen PWM-Prozentwert
// Parameter: channel - ADC-Kanal (0-7)
// Rückgabe: PWM-Prozentwert (0-100%)
double ADC_PWM_percent(uint8_t channel);
#endif /* ADC_H_ */