/*
 * PushButton.c
 *
 * Created: 2/24/2023 11:57:53 AM
 *  Author: Ahmed Shindy
 */ 

#define F_CPU	8000000UL
#include "STD_macros.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "EX_INT_interface.h"
#include "util/delay.h"


u8 fallingEdge1 = 0x00;
u8 fallingEdge2 =0x00;
u8 action =0x01;
void toggle_portA_pin0();
void detect_one_Of_4_events();
int main()
{
	void (*LocalPtr)(void) = NULL;
	LocalPtr = detect_one_Of_4_events;
	// this pin is connected as pull up 
	DIO_SetPinDir(DIO_PORTD,Pin2,INPUT);
	//  ,pd2 int0
	EX_INT_SET_MODE(INT0_PIN,IRQ_AT_lOW_LEVEL);
	EX_INT_Set_INT0_IRQ_Handler(LocalPtr);
	
	while (1)
	{
		switch(action)
		{
			case 0x01;
			toggle_portA_pin0();
			break;
			case 0x02:
			toggle_portA_pin1();
			break;
			
			case 0x03:
			toggle_portA_pin2();
			break;
			
			case 0x04:
			t
		}
	}
	
}

void detect_one_Of_4_events()
{
	if(fallingEdge1 == 0)
	{
		fallingEdge1++;
		action = 0x01;
	}
	else if ( (fallingEdge1 == 1) && (fallingEdge2 == 0))
	{
		fallingEdge1 = 0;
		action = 0x02;
		return;
	}
	u8 localReading= 0x00;
	_delay_ms(5000);
	localReading= Dio_GetPinValue(DIO_PORTD,Pin2);
	if(localReading == LOW)
	{
		action = 0x03;
		_delay_ms(10000);
		localReading= Dio_GetPinValue(DIO_PORTD,Pin2);
		if(localReading == LOW)
		{
			action =0x04;
		}
	}
}
void toggle_portA_pin0()
{
	DIO_SetPinDir(DIO_PORTA,Pin0,OUTPUT);
	DIO_TogglePinValue(DIO_PORTA,Pin0);
}

void toggle_portA_pin1()
{
	DIO_SetPinDir(DIO_PORTA,Pin1,OUTPUT);
	DIO_TogglePinValue(DIO_PORTA,Pin1);
}

void toggle_portA_pin2()
{
	DIO_SetPinDir(DIO_PORTA,Pin2,OUTPUT);
	DIO_TogglePinValue(DIO_PORTA,Pin2);
}

void toggle_portA_pin3()
{
	DIO_SetPinDir(DIO_PORTA,Pin3,OUTPUT);
	DIO_TogglePinValue(DIO_PORTA,Pin3 );
}