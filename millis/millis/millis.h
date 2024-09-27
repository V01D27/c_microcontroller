/*
 * millis.h
 *
 * Created: 17.09.2024 14:24:57
 *  Author: admin
 */ 



#ifndef MILLIS_H_
#define MILLIS_H_

#include <avr/io.h>
#include <stdint.h> 
void mllis_init();
uint64_t millis_get();



#endif /* MILLIS_H_ */