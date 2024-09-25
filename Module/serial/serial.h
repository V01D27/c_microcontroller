/*
 * serial.h
 *
 * Created: 19.09.2024 09:15:10
 *  Author: admin
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_
#include <avr/io.h>
#include <stdlib.h>
#define BAUD9600 9600

typedef void (*charhandler)(uint8_t );


void serial_init(charhandler myFunction, int BAUD);
void serial_send_char(uint8_t value_to_send);
void serial_send_string(char * string_to_send);
void serial_send_int(int value_to_send);
void serial_send_double(double value_to_send);
void serial_send_string_nl(char * string_to_send);




#endif /* SERIAL_H_ */