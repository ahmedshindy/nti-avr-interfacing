#define     F_CPU       8000000UL
// #define     F_CPU       16000000UL
#include "USART_interface.h"
#include "avr/interrupt.h"

extern volatile u8 data_recieved;
extern volatile u8 data_sent;
volatile u32 Tx_Size;
volatile u32 Rx_size;

u8* Tx_buffer= NULL;  
u8* Rx_buffer = NULL;   

void USART_vInit()
{
    #if (BAUD_RATE == 9600UL)
    u16 Local_UBBR;
    Local_UBBR = ((F_CPU)/(16*BAUD_RATE)) -1;
    UBRRH = ((u8)(Local_UBBR>>8));
    UBRRL = (u8) Local_UBBR;

    #endif

    #if (PARITY == NO_PARITY)
    // do nothing for now (recommended doing manually)
    #endif

    #if (STOP_BITS == 2)
        SET_BIT(UCSRC,USBS);
    #endif


    #if (FRAME_LENGTH == 8)
        SET_BIT(UCSRC,UCSZ0);
        SET_BIT(UCSRC,UCSZ1);

    #endif

    // enable send/recieve
    SET_BIT(UCSRB,RXEN);
    SET_BIT(UCSRB,TXEN);
}
void USART_vSendData_Synch(u8 data)
{
    // wait for the transmit reg to be empty
    while(READ_BIT(UCSRA,UDRE)==0);
    UDR = data;
}
u8 USART_u8ReceiveData_Synch(void)
{
    // wait for the recieve reg to be filled
    while(READ_BIT(UCSRA,RXC)==0);
    return UDR;
}
void USART_vSendString( u8 *ptr)
{
    for( ; *ptr; ptr++)
    {
        USART_vSendData_Synch(*ptr);
    }
return;
}



/*** Asynchronous Functions ****/
void USART_vSendData_Asynch(u8* data, u32 size)
{
    // enable Tx interrupts & global interrupts
    sei();
    SET_BIT(UCSRB,TXCIE);
    Tx_Size= size;
    Tx_buffer = data;
    while(READ_BIT(UCSRA,UDRE)==0);
    UDR = data[0];
}
void USART_u8ReceiveData_Asynch(u8* data, u32 size)
{
    // enable Rx interrupts & global interrupts
    sei();
    SET_BIT(UCSRB,RXCIE);
    Rx_buffer = data;
    Rx_size = size;    
}
// not required
// void USART_vSendString_Asynch( u8 *ptr,u32 size )
// {
// }


/**
 * @brief Construct a new ISR object
 * 
 * 
 */

/*** transmit interrupt handler */
ISR(USART_TXC_vect)
{
    Tx_Size--;
    static u32 counter =1;
    if(Tx_Size == 0)
    {
        CLR_BIT(UCSRB,TXCIE);
        data_sent =0x01;
        cli();
    }
    else if(Tx_buffer != NULL)
    {
        UDR = Tx_buffer[counter];
        counter ++;
    }

}


/** recive interrupt handler */
ISR(USART_RXC_vect)
{
    static u32 counter =0;
    if(counter == 5)
    {
        data_sent= 1;
        CLR_BIT(UCSRB,RXCIE);
        cli();
    }
    if(Rx_size == 0)
    {
        data_sent= 0x01;
        // disable usart interrupts & return
        CLR_BIT(UCSRB,RXCIE);
        cli();
    }
    else if(Rx_buffer != NULL)
    {
        Rx_buffer[counter] = UDR;
        counter ++;
        Rx_size --;
    }
}