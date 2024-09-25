
#include "lcd_lib.h"

static void LCD4_send(uint8_t data, uint8_t mode)
{
	
		LCD_DATA = (LCD_DATA & 0x0F) | (data & 0xF0);
		
		if (mode == 0)
		{
			LCD_DATA &= ~(1<<rs); 
		} else 
		{
			LCD_DATA |= (1 << rs);
		}
		
		LCD4_enable();
		
		// Send lower nibble
		LCD_DATA = (LCD_DATA & 0x0F) | ((data << 4) & 0xF0);
		
		LCD4_enable();
	
}

void LCD4_enable()
{
	LCD_DATA |= (1<<en);
	_delay_ms(1);
	LCD_DATA &= ~(1<<en);
	_delay_us(200);
}

void LCD4_cmd(unsigned char cmd)
{
	
	LCD4_send(cmd,0);
	// Send upper nibble

}

void LCD4_write(unsigned char data)
{
	
	LCD4_send(data,1);
}


void LCD4_init()
{
	LCD_DDR = 0xFF;  // Set LCD port as output
	_delay_ms(20);   // Wait for LCD to power up
	
	// Initialize in 4-bit mode
	LCD4_cmd(DDRAMADRESS_1);
	_delay_ms(5);
	LCD4_cmd(DDRAMADRESS_2);
	_delay_ms(2);
	LCD4_cmd(TWO_LINES);  // 4-bit mode, 2 lines, 5x8 font
	_delay_ms(2);
	LCD4_cmd(DISPLAY_ON);  // Display on, cursor off
	_delay_ms(2);
	LCD4_cmd(INSERT_MODE);  // Increment cursor
	_delay_ms(2);
	LCD4_cmd(CLEAR);  // Clear display
	_delay_ms(2);
}


void LCD4_write_string(const char *data)
{
	
	int n=0;
	while(data[n])
	{
		LCD4_write(data[n]);
		n++;
		if (n==16)
		{
			LCD4_cmd(NEXT_LINE);
		}
	}
}

void LCD4_write_integer(int data)
{
	
	char buffer[12];
	itoa(data, buffer, 10);
	LCD4_write_string(buffer);
}

void LCD4_write_double (double data)
{
	char buffer[20];
	dtostrf(data, 4, 2, buffer);
	LCD4_write_string(buffer);
}

void LCD4_gotoxy(int x, int y)
{
	
	if (y==0)
	{
		LCD4_cmd(FIRST_LINE+x);
	}
	if (y==1)
	{
		LCD4_cmd(SECOND_LINE+x);
	}
}

void LCD4_clear()
{
	LCD4_cmd(CLEAR);
}