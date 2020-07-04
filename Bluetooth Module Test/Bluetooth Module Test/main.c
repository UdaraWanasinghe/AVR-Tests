/*
 * Bluetooth Module Test.c
 *
 * Created: 1/22/2018 9:24:46 PM
 * Author : Udara Wanasinghe
 */ 

#include "lcd.h"
#include "bluetooth.h"
#include <avr/delay.h>

int main(void)
{
    lcd_init(LCD_DISP_ON);
	lcd_puts("Welcome");
	
	bluetooth_init();
	int i;
	char c;
	
	while (1)
	{
		c = bluetooth_receivec();
		
		if (c == 'A')
		{
			lcd_putc(c);
			bluetooth_transmits("RR:A");
			bluetooth_transmits("LL:100");
			
		}else if (c == 'B')
		{
			lcd_putc(c);
			bluetooth_transmits("RR:B");
			bluetooth_transmits("LL:200");
			
		}else if (c == 'C')
		{
			lcd_putc(c);
			bluetooth_transmits("RR:C");
			bluetooth_transmits("LL:300");
		}else if (c == 'D')
		{
			lcd_putc(c);
			bluetooth_transmits("RR:D");
			bluetooth_transmits("LL:400");
		}else if (c == 'E')
		{
			lcd_putc(c);
			bluetooth_transmits("RR:E");
			bluetooth_transmits("LL:500");
		}else if (c == 'F')
		{
			lcd_putc(c);
			bluetooth_transmits("RR:F");
			bluetooth_transmits("LL:600");
		}
	}
}

