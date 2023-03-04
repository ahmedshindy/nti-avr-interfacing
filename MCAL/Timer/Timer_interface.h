


#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
#include "STD_macros.h"
#include "STD_TYPES.h"
#include "Timer_config.h"
#include "Timer_private.h"



void Timer0_InitCTC(void);
void Timer0_Init_PWM(u8 DutyCycle);
void Timer0_InitPhCorrPWM(u8 DutyCycle);


void Timer0_Init(void);
void Timer0_Start(void);
void Timer0_Stop(void);

void Timer1_Init_ICU(void);
void Timer1_InitFastPWM(void);

/**General Functions: design later*/
void Timer_Init(void);
void Timer_Start(void);
void Timer_Stop(void);

void DelayMs(u16 Copy_val);

#endif