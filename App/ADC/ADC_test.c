/**
 * ADC_test.c
*/

#define F_CPU   8000000UL
#include "STD_macros.h"
#include "STD_TYPES.h"
#include "util/delay.h"
#include  "DIO_interface.h"
#include "ADC_interface.h"


int main()
{
    u16 LocADC_Read= 0x0000;
    // init 
    ADC_init();
    // set pin out
    DIO_SetPinDir(DIO_PORTB,Pin0,OUTPUT);
    DIO_SetPinDir(DIO_PORTB,Pin1,OUTPUT);

    DIO_SetPinValue(DIO_PORTB,Pin1,HIGH);

    _delay_ms(100);
    while (1)
    {
        LocADC_Read = ADC_Read(ADC0);
        if(LocADC_Read > 500 )
        {
           DIO_SetPinValue(DIO_PORTB,Pin1,HIGH);

        }
        else if (LocADC_Read <= 500)
        {
           DIO_SetPinValue(DIO_PORTB,Pin1,LOW);
        }
    }
    return 0;
}

// void custom_delay(u32 val)
// {
//     _delay_ms(500);
// }