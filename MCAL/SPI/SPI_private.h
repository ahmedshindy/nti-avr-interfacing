/**@brief 
 * this is the mcu register file for spi peripheral
 * 
 * 
*/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR       (*((volatile u8* )0x2D))
#define SPSR        (*((volatile u8* )0x2E))
#define SPDR        (*((volatile u8* )0x2F))

/* SPSR */
#define SPIF    7
#define WCOL    6
/* bits 5-1 reserved */
#define SPI2X   0

/* SPCR */
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0


#endif