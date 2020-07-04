
/*
 * keypad.h
 *
 * Created		: 1/25/2018 6:59:19 PM
 * Author		: Udara Wanasinghe
 * References	: http://extremeelectronics.co.in/avr-tutorials/4x3-matrix-keypad-interface-avr-tutorial/
 */ 

#include <avr/io.h>

#define KEYPAD_DDR DDRD
#define KEYPAD_PORT PORTD
#define KEYPAD_PIN PIND

extern char scan_for_key();