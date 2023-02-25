/*
 * Dio.c
 * Created: 2/17/2023 12:39:40 PM
 * Author : Ahmed Shindy
 */
#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include "LCD_interface.h"
#include "util/delay.h"


int main_calc()
{
	DIO_SetPinDir(DIO_PORTD,Pin0,OUTPUT);
	Keypad_vInit();
	
	
	while(1)
	{
		
		DIO_TogglePinValue(DIO_PORTD,Pin0);
		_delay_ms(1000);
	}
	
	
}