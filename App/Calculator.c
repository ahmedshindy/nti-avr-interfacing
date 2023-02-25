/*
 * Calculator.c
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
}