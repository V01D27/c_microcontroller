/*
 * UtilityLib.h
 *
 * Created: 15.12.2023
 *  Author: EIS2020
 */ 


#pragma once

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>

char* Util_intToString( int number );
char* Util_doubleToString( double number, uint8_t decimalPoints );
int Util_stringToInt( const char* str );
float Util_stringToFloat( const char* str );
char* Util_truncString( const char* str );
char* Util_concatStr( const char* str1, const char* str2 );
uint8_t Util_getStrLen( char* str );