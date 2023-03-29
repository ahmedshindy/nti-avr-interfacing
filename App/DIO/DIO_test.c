/***file : DIO_test.c*/


#define F_CPU   16000000UL
#include "STD_macros.h"
#include "STD_TYPES.h"
#include "util/delay.h"
#include  "DIO_interface.h"
#include "ADC_interface.h"


int main()
{
    DIO_SetPinDir(DIO_PORTA, Pin0, OUTPUT);
    DIO_SetPinDir(DIO_PORTA, Pin3, OUTPUT);
    DIO_SetPinDir(DIO_PORTB, Pin0,INPUT);
    u8 LocalPinRead= 0;
    
    while(1)
    {
        
        LocalPinRead= Dio_GetPinValue(DIO_PORTB,Pin0);
        if(LocalPinRead == 1)
        {
            DIO_SetPinValue(DIO_PORTA,Pin3,HIGH);
        }
        else if (LocalPinRead == 0)
        {
            DIO_TogglePinValue(DIO_PORTA,Pin3);
        }
        DIO_TogglePinValue(DIO_PORTA,Pin0);
        _delay_ms(1000);

    }
    return 0;
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

