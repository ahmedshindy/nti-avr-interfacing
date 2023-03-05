
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


static void display_from_one_to_nine(u8 copyVal);

int main()
{
	Keypad_vInit();
	LCD_vInit();
	LCD_vWriteString("Testing Keypad");

	u8 LocalKeypadVal= NOTPRESSED;
	u8 LocCharVal = 'A';
	while(1)
	{
		// LocalKeypadVal = keypad_u8check_press();
		   LocalKeypadVal = Keypad_u8Scan();
		if(LocalKeypadVal == NOTPRESSED)
		{
			continue;
		}
		else
		{
			// put the data onto lcd
			LocCharVal = LocalKeypadVal + '0';
			LCD_vWriteData(LocCharVal);
			LocalKeypadVal = NOTPRESSED;
		}	
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