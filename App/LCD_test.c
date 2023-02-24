/*
 * LCD_test.c
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


int main()
{
	Keypad_vInit();
	LCD_vInit();
	
	// LCD_vWriteCommand(0x0e); // CMD_CURSOR_ON_DISPLAN_ON
	LCD_vWriteData('A');
	_delay_ms(1000);
	LCD_vWriteData('B');
	_delay_ms(1000);
	while(1);
}

int main_DIO_TEST()
{
	// for checking; 
	DIO_SetPinDir(DIO_PORTA,Pin6,OUTPUT);

	// mark pin as input, pull up
	DIO_SetPinDir(DIO_PORTD,Pin3,INPUT);
	DIO_SetPinValue(DIO_PORTD,Pin3,HIGH);
	while(1)
	{
		
			// read pin value if it is low ,
			// delay 25ms and read again
			// read the button again
			u8 value = Dio_GetPinValue(DIO_PORTD,Pin3);
			if(value == LOW)
			{
				_delay_ms(25);
				value = Dio_GetPinValue(DIO_PORTD,Pin3);
			}
			else
			{
				value = HIGH;
			}
			
		if (value == LOW)
		{
		DIO_SetPinValue(DIO_PORTA,Pin6,HIGH);
		}
	}

}
/* just blinking
int main()
{
	DIO_SetPinDir(DIO_PORTA,Pin6,OUTPUT);
	DIO_SetPinValue(DIO_PORTA,Pin6,HIGH);

	while (1)
	{
		// DIO_TogglePinValue(DIO_PORTA,Pin6);
		DIO_SetPinValue(DIO_PORTA,Pin6,LOW);
		_delay_ms(25);
		DIO_SetPinValue(DIO_PORTA,Pin6,LOW);
		_delay_ms(25);
	}

	return 0;
}
*/

