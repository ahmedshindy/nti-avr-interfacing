/*
 * LCD_private.h
 *
 * Created: 2/18/2023 9:05:28 PM
 *  Author: Ahmed Shindy
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define FuncitonSet1						0x33
#define FuncitonSet2						0x32
#define CMD_CLEAR_DISPLAY					0x01
#define CMD_CURSOR_ON_DISPLAN_ON			0x0e
#define CMD_RETURN_HOME						0x02
#define CMD_ENTRY_MODE						0x06

#define LCD_4_Bit_Mode_2_Line_5_8_Dots		0x28
#define Display_Cursor_ON_Blink_OFF			0x0E
#define Clear_Display_Screen				0x01
#define Shift_Cursor_Right_Per_Read_Write	0x06



static void Send_FallingEdge(void);





#endif /* LCD_PRIVATE_H_ */