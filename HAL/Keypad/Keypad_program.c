/*
 * Keypad_program.c
 * Created: 2/18/2023 7:25:18 AM
 *  Author: Ahmed Shindy
 */ 
#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include "util/delay.h"

void Keypad_vInit()
{
	// mark all 4 row as output pc 2:5
	DIO_SetPinDir(DIO_PORTC,Pin5,OUTPUT);
	DIO_SetPinDir(DIO_PORTC,Pin4,OUTPUT);
	DIO_SetPinDir(DIO_PORTC,Pin3,OUTPUT);
	DIO_SetPinDir(DIO_PORTC,Pin2,OUTPUT);
	
	
	// mark all 4 cols as input , they are already pulled up pd 3,5,6,7

	
	DIO_SetPinDir(DIO_PORTD,Pin7,INPUT);
	DIO_SetPinDir(DIO_PORTD,Pin6,INPUT);
	DIO_SetPinDir(DIO_PORTD,Pin5,INPUT);
	DIO_SetPinDir(DIO_PORTD,Pin3,INPUT);

	// optional: drive all rows low ? is it right? NO it is wrong
	// drive all output lines high coz they are low by default
	
	DIO_SetPinValue(DIO_PORTC,Pin5,HIGH);
	DIO_SetPinValue(DIO_PORTC,Pin4,HIGH);
	DIO_SetPinValue(DIO_PORTC,Pin3,HIGH);
	DIO_SetPinValue(DIO_PORTC,Pin2,HIGH);

	
	// set input pull ups for proteus, for Eta32 it is optional
	Set_InputPullUp(DIO_PORTD,Pin7);
	Set_InputPullUp(DIO_PORTD,Pin6);
	Set_InputPullUp(DIO_PORTD,Pin5);
	Set_InputPullUp(DIO_PORTD,Pin3);
}

u8	 Keypad_u8Scan()
{
	u8 Return_value = NOTPRESSED;
	unsigned short Keypad_matrix[4][4]={{'1','2','3','4'},
										{'5',6,7,8},
										{9,10,11,12},                                                                                                      
										{13,14,15,16}
										}; 
								
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
					while (Dio_GetPinValue(DIO_PORTD,COLs[col]) == 0);	// stop here untill the button is unpressed
					DIO_SetPinValue(DIO_PORTC,ROWs[row],HIGH); // make default output == high again
					return (u8)Return_value;
				}
			}
		}
		// DIO_SetPinValue(DIO_PORTC,ROWs[row],HIGH); // restore default case "HIGH" for the row in progress,
	}
	return (u8)Return_value;	
}


 char Keypad_u8Read()
 {
	 char arr[4][4]={{'7','8','9','/'},
	 				{'4','5','6','*'},
					{'1','2','3','-'},
					{'A','0','=','+'}};
	 char row,coloumn,x;
	 char returnval=NOTPRESSED;

	int ROWs[4]  = {5,4,3,2};
	int COLs[4] = {7,6,5,3};
	 for(row=0;row<4;row++)
	 {
		// DIO_write('D',0,1);
		// DIO_write('D',1,1);
		// DIO_write('D',2,1);
		// DIO_write('D',3,1);
		// DIO_write('D',row,0);
		DIO_SetPinValue(DIO_PORTC,ROWs[0],HIGH);
		DIO_SetPinValue(DIO_PORTC,ROWs[1],HIGH);
		DIO_SetPinValue(DIO_PORTC,ROWs[2],HIGH);
		DIO_SetPinValue(DIO_PORTC,ROWs[3],HIGH);

		DIO_SetPinValue(DIO_PORTC,ROWs[row],LOW);

		for(coloumn=0;coloumn<4;coloumn++)
		{
			// x=DIO_u8read('D',(coloumn+4));
			x = Dio_GetPinValue(DIO_PORTD,COLs[coloumn]);
			if(x==0)
			 {
				while (Dio_GetPinValue(DIO_PORTD,COLs[coloumn]) == 0)
				{
					// stuck here untill you lift your finger
				}
				
				returnval=arr[row][coloumn];
				break;
			 }  
		}	
		if(x==0)
		{
			break;
		}
	}	 
	 return returnval ;	 
 }