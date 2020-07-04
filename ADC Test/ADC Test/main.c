/*
 * ADC Test.c
 *
 * Created: 1/30/2018 12:03:17 PM
 * Author : Udara Wanasinghe
 */ 

#include <avr/io.h>
#include "lcd.h"
#include <avr/delay.h>

void adc_init()
{
	// AREF = AVcc
	ADMUX = (1<<REFS0);
	
	// ADC Enable and prescaler of 128
	// 16000000/128 = 125000
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint16_t adc_read(uint8_t ch)
{
	// select the corresponding channel 0~7
	// ANDing with ’7? will always keep the value
	// of ‘ch’ between 0 and 7
	ch &= 0b00000111;  // AND operation with 7
	ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing
	
	// start single convertion
	// write ’1? to ADSC
	ADCSRA |= (1<<ADSC);
	
	// wait for conversion to complete
	// ADSC becomes ’0? again
	// till then, run loop continuously
	while(ADCSRA & (1<<ADSC));
	
	return (ADC);
}

int main(void)
{
    lcd_init(LCD_DISP_ON);
	lcd_puts("Welcome");
	
	adc_init();
	
	while(1){
		char c[4];
		itoa(160 - adc_read(0), c, 10);
		lcd_clrscr();
		lcd_puts(c);
		_delay_ms(500);
	}
}

