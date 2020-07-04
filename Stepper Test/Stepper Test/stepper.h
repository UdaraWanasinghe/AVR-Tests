
/*
 * stepper.h
 *
 * Created: 1/24/2018 1:55:46 AM
 *  Author: Udara Wanasinghe
 */ 

#include <avr/io.h>

#define STEPPER_CLOCKWISE 1
#define STEPPER_ANTICLOCKWISE 0
#define STEPPER_STOP 2

//configurations
#define STEPPER_DDR DDRA
#define STEPPER_PORT PORTA
#define STEPPER_PIN0 PINA4
#define STEPPER_PIN1 PINA5
#define STEPPER_PIN2 PINA6
#define STEPPER_PIN3 PINA7
#define STEP_ANGLE 1.8F
#define RPM 60.0
#define STEPPER_DELAY_MS (STEP_ANGLE / 60.0 * RPM)
#define STEP_DELAY 20

extern void stepper_init();

extern void step_motor(int angle, int direction);

extern void stop_motor();