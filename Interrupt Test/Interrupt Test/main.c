/*
 * Interrupt Test.c
 *
 * Created: 1/30/2018 2:53:51 PM
 * Author : Udara Wanasinghe
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include "bluetooth.h"

int main(void)
{
	lcd_init(LCD_DISP_ON);
	bluetooth_init();
	lcd_puts("Welcome");
	
	sei();
	UCSRB |= (1 << RXCIE);
	
    while (1)
    {
    }
}

ISR(USART_RXC_vect)
{
	char receivedByte;
	receivedByte = UDR;
	
	if (receivedByte == 'A')
	{
		lcd_putc(receivedByte);
		bluetooth_transmits("RR:A");
		bluetooth_transmits("LL:100");
		
	}else if (receivedByte == 'B')
	{
		lcd_putc(receivedByte);
		bluetooth_transmits("RR:B");
		bluetooth_transmits("LL:200");
		
	}else if (receivedByte == 'C')
	{
		lcd_putc(receivedByte);
		bluetooth_transmits("RR:C");
		bluetooth_transmits("LL:300");
	}else if (receivedByte == 'D')
	{
		lcd_putc(receivedByte);
		bluetooth_transmits("RR:D");
		bluetooth_transmits("LL:400");
	}else if (receivedByte == 'E')
	{
		lcd_putc(receivedByte);
		bluetooth_transmits("RR:E");
		bluetooth_transmits("LL:500");
	}else if (receivedByte == 'F')
	{
		lcd_putc(receivedByte);
		bluetooth_transmits("RR:F");
		bluetooth_transmits("LL:600");
	}
}