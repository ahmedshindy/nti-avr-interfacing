/*
<<<<<<< HEAD
 * Dio.c
=======
 * Calculator.c
>>>>>>> eb155b22675510aee95b76adb41741fcb0a59ceb
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
<<<<<<< HEAD
	DIO_SetPinDir(DIO_PORTD,Pin0,OUTPUT);
	Keypad_vInit();
	
	
	while(1)
	{
		
		DIO_TogglePinValue(DIO_PORTD,Pin0);
		_delay_ms(1000);
	}
	
	
=======
	LCD_vInit();
	Keypad_vInit();
	u8 LocalTestVal=0xff;
	
	while(1)
	{
	LocalTestVal = Keypad_u8Scan();
	if(LocalTestVal == 0xff)	
	{
		continue;
	}
	else
	{
		LCD_vWriteData(LocalTestVal);
		_delay_ms(1000);
		LocalTestVal = 0xff;
	}

	}	
>>>>>>> eb155b22675510aee95b76adb41741fcb0a59ceb
}