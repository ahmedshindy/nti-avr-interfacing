/*
 * LCD_program.c
 *
 * Created: 2/18/2023 7:29:33 PM
 *  Author: Ahmed Shindy
 */ 


#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "STD_macros.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "DIO_interface.h"
#include "LCD_private.h"
#include <util/delay.h>


static void Send_FallingEdge(void);
void LCD_vInit(void)
{
	_delay_ms(40);
	DIO_SetPinDir(DIO_PORTA,Pin4,OUTPUT);
	DIO_SetPinDir(DIO_PORTA,Pin5,OUTPUT);
	DIO_SetPinDir(DIO_PORTA,Pin6,OUTPUT);
	DIO_SetPinDir(DIO_PORTA,Pin7,OUTPUT);

	DIO_SetPinDir(RS_PORT,RS_PIN,OUTPUT);
	DIO_SetPinDir(EN_PORT,EN_PIN,OUTPUT);
	DIO_SetPinDir(RW_PORT,RW_PIN,OUTPUT);
	// always RW=0 low as it is on the kit
	DIO_SetPinValue(RW_PORT,RW_PIN,LOW); 
	// 02 , 28, 0x0e , 0x01 0x06
	// delays 10, 1, 1, 10 1 ms
	LCD_vWriteCommand(0x02);
	_delay_ms(10);
	LCD_vWriteCommand(0x28);
	_delay_ms(1);
	LCD_vWriteCommand(0x0e);
	_delay_ms(1);
	LCD_vWriteCommand(0x01);
	_delay_ms(10);
	LCD_vWriteCommand(0x06);
	_delay_ms(1);
	//LCD_vWriteCommand(FuncitonSet1); // 0x33 ==> 28
	// LCD_vWriteCommand(FuncitonSet2); // 0x32
	//LCD_vWriteCommand(LCD_4_Bit_Mode_2_Line_5_8_Dots); // 0x28
	// LCD_vWriteCommand(Display_Cursor_ON_Blink_OFF);  // 0x0E
	//LCD_vWriteCommand(Clear_Display_Screen); //0x01
	// LCD_vWriteCommand(Shift_Cursor_Right_Per_Read_Write); //0x06
}


static void Send_FallingEdge(void)
{
	// EN =1, delay 2ms , EN=0, delay 2ms, exit
	DIO_SetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	_delay_ms(2);
}

void LCD_vWriteCommand(u8 cmd)
{
	DIO_SetPinValue(DIO_PORTA,Pin7,READ_BIT(cmd,7));
	DIO_SetPinValue(DIO_PORTA,Pin6,READ_BIT(cmd,6));
	DIO_SetPinValue(DIO_PORTA,Pin5,READ_BIT(cmd,5));
	DIO_SetPinValue(DIO_PORTA,Pin4,READ_BIT(cmd,4));
	DIO_SetPinValue(RS_PORT,RS_PIN,LOW);
	Send_FallingEdge();
	_delay_ms(1);
	
	DIO_SetPinValue(DIO_PORTA,Pin7,READ_BIT(cmd,3));
	DIO_SetPinValue(DIO_PORTA,Pin6,READ_BIT(cmd,2));
	DIO_SetPinValue(DIO_PORTA,Pin5,READ_BIT(cmd,1));
	DIO_SetPinValue(DIO_PORTA,Pin4,READ_BIT(cmd,0));
	DIO_SetPinValue(RS_PORT,RS_PIN,LOW);
	Send_FallingEdge();
	_delay_ms(1);
}

void LCD_vWriteData(u8 data)
{
	DIO_SetPinValue(DIO_PORTA,Pin7,READ_BIT(data,7));
	DIO_SetPinValue(DIO_PORTA,Pin6,READ_BIT(data,6));
	DIO_SetPinValue(DIO_PORTA,Pin5,READ_BIT(data,5));
	DIO_SetPinValue(DIO_PORTA,Pin4,READ_BIT(data,4));
	DIO_SetPinValue(RS_PORT,RS_PIN,HIGH);
	Send_FallingEdge();
	_delay_ms(1);

	DIO_SetPinValue(DIO_PORTA,Pin7,READ_BIT(data,3));
	DIO_SetPinValue(DIO_PORTA,Pin6,READ_BIT(data,2));
	DIO_SetPinValue(DIO_PORTA,Pin5,READ_BIT(data,1));
	DIO_SetPinValue(DIO_PORTA,Pin4,READ_BIT(data,0));
	DIO_SetPinValue(RS_PORT,RS_PIN,HIGH);
	Send_FallingEdge();
	_delay_ms(1);
}

