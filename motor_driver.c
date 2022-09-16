/*
 * motor_driver.c
 *
 *  Created on: Oct 12, 2021
 *      Author: MARIAM ANWAR
 */

#include "gpio.h"
#include "common_macros.h"
#include "motor_driver.h"
#include "PWM_driver.h"


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for setup the direction for the two motor pins.
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_E1_PORT_ID, MOTOR_E1_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
}

/*
 * Description :
 *function responsible for rotate the DC Motor CW/ or A-CW or stop the motor.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	uint8 duty_cycle;
	duty_cycle= (255/100) * speed ;
	Timer0_PWM_Start(duty_cycle);

	switch(state)
	{
	case MOTOR_STOP:
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	case MOTOR_CW:
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;
	case MOTOR_ACW:
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	}

}
