#define F_CPU       8000000UL
#include "STD_macros.h"
#include "I2C_interface.h"


void TWI_INTI(void)
{
    TWBR= (u8) (((F_CPU/SCL_Clock)-16)/(2*SCL_PRESCALAR));
    #if (SCL_PRESCALAR == SCL_PRESCALAR_16)
        TWSR |= (0x02);
        // add other options
    #endif

}
void TWI_WriteStartCond(void)
{
    TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
}


void TWI_WriteRepStartCond(void)
{
    TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
}


void TWI_WriteStopCond(void)
{
    TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void TWI_WriteData(u8 Data)
{
    TWDR = Data;
    TWCR |= ((1<<TWINT) | (1<<TWEN) );
    while(READ_BIT(TWCR,TWINT)==0);
    // check status bits 
    while ((TWSR & 0xf8) != 0x08); 
}

// u8  TWI_ReadData_Write_NACK(void);
// u8  TWI_ReadData_Write_ACK(void);


// void TWI_WriteSlaveAdd_With_Op(u8 SLA_Add, u8 Operation)
// {

//     // //if(Operation == 1) // READ 1
//     // #if(MODE == MASTER_MODE)
//     // // do nothing 
//     // #else
//     // TWAR |=(SLA_Add<<1);
//     // #endif
// }

