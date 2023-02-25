/*
 * EX_INT_private.h
 *
 * Created: 2/24/2023 7:49:47 AM
 *  Author: Ahmed Shindy
 */ 

#ifndef EX_INT_PRIVATE_H
#define EX_INT_PRIVATE_H

// attribbutes and signals? , SimulIDE, parameters in the callback


#define  MCUCR_PORT		(*((volatile u8*) (0x55)))
#define  MCUSCR_PORT		(*((volatile u8*) (0x54)))

#define GIFR_PORT		(*((volatile u8*) (0x5A)))
#define GICR_PORT		(*((volatile u8*) (0x5B)))


#endif
