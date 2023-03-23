#define F_CPU		16000000UL
#include "STD_TYPES.h"
#include "I2C_private.h"
#include "I2C_interface.h"
#include "LCD_interface.h"
#include "Ext_EEPROM_config.h"
#include "Ext_EEPROM_interface.h"



void EEPROM_Init(void)
{
	TWI_INIT();
}

/* this will write the data to address 0*/
void EEPROM_SaveData(u8 pageNum, u8 byte_address, u8 data)
{ 
	TWI_INIT();
	_delay_ms(500);
	TWI_WriteStartCond(); // transmit start condition // 0x00a0
	u8 var = (DEVICE_ADDRESS | pageNum) & 0xFE;
	// transmit device address and Write
	TWI_WriteSlaveAdd_With_Op(var,I2C_WRITE); 
	TWI_WriteData(byte_address); // transmit word address
	
	TWI_WriteData(data); // transmit data
	TWI_WriteStopCond(); // transmit stop condition
	_delay_ms(200);
}


u8 EEPROM_ReadData(u8 pageNumber, u8 byte_address)
{
	u8 data = 0;
	TWI_WriteStartCond(); // transmit start condition
	u8 var = (DEVICE_ADDRESS | pageNumber) & 0xFE;
	TWI_WriteSlaveAdd_With_Op(var,I2C_WRITE);// transmit device address and Write
	TWI_WriteData(byte_address); // transmit word address
	TWI_WriteRepStartCond(); // transmit repeated start condition
	TWI_WriteSlaveAdd_With_Op(var,I2C_READ); // transmit device address and read
	data=TWI_ReadData_Write_ACK();


	TWI_WriteStopCond();
	return data;
}