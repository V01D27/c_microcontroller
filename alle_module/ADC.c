/*
 * adc.c
 *
 * Created: 19.09.2024 12:31:35
 * Author: admin
 */ 

#include "adc.h"

/* Initialisiert den Analog-Digital-Wandler (ADC) */
void adc_init()
{
    DDRA = 0x00;  // Setzt Port A als Eingang
    ADCSRA = (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);  // Aktiviert ADC und setzt Prescaler
    ADMUX = (1 << REFS0);  // Setzt Referenzspannung auf AVCC
}

/* Liest den ADC-Wert vom angegebenen Kanal */
uint16_t adc_read(uint8_t channel)
{
    uint16_t result;
    
    ADMUX &= 0xf0;  // Löscht die unteren 4 Bits von ADMUX
    ADMUX |= (channel & 0x0f);  // Setzt den Kanal

    ADCSRA |= (1 << ADSC);  // Startet die Konvertierung
    while ((ADCSRA & (1 << ADIF)) == 0);  // Wartet auf Abschluss der Konvertierung
    
    _delay_us(10);  // Kurze Verzögerung
    result = (uint16_t)ADCL;  // Liest das untere Byte
    result |= (uint16_t)(ADCH << 8);  // Liest das obere Byte und kombiniert es
    
    return result;
}

/* Konvertiert den ADC-Wert in Spannung */
double adc_voltage(uint8_t channel)
{
    uint16_t value;
    value = adc_read(channel);
    double voltage = 0.00488 * value;  // Konvertiert ADC-Wert in Spannung
    return voltage;
}

/* Konvertiert den ADC-Wert in PWM-Prozent */
double adc_pwm_percent(uint8_t channel)
{
    uint16_t value;
    value = adc_read(channel);
    double ocr = 0.0976 * value;  // Konvertiert ADC-Wert in PWM-Prozent
    return ocr;
}
