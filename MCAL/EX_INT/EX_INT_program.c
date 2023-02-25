/*
 * EX_INT_program.c
 *
 * Created: 2/24/2023 7:49:16 AM
 *  Author: Ahmed Shindy
 */ 

#define F_CPU	8000000UL
#include "STD_macros.h"
#include "STD_TYPES.h"
#include "EX_INT_config.h"
#include "EX_INT_private.h"
#include "EX_INT_interface.h"
//#include "avr/io.h"


void (*Global_INT0_FPtr )(void) = NULL;
void (*Global_INT1_FPtr )(void) = NULL;
void (*Global_INT2_FPtr )(void) = NULL;


void GIE()
{
	//sei(); buitin function
	asm("SEI");
}

void GID()
{
	asm("CLI");
}

void EX_INT_SET_MODE(INT_PIN_TYPE IntPin_Number, EXT_IRQ_TYPE IRQ)
{
	switch(IntPin_Number)	
	{
		case INT0_PIN:
			if(IRQ == IRQ_AT_FALLING_EDGE)
			{
				MCUCR_PORT &=~(1U<<0);
				MCUCR_PORT &=~(1U<<1);
			}
			else if(IRQ == IRQ_AT_ANY_LOGIC_CHANGE)
			{
				MCUCR_PORT |=(1U<<0U);
				MCUCR_PORT &=~(1U<<1U);
			}
			else if (IRQ == IRQ_AT_FALLING_EDGE)
			{
				MCUCR_PORT &=~(1U<<0U);
				MCUCR_PORT |=(1U<<1U);
			}
			else if (IRQ == IRQ_AT_RISING_EDGE)
			{
				MCUCR_PORT |= (1U<<0U);
				MCUCR_PORT |= (1U<<1U);
			}
			else if(IRQ == NO_IRQ_RESPONCE)
			{
				// to do, clear corresponding bit GICR bit 5
				GICR_PORT &=~(1U << 7U);
			}
			break;

		case INT1_PIN :
			if(IRQ == IRQ_AT_FALLING_EDGE)
			{
				MCUCR_PORT &=~(1U<<2U);
				MCUCR_PORT &=~(1U<<3U);
			}
			else if(IRQ == IRQ_AT_ANY_LOGIC_CHANGE)
			{
				MCUCR_PORT |=(1U<<2U);
				MCUCR_PORT &=~(1U<<3U);
			}
			else if (IRQ == IRQ_AT_FALLING_EDGE)
			{
				MCUCR_PORT &=~(1U<<2U);
				MCUCR_PORT |=(1U<<3U);
			}
			else if (IRQ == IRQ_AT_RISING_EDGE)
			{
				MCUCR_PORT |= (1U<<2U);
				MCUCR_PORT |= (1U<<3U);
			}
			else if(IRQ == NO_IRQ_RESPONCE)
			{
				GICR_PORT &=~(1U << 6U);
			}
			break;
		
		case INT2_PIN :
			if(IRQ == IRQ_AT_RISING_EDGE)
			{
				// set bit 6
				MCUCR_PORT |= (1U<<6U);
			}
			else if (IRQ == IRQ_AT_FALLING_EDGE)
			{
				// clear bit 6
				MCUCR_PORT &=~(1U<<6U);
			}
			else if (IRQ == NO_IRQ_RESPONCE)
			{
				GICR_PORT &=~(1U << 5U);
			}
			break;
	}
}

void EX_INT_Set_INT0_IRQ_Handler(void (*F_ptr)(void))
{
	Global_INT0_FPtr=F_ptr;
}
void EX_INT_Set_INT1_IRQ_Handler(void (*F_ptr)(void))
{
	Global_INT1_FPtr=F_ptr;
}
void EX_INT_Set_INT2_IRQ_Handler(void (*F_ptr)(void))
{
	Global_INT2_FPtr=F_ptr;
}

ISR(INT0_vect)
{
	if(Global_INT0_FPtr != NULL)
	{
		Global_INT0_FPtr();
	}
}

ISR(INT1_vect)
{
	if(Global_INT1_FPtr != NULL)
	{
		Global_INT1_FPtr();
	}
}
ISR(INT2_vect)
{
	if(Global_INT2_FPtr != NULL)
	{
		Global_INT2_FPtr();
	}
	
}