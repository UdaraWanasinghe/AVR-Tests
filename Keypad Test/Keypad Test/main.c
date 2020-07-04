/*
 * Keypad Test.c
 *
 * Created: 1/25/2018 9:06:29 AM
 * Author : Udara Wanasinghe
 */ 

#include <avr/io.h>
#include "lcd.h"
#include "keypad.h"

int main(void)
{	
	lcd_init(LCD_DISP_ON);
	while (1)
	{
		lcd_putc(scan_for_key());
	}
}


