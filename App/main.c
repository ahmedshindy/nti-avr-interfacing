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

void display_from_one_to_nine(u8 copyVal);

int main()
{
	Keypad_vInit();

	LCD_vInit();
	LCD_vWriteCommand(0x0e); // CMD_CURSOR_ON_DISPLAN_ON
	_delay_ms(10);
	LCD_vWriteData(0X0F);
	_delay_ms(10);
	LCD_vWriteData(0XF0);
	_delay_ms(10);
	
	while(1)
	{
		LCD_vWriteData('A');
		_delay_ms(100);
	}
}
int main_Keypad()
{
	Keypad_vInit();
	u8 LocalKeypadVal= NOTPRESSED;
	DIO_SetPinDir(DIO_PORTA,Pin5,OUTPUT);
	DIO_SetPinDir(DIO_PORTA,Pin6,OUTPUT);
	DIO_SetPinDir(DIO_PORTA,Pin4,OUTPUT);
	DIO_SetPinDir(DIO_PORTB,Pin7,OUTPUT);


	
	for (int i=0; i<8; i++)
	{
		DIO_TogglePinValue(DIO_PORTA,Pin5);
		_delay_ms(500);
	}
	DIO_SetPinValue(DIO_PORTB,Pin7,(LocalKeypadVal &=0x01));
	_delay_ms(500);
	DIO_SetPinValue(DIO_PORTB,Pin7,LOW);
	DIO_SetPinValue(DIO_PORTA,Pin5,LOW);


	while(1)
	{

		LocalKeypadVal = Keypad_u8Scan();
		while(Keypad_u8Scan() == NOTPRESSED);
		/*
		if(LocalKeypadVal == 1)
		{
			// DIO_SetPinValue(DIO_PORTA,Pin5,HIGH);
			 DIO_TogglePinValue(DIO_PORTA,Pin5);
			 _delay_ms(300);
			
			LocalKeypadVal = NOTPRESSED;
		}
		*/
		// display_from_one_to_nine(LocalKeypadVal);
		// raad the bits bit by bit , display them one by one
		
		// DIO_SetPinValue(DIO_PORTB,Pin7,READ_BIT(LocalKeypadVal,0));
		DIO_SetPinValue(DIO_PORTB,Pin7,HIGH);

		DIO_SetPinValue(DIO_PORTA,Pin4,READ_BIT(LocalKeypadVal,1));
		
		 // DIO_SetPinValue(DIO_PORTA,Pin5,(LocalKeypadVal &=0x04));
		 // DIO_SetPinValue(DIO_PORTA,Pin6,(LocalKeypadVal &=0x08));
		 DIO_SetPinValue(DIO_PORTA,Pin5,READ_BIT(LocalKeypadVal,2));
		 DIO_SetPinValue(DIO_PORTA,Pin6,READ_BIT(LocalKeypadVal,3));
		
		_delay_ms(1000);
	DIO_SetPinValue(DIO_PORTB,Pin7,LOW);
	DIO_SetPinValue(DIO_PORTA,Pin4,LOW);
	DIO_SetPinValue(DIO_PORTA,Pin5,LOW);
	DIO_SetPinValue(DIO_PORTA,Pin6,LOW);
		
		
	}
	
}

void display_from_one_to_nine(u8 copyVal)
{
switch (copyVal)
	{
	case 1:
		DIO_SetPinValue(DIO_PORTB,Pin7,HIGH);
		DIO_SetPinValue(DIO_PORTA,Pin4,LOW);
		DIO_SetPinValue(DIO_PORTA,Pin5,LOW);
		DIO_SetPinValue(DIO_PORTA,Pin6,LOW);

	break;
	case 2:
		DIO_SetPinValue(DIO_PORTB,Pin7,LOW);
		DIO_SetPinValue(DIO_PORTA,Pin4,HIGH);
		DIO_SetPinValue(DIO_PORTA,Pin5,LOW);
		DIO_SetPinValue(DIO_PORTA,Pin6,LOW);
	break;
	case 3:
		DIO_SetPinValue(DIO_PORTB,Pin7,HIGH);
		DIO_SetPinValue(DIO_PORTA,Pin4,HIGH);
		DIO_SetPinValue(DIO_PORTA,Pin5,LOW);
		DIO_SetPinValue(DIO_PORTA,Pin6,LOW);
	//
	break;
	case 15:
	DIO_SetPinValue(DIO_PORTB,Pin7,HIGH);
	DIO_SetPinValue(DIO_PORTA,Pin4,HIGH);
	DIO_SetPinValue(DIO_PORTA,Pin5,HIGH);
	DIO_SetPinValue(DIO_PORTA,Pin6,HIGH);
	//
	break;

	/*
	case 5:
	break;
	case 6:
	break;
	case 7:
	break;
	case 8:
	break;
	case 9:
	break;
	case 10:
	break;
	case 11:
	break;
	case 12:
	break;
	case 4:
	break;
	case 4:
	break;
	case 4:
	break;

	default:
	
	break;
	// all zeroes

	*/
	}
	return;
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

