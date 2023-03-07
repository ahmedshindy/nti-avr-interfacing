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
	DIO_SetPinDir(DIO_PORTB,Pin0,OUTPUT);
	DIO_SetPinDir(DIO_PORTB,Pin1,OUTPUT);
	DIO_SetPinDir(DIO_PORTB,Pin2,OUTPUT);
	DIO_SetPinDir(DIO_PORTB,Pin4,OUTPUT);

	DIO_SetPinDir(RS_PORT,RS_PIN,OUTPUT);
	DIO_SetPinDir(EN_PORT,EN_PIN,OUTPUT);
	DIO_SetPinDir(RW_PORT,RW_PIN,OUTPUT);

	// always RW=0 low as it is on the kit, I will be always reading for now
	DIO_SetPinValue(RW_PORT,RW_PIN,LOW); 
	// 02 , 28, 0x0e , 0x01 0x06
	// delays 10, 1, 1, 10 1 ms
	// LCD_vWriteCommand(0x02);
	// _delay_ms(10);
	// LCD_vWriteCommand(0x28);
	// _delay_ms(1);
	// LCD_vWriteCommand(0x0e);
	// _delay_ms(1);
	// LCD_vWriteCommand(0x01);
	// _delay_ms(10);
	// LCD_vWriteCommand(0x06);
	// _delay_ms(1);
	
	LCD_vWriteCommand(FuncitonSet1); // 0x33 ==> 28
	_delay_ms(10);
	LCD_vWriteCommand(FuncitonSet2); // 0x32
	_delay_ms(1);
	LCD_vWriteCommand(LCD_4_Bit_Mode_2_Line_5_8_Dots); // 0x28
	_delay_ms(1);
	LCD_vWriteCommand(Display_Cursor_ON_Blink_OFF);  // 0x0E
	_delay_ms(1);
	LCD_vWriteCommand(Clear_Display_Screen); //0x01
	_delay_ms(10);
	LCD_vWriteCommand(Shift_Cursor_Right_Per_Read_Write); //0x06
	_delay_ms(1);
}


static void Send_FallingEdge(void)
{
	// EN =1, delay 2ms , EN=0, delay 2ms, exit
	DIO_SetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	_delay_ms(2);
}


void LCD_vWriteString(char * Str)
{
	int i=0;
	while (Str[i] != '\0')
	{
		LCD_vWriteData(Str[i]);
		i++;
		_delay_ms(100);
	}
	
}


void LCD_vWriteCommand(u8 cmd)
{
	DIO_SetPinValue(DIO_PORTB,Pin4,READ_BIT(cmd,7));
	DIO_SetPinValue(DIO_PORTB,Pin2,READ_BIT(cmd,6));
	DIO_SetPinValue(DIO_PORTB,Pin1,READ_BIT(cmd,5));
	DIO_SetPinValue(DIO_PORTB,Pin0,READ_BIT(cmd,4));
	DIO_SetPinValue(RS_PORT,RS_PIN,LOW);
	Send_FallingEdge();
	_delay_ms(1);
	
	DIO_SetPinValue(DIO_PORTB,Pin4,READ_BIT(cmd,3));
	DIO_SetPinValue(DIO_PORTB,Pin2,READ_BIT(cmd,2));
	DIO_SetPinValue(DIO_PORTB,Pin1,READ_BIT(cmd,1));
	DIO_SetPinValue(DIO_PORTB,Pin0,READ_BIT(cmd,0));
	DIO_SetPinValue(RS_PORT,RS_PIN,LOW);
	Send_FallingEdge();
	_delay_ms(1);
}

void LCD_vWriteData(u8 data)
{
	// DIO_SetPinValue(DIO_PORTA,Pin7,READ_BIT(data,7));
	// DIO_SetPinValue(DIO_PORTA,Pin6,READ_BIT(data,6));
	// DIO_SetPinValue(DIO_PORTA,Pin5,READ_BIT(data,5));
	// DIO_SetPinValue(DIO_PORTA,Pin4,READ_BIT(data,4));
	DIO_SetPinValue(DIO_PORTB,Pin4,READ_BIT(data,7));
	DIO_SetPinValue(DIO_PORTB,Pin2,READ_BIT(data,6));
	DIO_SetPinValue(DIO_PORTB,Pin1,READ_BIT(data,5));
	DIO_SetPinValue(DIO_PORTB,Pin0,READ_BIT(data,4));

	DIO_SetPinValue(RS_PORT,RS_PIN,HIGH);
	Send_FallingEdge();
	_delay_ms(1);

	// DIO_SetPinValue(DIO_PORTA,Pin7,READ_BIT(data,3));
	// DIO_SetPinValue(DIO_PORTA,Pin6,READ_BIT(data,2));
	// DIO_SetPinValue(DIO_PORTA,Pin5,READ_BIT(data,1));
	// DIO_SetPinValue(DIO_PORTA,Pin4,READ_BIT(data,0));
	DIO_SetPinValue(DIO_PORTB,Pin4,READ_BIT(data,3));
	DIO_SetPinValue(DIO_PORTB,Pin2,READ_BIT(data,2));
	DIO_SetPinValue(DIO_PORTB,Pin1,READ_BIT(data,1));
	DIO_SetPinValue(DIO_PORTB,Pin0,READ_BIT(data,0));
	DIO_SetPinValue(RS_PORT,RS_PIN,HIGH);
	Send_FallingEdge();
	_delay_ms(1);
}

LCD_vClearScreen()
{
	LCD_vWriteCommand(Clear_Display_Screen);
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
void LCD_MoveCursor(u8 row,u8 coloumn )
{
	u8 data ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	LCD_vWriteCommand(data);
	_delay_ms(1);
}
