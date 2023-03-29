/*
 * LCD_test.c
 * Created: 2/17/2023 12:39:40 PM
 * Author : Ahmed Shindy
 */
#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include "LCD_interface.h"
#include "util/delay.h"



int main()
{
	Keypad_vInit();
	LCD_vInit();
	
	// LCD_vWriteCommand(0x0e); // CMD_CURSOR_ON_DISPLAN_ON
	// LCD_vWriteData('A');
	// _delay_ms(100);
	// LCD_vWriteData('B');
	// _delay_ms(100);
	LCD_vWriteString("Ahmed Shindy");
	while(1);
}
