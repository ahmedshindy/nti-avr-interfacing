#include "STD_macros.h"
#include "STD_TYPES.h"
#include "Timer_config.h"
#include "Timer_private.h"
#include "Timer_interface.h"
#include "DIO_interface.h"
#include "avr/interrupt.h"

#define F_CPU   16000000UL

u32 Set_OVF_Glogal_count;
u8 Set_portion_OVF_Glogal_count;



void Timer0_InitCTC(void)
{
    
}
void Timer0_Init_PWM(u8 DutyCycle)
{

}
void Timer0_InitPhCorrPWM(u8 DutyCycle)
{
    // set oc0 output
    DIO_SetPinDir(DIO_PORTB,Pin3,OUTPUT);
    // PhCorr PWM
    SET_BIT(TCCR0_Reg , WGM00);
    OCR0_Reg = DutyCycle;
    // CLK
    TCCR0_Reg |=( CLK_SRC_PRE_SCALAR );
    // OC0 clear on compare match
    SET_BIT(TCCR0_Reg,COM01);
}


void Timer1_InitFastPWM(void)
{
    // set OC1A
    // select mode 
    // SET_BIT(TCCR1A,)
    // SET_BIT(TCCR1A,)
    // SET_BIT(TCCR1A,)
    // SET_BIT(TCCR1A,)



}
void Timer0_Init(void)
{
    // CTC mode
    TCCR0_Reg &=~(1<<7);
    TCCR0_Reg &=~(1<<3); 
    //0c0 disconnected
    TCCR0_Reg &=~(1<<5);
    TCCR0_Reg &=~(1<<4);
    sei();
    TIMSK_Reg |=(1<<0);
}
void Timer0_Start(void)
{
    // clear prescalar bits, then set them as required 100 which is 256
   
    #if (CLK_SRC_PRE_SCALAR ==CLK_DIV_BY_1024)
    TCCR0_Reg &=~(1<<0);
    TCCR0_Reg &=~(1<<1);
    TCCR0_Reg &=~(1<<2);

    TCCR0_Reg |=(CLK_DIV_BY_1024);
    
    #elif (CLK_SRC_PRE_SCALAR == CLK_DIV_BY_64)
    // this code should not run
    TCCR0_Reg &=~(1<<2);
    #endif 

}


void Timer0_Stop(void)
{
    TCCR0_Reg &=~(1<<0);
    TCCR0_Reg &=~(1<<1);
    TCCR0_Reg &=~(1<<2);
}


void DelayMs(u16 total_time)
{
    double  Loc_OVF_count = 0.0;
    u32 freq = F_CPU/CLK_SRC_PRE_SCALAR;


    Loc_OVF_count = ((double)(total_time * freq)/(double)(256*1000));

    Set_OVF_Glogal_count=(u32)Loc_OVF_count ;
    float potrtion = Loc_OVF_count - Set_OVF_Glogal_count;

    potrtion *= (256);
    Set_portion_OVF_Glogal_count = (u8)potrtion;
}









/****** General Functions ******/
void Timer_Init(void)
{
    #if (TIMER == TIMER0) 
    // clear bit 7,3    wgm00 01 normal
    TCCR0_Reg &=~(1<<7);
    TCCR0_Reg &=~(1<<3); 
    // clear bit 5,4  , 0c0 disconnected at normal mode
    TCCR0_Reg &=~(1<<5);
    TCCR0_Reg &=~(1<<4);
    // enable timer 0 interrupts
    TIMSK_Reg |=(1<<0);
    #elif (TIMER== TIMER1)
    // TCCR0_Reg &=~(1<<5);
    // TCCR0_Reg &=~(1<<4); 
    #endif

    // enable global interrupts
    sei();



}

void Timer_Start(void)
{
    // clear prescalar bits, then set them as required 100 which is 256
   
    #if (CLK_SRC_PRE_SCALAR_PRE_SCALAR ==CLK_DIV_BY_1024)
    TCCR0_Reg &=~(1<<0);
    TCCR0_Reg &=~(1<<1);
    TCCR0_Reg &=~(1<<2);

    TCCR0_Reg |=(CLK_DIV_BY_1024);
    
    #elif (CLK_SRC_PRE_SCALAR_PRE_SCALAR == CLK_DIV_BY_64)
    // this code should not run
    TCCR0_Reg &=~(1<<2);
    #endif 

    sei();
    TIMSK_Reg |=(1<<0);

}
void Timer_Stop(void)
{

}


