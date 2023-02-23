/*
 * Keypad_program.c
 * Created: 2/18/2023 7:25:18 AM
 *  Author: Ahmed Shindy
 */ 
#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include "util/delay.h"

void Keypad_vInit()
{
	// mark all 4 row as output pc 2:5
	DIO_SetPinDir(DIO_PORTC,Pin2,OUTPUT);
	DIO_SetPinDir(DIO_PORTC,Pin3,OUTPUT);
	DIO_SetPinDir(DIO_PORTC,Pin4,OUTPUT);
	DIO_SetPinDir(DIO_PORTC,Pin5,OUTPUT);
	
	// mark all 4 cols as input , they are already pulled up pd 3,5,6,7
	DIO_SetPinDir(DIO_PORTD,Pin3,INPUT);
	DIO_SetPinDir(DIO_PORTD,Pin5,INPUT);
	DIO_SetPinDir(DIO_PORTD,Pin6,INPUT);
	DIO_SetPinDir(DIO_PORTD,Pin7,INPUT);

	// optional: drive all rows low ? is it right? NO it is wrong
	// drive all output lines high coz they are low by default
	DIO_SetPinValue(DIO_PORTC,Pin2,HIGH);
	DIO_SetPinValue(DIO_PORTC,Pin3,HIGH);
	DIO_SetPinValue(DIO_PORTC,Pin4,HIGH);
	DIO_SetPinValue(DIO_PORTC,Pin5,HIGH);
	
	// set input pull ups for proteus
	Set_InputPullUp(DIO_PORTD,Pin3);
	Set_InputPullUp(DIO_PORTD,Pin5);
	Set_InputPullUp(DIO_PORTD,Pin6);
	Set_InputPullUp(DIO_PORTD,Pin7);



}

u8	 Keypad_u8Scan()
{
	u8 Return_value = NOTPRESSED;
	 u8 Keypad_matrix[4][4]= 
							{{1,2,3,4},
							{5,6,7,8},
							{9,10,11,12},                                                                                                      
							{13,14,15,16}}; 
								
	 int ROWs[4]  = {5,4,3,2};
	 int COLs[4] = {7,6,5,3};
		 
	// drive one rows low
	for(int row =0 ; row <4; row++)
	{
		DIO_SetPinValue(DIO_PORTC,ROWs[0],HIGH);
		DIO_SetPinValue(DIO_PORTC,ROWs[1],HIGH);
		DIO_SetPinValue(DIO_PORTC,ROWs[2],HIGH);
		DIO_SetPinValue(DIO_PORTC,ROWs[3],HIGH);


		DIO_SetPinValue(DIO_PORTC,ROWs[row],LOW);
		for(int col =0; col <4; col ++)
		{
			u8 LocalPinVal= Dio_GetPinValue(DIO_PORTD,COLs[col]);
			if(LocalPinVal == 0)
			{
				_delay_ms(25);
				LocalPinVal = Dio_GetPinValue(DIO_PORTD,COLs[col]);
				if (LocalPinVal == 0)
				{
					Return_value = Keypad_matrix[row][col];
					while (Dio_GetPinValue(DIO_PORTD,COLs[col]) == 0);
					DIO_SetPinValue(DIO_PORTC,ROWs[row],HIGH); // make default output == high macro
					return Return_value;

				}
			}
		}
		// restore default case "HIGH" for the row in progress
		DIO_SetPinValue(DIO_PORTC,ROWs[row],HIGH);
	}


	return Return_value;	
}
