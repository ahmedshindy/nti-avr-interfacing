

#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

/* Steps to configure 
* 1. select timer 
* 2. select timer mode availabl based on choise 1
* 3. select prescalar
*/
#define TIMER0      0
#define TIMER1      1
#define TIMER2      2

#define     TIMER   TIMER0


/**** MODES *******/
#define TIMER0_NORMAL_MODE            0
#define TIMER0_PWM_PHASE_CORRECT      1
#define TIMER0_CTC_MODE               2
#define TIMER0_FAST_PWM               3


#define MODE        TIMER0_NORMAL_MODE


/*** Clock Source **/
#define     CLK_NO_CLK_SOURCE           0
#define     CLK_NO_PRE_SCALAR           1
#define     CLK_DIV_BY_8                2
#define     CLK_DIV_BY_64               3
#define     CLK_DIV_BY_256              4
#define     CLK_DIV_BY_1024             5
            
#define     CLK_SRC_PRE_SCALAR             CLK_DIV_BY_1024

#endif