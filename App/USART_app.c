#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "USART_interface.h"
volatile u8 data_recieved = 0x00;
volatile u8 data_sent = 0x00;

u8 RX_data[10];
u8 TX_data[10]={'S','e','n','d','i','n','g'};
int main ()
{
    LCD_vInit();
    USART_vInit();





    USART_u8ReceiveData_Asynch(RX_data,6);

    while(1)
    {
        // do your job and
        if(data_recieved == 0x01)
        {
            LCD_vWriteString("Done");
            break;
        }
    }


    // /* Sender test, please activate only one portion */
    // USART_vSendData_Asynch(TX_data,5);

    // while(1)
    // {
    //     // do your job and
    //     if(data_sent == 0x01)
    //     {
    //         LCD_vWriteString("Sent");
    //         break;
    //     }
    // }




    // stop here
    while (1)
    {
        /* code */
    }
    

}