/*
 * LDR Test.c
 *
 * Created: 2/4/2018 7:48:27 AM
 * Author : Udara Wanasinghe
 */ 

#include <avr/io.h>
#include "lcd.h"

int main(void)
{
	lcd_init(LCD_DISP_ON);
    /* Replace with your application code */
	DDRA = 0x00;
	DDRC = 0xFF;
	PORTC = 0b00000100;
    while (1) 
    {
		char c[2];
		itoa(PINA & 0b00000010, c, 10);
		lcd_puts(c);
    }
}

