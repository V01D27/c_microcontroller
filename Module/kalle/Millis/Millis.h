/*
 * Millis.h
 *
 * Created: 17.09.2024 14:20:36
 *  Author: admin
 */ 

#include <avr/io.h>

#ifndef MILLIS_H_
#define MILLIS_H_


// Initialisiert den Timer für die Millisekunden-Zählung
// Setzt den Timer2 im CTC-Modus mit 128 Prescaler
void millis_init();

// Gibt die aktuelle Anzahl der vergangenen Millisekunden seit der Initialisierung zurück
// Rückgabewert ist ein 64-Bit-Unsigned-Integer für lange Laufzeiten
uint64_t millis_get();

#endif /* MILLIS_H_ */