/**@brief interface functions for spi*/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
#include "STD_TYPES.h"

void SPI_MasterInit(void);
void SPI_SlaveInit(void);

u8 SPI_TransReceive(u8 data);


#endif 