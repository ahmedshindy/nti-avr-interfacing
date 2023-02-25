/*
 * ADC_interface.h
 *
 * Created: 25/2/2023 9:49:28 AM
 *  Author: Ahmed Shindy
 */ 

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "STD_macros.h"
#include "STD_TYPES.h"
#include "ADC_config.h"
#include "ADC_private.h"
 
 
 //--channels----
#define ADC0              0
#define ADC1              1
#define ADC2              2
#define ADC3              3
#define ADC4              4
#define ADC5              5
#define ADC6              6
#define ADC7              7





void ADC_init();
u16 ADC_Read( u8 ADC_Channel  ) ;


#endif