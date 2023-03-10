/**SPI configurations */


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#define LSB_FIRST	0
#define MSB_FIRST	1

#define DATA_ORDER	MSB_FIRST


#define POL		IDLE_LOW

#define SAMPLE_LEADING		0
#define SAMPLE_TRAILING		1

#define CLK_PHASE	SAMPLE_LEADING

#define FOSC_div_4		0
#define FOSC_div_16		1
#define FOSC_div_64		2
#define FOSC_div_128	3

#define CLK_PRESCALAR	FOSC_div_16


#endif