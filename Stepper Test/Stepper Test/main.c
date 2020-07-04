/*
 * Stepper Test.c
 *
 * Created: 1/27/2018 7:27:17 PM
 * Author : Udara Wanasinghe
 */ 

#include <avr/io.h>
#include "stepper.h"
#include <avr/delay.h>

int main(void)
{
    stepper_init();
	step_motor(90, STEPPER_CLOCKWISE);
	stop_motor();
}
