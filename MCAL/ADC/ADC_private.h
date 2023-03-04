/*
 * ADC_private.h
 *
 * Created: 25/2/2023 9:49:28 AM
 *  Author: Ahmed Shindy
 */ 

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADMUX_Reg           (*((volatile u8*)0x27))

#define  REFS1		7
#define  REFS0		6
#define  ADLAR		5
#define  MUX4		4
#define  MUX3	    3
#define  MUX2	   	2
#define  MUX1		1
#define  MUX0		0


#define ADCSRA_Reg          (*((volatile u8*)0x26))
#define  ADEN		7
#define  ADSC		6
#define  ADATE		5
#define  ADIF		4
#define  ADIE	    3
#define  ADPS2	   	2
#define  ADPS1		1
#define  ADPS0		0


#define SFIOR_Reg           (*((volatile u8*)0x50))
#define  ADTS2 7
#define  ADTS1 6
#define  ADTS0 5


#define ADCL_Reg           (*((volatile u8*)0x24))
#define ADCH_Reg           (*((volatile u8*)0x25))
#define ADC_DATA_Reg           (*((volatile u16*)0x24))

#endif