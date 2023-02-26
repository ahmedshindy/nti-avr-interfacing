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