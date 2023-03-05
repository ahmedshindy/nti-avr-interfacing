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

u8 GlobalLineArray[50] = {0};
int main()
{
	Keypad_vInit();
	LCD_vInit();


	while (1)
	{
		u8 counter =0;
		u8 LocKeypadVal = Keypad_u8Read();
		if(LocKeypadVal == NOTPRESSED)
		{
			continue;
		}
		else if(LocKeypadVal == '=')
		{
			// go for processing
			LCD_vWriteData(LocKeypadVal);
						
						
		}
		else
		{
			GlobalLineArray[counter] = LocKeypadVal;
			LCD_vWriteData(LocKeypadVal);
			counter++;
			LocKeypadVal = NOTPRESSED;
		}
		
	}
	
}