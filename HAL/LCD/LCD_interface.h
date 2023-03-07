/*
 * LCD_interface.h
 *
 * Created: 2/18/2023 7:29:13 PM
 *  Author: Ahmed Shindy
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_vInit(void);
void LCD_vWriteCommand(u8 cmd);
void LCD_vWriteData(u8 data);
void LCD_vSendString(u8 *data);
void LCD_vClearScreen();
void LCD_MoveCursor(u8 row,u8 coloumn);
void LCD_vWriteString(char * Str);
void LCD_WriteNUM(u32 NUM);



#endif /* LCD_INTERFACE_H_ */