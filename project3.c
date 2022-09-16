/*
 * project3.c
 *
 *  Created on: Oct 11, 2021
 *      Author: MARIAM ANWAR
 */
#include "adc.h"
#include "motor_driver.h"
#include "lcd.h"
#include "lm35_sensor.h"


int main (void)
{
	ADC_ConfigType ADC_CONFIGURATION = { INTERNAL_Vref , PRE_8 };
	uint8 TEMP_VALUE;
	DcMotor_Init();
	ADC_init(&ADC_CONFIGURATION);
	LCD_init();

	LCD_displayStringRowColumn( 0,4,"FAN is ");
	LCD_displayStringRowColumn( 1,4,"TEMP =  ");
	while (1)
	{
		TEMP_VALUE = LM35_getTemperature();

		if (TEMP_VALUE<30)
		{
			DcMotor_Rotate( MOTOR_STOP, 0);
			LCD_displayStringRowColumn( 0,12,"OFF");

		}
		else if (TEMP_VALUE>=30 && TEMP_VALUE<60 )
		{
			DcMotor_Rotate( MOTOR_CW , 25  );
			LCD_displayStringRowColumn( 0,12,"ON ");
		}
		else if (TEMP_VALUE>=60 && TEMP_VALUE<90 )
		{
			DcMotor_Rotate( MOTOR_CW , 50  );
			LCD_displayStringRowColumn( 0,12,"ON ");
		}
		else if (TEMP_VALUE>=90 && TEMP_VALUE<120 )
		{
			DcMotor_Rotate( MOTOR_CW , 75  );
			LCD_displayStringRowColumn( 0,12,"ON ");
		}
		else
		{
			DcMotor_Rotate( MOTOR_CW , 100  );
			LCD_displayStringRowColumn( 0,12,"ON ");
		}


		LCD_moveCursor(1,12);
		if (TEMP_VALUE>=0 && TEMP_VALUE<10){
			LCD_intgerToString(TEMP_VALUE);
			LCD_displayStringRowColumn(1,13," ");
		}
		else if (TEMP_VALUE>=10 && TEMP_VALUE<100){
			LCD_intgerToString(TEMP_VALUE);
			LCD_displayStringRowColumn(1,14," ");
		}
		else if (TEMP_VALUE>=100){
			LCD_intgerToString(TEMP_VALUE);
		}
	}
}
