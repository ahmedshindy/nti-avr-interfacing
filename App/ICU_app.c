
#define  F_CPU 8000000UL

#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "Timer_interface.h"
#include "LCD_interface.h"
#include "avr/interrupt.h"
#include "LCD_private.h"
#include "util/delay.h"


/**** ICU global Variables ********/
volatile u16 Global_ICU_OVFs_count;
volatile u16 Global_FirstICR_Value;
volatile u16 Global_SecondICR_Value;
volatile u16 Global_ThirdICR_Value;
volatile u16 GlobalDifferenceICR_Value;
volatile double Global_s64_Frequency;
u8 volatile edge = 0;


void LCD_WriteNUM(u32 NUM);
void LCD_WriteNumber(u32 Number);
void Timer1_Calc_Freq_and_Duty();
// 65536
// #define TIMER_CLK           ;
#define TimerCLK               (F_CPU/CLK_DIV_BY_64) 

int main()
{
    LCD_vInit();
    LCD_vWriteData('A');
    LCD_vWriteData('B');

   // LCD_WriteNUM(5324);

    LCD_vWriteCommand(Clear_Display_Screen);
    while (1)
    {
        Timer1_Calc_Freq_and_Duty();
        while(edge  < 3 );
        LCD_vWriteString("2hda");
        _delay_ms(500);
        // make your calculations
        // display 2 values on lcd
        LCD_vWriteCommand(Clear_Display_Screen);
        LCD_vWriteData('F');
        LCD_vWriteData(':');
        LCD_vWriteData(' ');

        Global_s64_Frequency = (  (double) (TimerCLK/(Global_ThirdICR_Value - Global_FirstICR_Value))  );
        LCD_WriteNUM(Global_s64_Frequency);
        _delay_ms(3000);
        // Clearing old data
        edge =0;
        Global_FirstICR_Value =0;
        Global_ICU_OVFs_count =0;
        Global_SecondICR_Value =0;
        Global_ThirdICR_Value =0;
        Global_s64_Frequency = 0;

    }
    
}

/* @brief:  function calculates the freq and duty cycle of an input signal on ICP1 pin
*           and returns those values to and callback fn hopefully!
*/
void Timer1_Calc_Freq_and_Duty()
{
    // clear all at first
    TCCR1A = 0x00;
    TCCR1B = 0x00;

    SET_BIT(TCCR1B,ICES1); //FE
    // normal mode
    // select clk

    // enable isr
    SET_BIT(TIMSK_Reg,TOIE1); // Enable overflow interrupts and input capture flag
    SET_BIT(TIMSK_Reg,TICIE1);
    sei();
    TCCR1B  |=(CLK_DIV_BY_64);
}

ISR(TIMER1_CAPT_vect)
{
    if(edge == 0)
    {
        Global_FirstICR_Value = ICR1;
        edge++;
        // capture falling next
        CLR_BIT(TCCR1B,ICES1);
    }
    else if(edge == 1)
    {
        Global_SecondICR_Value = ICR1;
        edge ++;
        // capture rising next
        SET_BIT(TCCR1B,ICES1);
    }
    else
    {
        Global_ThirdICR_Value = ICR1;
        edge++;
        // clear all at the end
        TCCR1A = 0x00;
        TCCR1B = 0x00;   
        cli();
    }

    // clear flag bit
    CLR_BIT(TIFR_Reg,ICF1);
}

ISR(TIMER1_OVF_vect)
{
    Global_ICU_OVFs_count++;
    // clear flag bit
    CLR_BIT(TIFR,TOV1);
}


void LCD_WriteNUM(u32 NUM)
{
	u32 reminder=0 , reversed = 0 , digits = 0;
	if(NUM < 0)
	{
		LCD_vWriteData('-');
		NUM *= (-1);
	}
	while(NUM)
	{
		reminder = NUM % 10;
		reversed = reversed * 10 + reminder; 
		NUM /= 10;
		digits++;
	}
	while(digits)
	{
		reminder = reversed % 10;
		LCD_vWriteData(reminder + '0');
		reversed = reversed / 10;
		digits--;
	}
}


// void LCD_WriteNumber(u32 Number)
// {
//     u8  NumArray[20]={'0'};

//     if(Number == 0 )
//     {
 
//         LCD_vWriteData("0");
//         return;
//     }

//     u8 temp =Number %10;
//     u8 counter =0;
//     while (Number > 0)
//     {
//         NumArray[counter] = temp + '0';
//         counter++;
//         Number -= temp;
        
//         if(Number != 0)
//         {
//             temp = Number %10;
//         }
//         else
//         {
//             break;
//         }
//     }

//     for(int i=counter ; i>=0; i++)
//     {
//         LCD_vWriteData(NumArray[i]);
//     }
    
// }