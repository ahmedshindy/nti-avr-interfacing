/*
 * EX_INT_interface.h
 *
 * Created: 2/24/2023 7:49:47 AM
 *  Author: Ahmed Shindy
 */ 

#ifndef EX_INT_INTERFACE_H_
#define EX_INT_INTERFACE_H_


#include "STD_macros.h"
#include "STD_TYPES.h"
#include "avr/interrupt.h"
#include "EX_INT_private.h"
#include "EX_INT_config.h"

typedef enum {IRQ_AT_lOW_LEVEL,IRQ_AT_ANY_LOGIC_CHANGE, IRQ_AT_FALLING_EDGE, IRQ_AT_RISING_EDGE,NO_IRQ_RESPONCE}EXT_IRQ_TYPE;
	
typedef enum {INT0_PIN, INT1_PIN, INT2_PIN}INT_PIN_TYPE;

#define INT2_PIN	2
#define INT1_PIN	1
#define INT0_PIN	0


void GIE();
void GID();
void EX_INT_Set_INT0_IRQ_Handler(void (*F_ptr)(void));
void EX_INT_Set_INT1_IRQ_Handler(void (*F_ptr)(void));
void EX_INT_Set_INT2_IRQ_Handler(void (*F_ptr)(void));
void EX_INT_SET_MODE(INT_PIN_TYPE IntPin_Number, EXT_IRQ_TYPE IRQ);




#endif /* EX_INT_INTERFACE_H_ */