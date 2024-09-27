/*
 * Ampel.c
 *
 * Created: 16.09.2024 13:37:13
 * Author : admin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define ROT 128 
#define GELB 64 
#define GRUEN 32

void setz_rot_gelb();
void setz_rot();
void setz_gruen();
void setz_gelb();
void ampel();


int main(void)
{
	DDRB = 0xFF;
	
    /* Replace with your application code */
    while (1) 
    {
		ampel();

    }
}

void setz_rot_gelb()
{
	PORTB = ROT | GELB;
}

void setz_rot()
{
	PORTB = ROT;
}

void setz_gruen()
{
	PORTB = GRUEN;
}


void setz_gelb()
{
	PORTB = GELB;
}

void sleep_1s(uint8_t faktor)
{
	for (int i = 0; i < faktor; i++)
	{
		_delay_ms(1000);
	}
}

void ampel()
{
	setz_rot();
	sleep_1s(2);
	setz_rot_gelb();
	sleep_1s(1);
	setz_gruen();
	sleep_1s(2);
	setz_gelb();
	sleep_1s(1);
}
