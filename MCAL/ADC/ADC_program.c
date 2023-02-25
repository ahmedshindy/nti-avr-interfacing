/*
 * ADC_program.c
 *
 * Created: 25/2/2023 9:49:28 AM
 *  Author: Ahmed Shindy
 */ 

#define F_CPU   8000000UL

#include "STD_macros.h"
#include "STD_TYPES.h"
#include "ADC_config.h"
#include "ADC_private.h"


void ADC_init()
{


    #if (ADC_VOLTAGE_REFERENCE == AVCC)
    ADMUX_Reg |=(AVCC<<6);
    #endif




    // left or right adjustment. No change
    // channel selection ADXMUX, not needed
    #if (ADC_Division_Factor == ADC_div_128)
    ADCSRA_Reg |=(ADC_div_128);
    #endif




    #if (TRIGGER_MODE == SINGLE_CONVERSION_MODE)
    // clear bit 5
    ADCSRA_Reg &=~(1<<5);

    #elif (TRIGGER_MODE == FREE_RUNNIGN)
    // set bit 5
    ADCSRA_Reg |=(1<<5);
    #endif


    ADCSRA_Reg |=(1<<3);
    // enable adc 

    ADCSRA_Reg |=(1<<7);
}



u16 ADC_Read( u8 ADC_Channel  ) 
{

    ADMUX_Reg |=(ADC_Channel<<0);
    // start conversion
    ADCSRA_Reg |=(1<<6);
    while ( (   (ADCSRA_Reg>>4) & (0x01)  ) == 0);
    // clear flag bit if not done in the ISR
    ADCSRA_Reg &=~(1<<4);

    return (ADC_DATA_Reg & 0x03ff );
}