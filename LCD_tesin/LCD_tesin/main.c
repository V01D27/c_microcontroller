/*
* LCD_tesin.c
*
* Created: 19.09.2024 14:57:42
* Author : admin
*/

#include <avr/io.h>
#include "lcd_lib.h"

int main(void)
{
	LCD4_init();
	LCD4_write_string("Hallo Welt");
	LCD4_gotoxy(0, 1);
	LCD4_write_string("Hallo Universum");
	/* Replace with your application code */
	while (1)
	{

	}
}

