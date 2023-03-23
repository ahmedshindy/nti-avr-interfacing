#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


#include "USART_config.h"
#include "USART_private.h"
#include "STD_macros.h"
#include "STD_TYPES.h"



void USART_vInit();
void USART_vSendData_Synch(u8 data);

void USART_Tx_Buffer(u8* buf , u8 buf_len);
void USART_Rx_Buffer(u8* buf , u8 buf_len);


u8 USART_u8ReceiveData_Synch(void);
void USART_vSendString( u8 *ptr);


/*** Asynchronous ****/
void USART_vSendData_Asynch(u8* data, u32 size);
void USART_u8ReceiveData_Asynch(u8* data, u32 size);
void USART_vSendString_Asynch( u8 *ptr, u32 size );

#endif