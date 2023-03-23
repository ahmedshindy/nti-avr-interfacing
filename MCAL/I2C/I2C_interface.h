#ifndef I2C_INTERFACE
#define I2C_INTERFACE
#include "STD_TYPES.h"

#include "I2C_private.h"
#include "I2C_config.h"

#define I2C_READ            0x01
#define I2C_WRITE           0x00

void TWI_INIT(void);
void TWI_WriteStartCond(void);
void TWI_WriteRepStartCond(void);
void TWI_WriteStopCond(void);

void TWI_WriteSlaveAdd_With_Op(u8 SLA_Add, u8 Operation);
void TWI_WriteData(u8 Data);
u8  TWI_ReadData_Write_NACK(void);
u8  TWI_ReadData_Write_ACK(void);






void TWI_WriteMultiData(u8* Data, u8 Data_Size);
void TWI_WriteString(u8* Data, u8 Data_Size);
void TWI_ReadMultiData(u8* Data, u8 Data_Size);
#endif