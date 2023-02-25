/*
 * ADC_private.h
 *
 * Created: 25/2/2023 9:49:28 AM
 *  Author: Ahmed Shindy
 */ 

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define AREF            0
#define AVCC            1
#define Internal_2_56V  3



#define ADC_div_128   7
#define ADC_div_64    6
#define ADC_div_32    5
#define ADC_div_16    4
#define ADC_div_8     3
#define ADC_div_4     2
#define ADC_div_2     1

#define FREE_RUNNING                0
#define ANALOG_COMPARATOR	        1
#define EXTERNAL_INTERRUPT_REQUEST  2
#define Timer0_Compare_Match	    3
#define Timer0_Overflow			    4
#define Timer_Compare_Match_B	    5
#define Timer1_Overflow			    6
#define Timer1_Capture_Event	    7

#define SINGLE_CONVERSION_MODE      8




#define ADC_VOLTAGE_REFERENCE     AVCC

#define TRIGGER_MODE             SINGLE_CONVERSION_MODE

#define ADC_Division_Factor      ADC_div_128

#endif