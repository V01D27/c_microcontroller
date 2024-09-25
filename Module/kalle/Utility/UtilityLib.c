/*
 * UtilityLib.c
 *
 * Created: 15.12.2023
 *  Author: EIS2020
 */ 

#include "UtilityLib.h"


char* Util_intToString( int number ){
	char buffer[7]; // string-buffer capable of storing a 16-bit integer at max/min value
	itoa( number, buffer, 10 ); // converts the integer into a decimal string with base 10
	return Util_truncString( buffer ); // returns a pointer to the string with the shortest necessary size to contain the converted number
}

char* Util_doubleToString( double number, uint8_t decimalPoints ){
	char buffer[18];
	dtostrf( number, -1, decimalPoints, buffer );
	return Util_truncString( buffer );
}

int Util_stringToInt( const char* str ){
	return atoi( str );
}

float Util_stringToFloat( const char* str ){
	return atof( str );
}

char* Util_truncString( const char* str ){
	uint8_t strLength = strlen( str );
	char* truncStr = malloc( strLength + 1 );
	
	if (!truncStr){
		return NULL;
	}
	
	memcpy( truncStr, str, strLength + 1 );
	return truncStr;
}

char* Util_concatStr( const char* str1, const char* str2 ){
	uint8_t str1Len = strlen( str1 );
	uint8_t str2Len = strlen( str2 );
	
	char* result = malloc( str1Len + str2Len + 1 );
	
	if (!result){
		return NULL;
	}
	
	memcpy( result, str1, str1Len );
	memcpy( result + str1Len, str2, str2Len + 1 );
	
	return result;
}

uint8_t Util_getStrLen( char* str ){
	uint8_t strLength = strlen( str );
	return strLength;
}