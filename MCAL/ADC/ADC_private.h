/*
 * ADC_private.h
 *
 * Created: 25/2/2023 9:49:28 AM
 *  Author: Ahmed Shindy
 */ 

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADMUX_Reg           (*((volatile u8*)0x27))
#define ADCSRA_Reg          (*((volatile u8*)0x26))
#define SFIOR_Reg           (*((volatile u8*)0x50))


#define ADCL_Reg           (*((volatile u8*)0x24))
#define ADCH_Reg           (*((volatile u8*)0x25))
#define ADC_DATA_Reg           (*((volatile u16*)0x24))
#endif