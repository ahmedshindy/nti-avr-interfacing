#define F_CPU   16000000UL

#include "I2C_interface.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Ext_EEPROM_interface.h"
#include "Ext_EEPROM_config.h"
#include "util/delay.h"



int main(void)
{
	LCD_vInit();
	LCD_vWriteString("Hi Man!");
	u8 X;
	EEPROM_Init();
	u8 eeData[]= {'H','e','l','l','o'};
	int i=0;
	EEPROM_SaveData(0,0,'A');
	_delay_ms(50);
	
	

	LCD_vWriteString("clear lcd");
	_delay_ms(100);
	LCD_vWriteCommand(0x01); 

	_delay_ms(3000);
	

	X= EEPROM_ReadData(0x00,0x00);
	_delay_ms(1000);

	LCD_vWriteString("EEPROM Read= ");
	LCD_vWriteData(X);
	while(1);
}