


#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
#include "STD_macros.h"
#include "STD_TYPES.h"
#include "Timer_config.h"


void Timer0_INIT(void);
void Timer0_Start(void);
void Timer0_Stop(void);

void Timer_Init(void);
void Timer_Start(void);
void Timer_Stop(void);

void DelayMs(u16 Copy_val);

#endif