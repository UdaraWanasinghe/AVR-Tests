
/*
 * stepper.c
 *
 * Created: 1/24/2018 1:56:04 AM
 *  Author: Udara Wanasinghe
 */ 
#include <avr/delay.h>

#include "stepper.h"

void stepper_init(){
	//set stepper pins as output
	STEPPER_DDR |= (1 << STEPPER_PIN0) | (1 << STEPPER_PIN1) | (1 << STEPPER_PIN2) | (1 << STEPPER_PIN3);
	//stop stepper motor
	stop_motor();
}

void step_motor(int nSteps, int direction){
	for (int i = 0; i < nSteps; i++)
	{
		
		STEPPER_PORT = 0b00110000;
		_delay_ms(STEP_DELAY);
		STEPPER_PORT = 0b00100000;
		_delay_ms(STEP_DELAY);
		STEPPER_PORT = 0b01100000;
		_delay_ms(STEP_DELAY);
		STEPPER_PORT = 0b01000000;
		_delay_ms(STEP_DELAY);
		STEPPER_PORT = 0b11000000;
		_delay_ms(STEP_DELAY);
		STEPPER_PORT = 0b10000000;
		_delay_ms(STEP_DELAY);
		STEPPER_PORT = 0b10010000;
		_delay_ms(STEP_DELAY);
		STEPPER_PORT = 0b00010000;
		_delay_ms(STEP_DELAY);
	}
}
	
void stop_motor(){
	//set stepper pins all 0
	STEPPER_PORT &= ~((1 << STEPPER_PIN0) | (1 << STEPPER_PIN1) | (1 << STEPPER_PIN2) | (1 << STEPPER_PIN3));
}