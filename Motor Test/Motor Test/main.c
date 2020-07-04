/*
 * Motor Test.c
 *
 * Created: 1/31/2018 5:30:29 PM
 * Author : Udara Wanasinghe
 */ 

#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	MCUCSR |= 1 << JTD;
	MCUCSR |= 1 << JTD;
	DDRC  = 0xFF;
	
	while (1)
	{
		PORTC = 0b00000010;
		_delay_ms(3000);
		PORTC = 0b10000100;
		_delay_ms(3000);
	}
}

