#include "STD_macros.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "DIO_interface.h"


void SPI_MasterInit(void)
{
    /*Set SS / MOSI / SCK  as output pins for master*/
	DIO_SetPinDir(DIO_PORTB,Pin4,OUTPUT);
	DIO_SetPinDir(DIO_PORTB,Pin5,OUTPUT);
	DIO_SetPinDir(DIO_PORTB,Pin7,OUTPUT);

	/*Enable Master mode*/
	SET_BIT(SPCR,MSTR);
	/*Set clock to fosc/16*/
    #if (CLK_PRESCALAR == FOSC_div_16)
	SET_BIT(SPCR,SPR0);
    #endif
	/*Enable SPI*/
    SET_BIT(SPCR,SPE);
	/*set SS to high */
	DIO_SetPinValue(DIO_PORTB,Pin4,HIGH);
}
void SPI_SlaveInit(void)
{
    /*Enable SPI*/
	SET_BIT(SPCR,SPE);
	/*Set MISO as output*/
	DIO_SetPinDir(DIO_PORTB,Pin6,OUTPUT);
}

u8 SPI_TransReceive(u8 data)
{
    /*Clear SS to send data to slave*/
	DIO_SetPinValue(DIO_PORTB,Pin4,LOW);

	/*Put data on SPDR*/
	SPDR=data;
	/*Wait until the transmission is finished polling */
    while(READ_BIT(SPSR,SPIF)==0);
	/*read SPDR*/
	return SPDR ;
}