/*
 * LCD Test.c
 *
 * Created: 1/26/2018 11:13:35 PM
 * Author : Udara Wanasinghe
 */ 

#include <avr/io.h>
#include "lcd.h"
#include <avr/delay.h>

void show_animated_message(char* message){
	lcd_clrscr();
	for (int i = 0; message[i] != '\0'; i++)
	{
		lcd_putc(message[i]);
		_delay_ms(40);
	}
}

int main(void)
{
    lcd_init(LCD_DISP_ON);
	show_animated_message(" ** Welcome **");
	_delay_ms(2000);
	show_animated_message("** Automated **\n** Cup Washer **");
}

