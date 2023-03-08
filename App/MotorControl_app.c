/* Controlling the speed of the motor using ADC value and PWM */

#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "Timer_interface.h"
#include "ADC_interface.h"
#include "util/delay.h"


int main()
{
    // read ADC val 
    ADC_init();
    u16 Locu16ADC_Val = 0x00;
    DIO_SetPinDir(DIO_PORTB,Pin5,OUTPUT);   // DIR of motor
    DIO_SetPinValue(DIO_PORTB,Pin5,HIGH);
    DIO_SetPinDir(DIO_PORTB,Pin6,OUTPUT);   // EN of motor driver
    DIO_SetPinValue(DIO_PORTB,Pin6,HIGH);
    Locu16ADC_Val = ADC_Read(ADC0);
    // map from 1024 to 256
    Locu16ADC_Val = Locu16ADC_Val/4;
    // write vale on OCR0 reg
    Timer0_InitPhCorrPWM(Locu16ADC_Val);

    while (1)
    {
        // Read adc value
        Locu16ADC_Val = ADC_Read(ADC0);
        _delay_ms(100);

        // put the value on OCR0
        OCR0_Reg = (Locu16ADC_Val/4);
        
    }
    

}