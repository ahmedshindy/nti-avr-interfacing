#define F_CPU   16000000UL

#include "STD_TYPES.h"
#include "STD_macros.h"
#include "I2C_interface.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Ext_EEPROM_interface.h"
#include "util/delay.h"

int main()
{
	LCD_vInit();
	LCD_vWriteString("Hi I2C!");
    TWI_INIT();
    TWI_WriteStartCond();
    TWI_WriteSlaveAdd_With_Op(0x52,I2C_WRITE);
    TWI_WriteData(0x77);

    TWI_WriteStopCond();

    while (1);
    
    
}