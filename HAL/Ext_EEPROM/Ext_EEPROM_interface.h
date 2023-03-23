#ifndef EXT_EEPROM_INTERFACE_H_
#define EXT_EEPROM_INTERFACE_H_ 

#include "STD_TYPES.h"
#include "LCD_interface.h"
#include <util/delay.h>



/*some addresses of EEPROM*/
#define  u16ADDRESS_00		0xA000
#define  u16ADDRESS_01		0xA001
#define  u16ADDRESS_02		0xA002
#define  u16ADDRESS_03		0xA003
#define  u16ADDRESS_04		0xA004
void EEPROM_Init(void);
void EEPROM_SaveData( u8 pageNum, u8 byte_address, u8 data);
u8 EEPROM_ReadData(u8 pageNumber, u8 byte_address);
#endif