// #define  F_CPU 8000000UL
#define     F_CPU       16000000UL

#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "USART_interface.h"
#include "FingPrint_config.h"
#include "FingPrint_interface.h"
#include "util/delay.h"
volatile u8 data_recieved = 0x00;
volatile u8 data_sent = 0x00;



//verify password command
const u8 VfyPwd[]={0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x07, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B};
//get image command(GenImg)
const u8 GenImg[]={0xEF, 0x1, 0xFF, 0xFF, 0xFF, 0xFF, 0x1, 0x0, 0x3, 0x1, 0x0, 0x5};
//converts image to character file and stores it in buffer 1(Img2TZ)
const u8 Img2Char1[]={0xEF, 0x1, 0xFF, 0xFF, 0xFF, 0xFF, 0x1, 0x0, 0x4, 0x2, 0x1, 0x0, 0x8};
//converts image to character file and stores it in buffer 2
const u8 Img2Char2[]={0xEF, 0x1, 0xFF, 0xFF, 0xFF, 0xFF, 0x1, 0x0, 0x4, 0x2, 0x2, 0x0, 0x9};
//combines character files in buffer 1 and buffer 2 into a template and stores it in both buffer 1 and bufer 2 (generate template)
const u8 RegModel[]={0xEF, 0x1, 0xFF, 0xFF, 0xFF, 0xFF, 0x1, 0x0, 0x3, 0x5, 0x0, 0x9};
//stores the template in the sensor internal flash (store)
u8 f_storeModel[]={0xEF, 0x1, 0xFF, 0xFF, 0xFF, 0xFF, 0x1, 0x0, 0x6, 0x6, 0x1, 0x0, 0x1, 0x0, 0xF};
//searches the library to find the template that matches with the character file stored in buffer 1
const u8 f_search[]={0xEF, 0x1, 0xFF, 0xFF, 0xFF, 0xFF, 0x1, 0x0, 0x8, 0x4, 0x1, 0x0, 0x1, 0x0, 0xD, 0x0, 0x1C};
	//sets the configurations of the aura LED
//u8 f_auraLED[]={0xEF, 0x1, 0xFF, 0xFF, 0xFF, 0xFF, 0x1, 0x0, 0x7, 0x35, LED_CTRL, LED_SPD, LED_COLOR, LED_TIMES, 0x0, 0x3D};
u8 f_auraLED[]={0xEF, 0x1, 0xFF, 0xFF, 0xFF, 0xFF, 0x1, 0x0, 0x7, 0x35, LED_CTRL, LED_SPD, LED_COLOR, LED_TIMES, 0x0, 0x3D};




u8 RecivedData [30];


int main()
{
    LCD_vInit();
    USART_vInit(); // baud 57600

    LCD_vWriteString("Test");
    _delay_ms(500);
    USART_Tx_Buffer(VfyPwd,16);

    u16 LedSum = 0x3D + LED_COLOR + LED_CTRL + LED_SPD + LED_TIMES;
    f_auraLED[14]= LedSum >>8;
    f_auraLED[15] = (u8) LedSum;

    _delay_ms(2000);
        USART_Tx_Buffer(f_auraLED,16);

    USART_Rx_Buffer(RecivedData,16);
    LCD_vWriteCommand(LCD_vClearScreen);
    _delay_ms(200);
    LCD_vWriteString("Done!");
    while (1)
    {
        /* code */
    }
    

}


// this version works with interrupts
int main_three()
{
    LCD_vInit();
    USART_vInit(); // baud 57600
    // USART_u8ReceiveData_Asynch(RX_data,6);

    LCD_vWriteString("Finger Print");
    _delay_ms(500);
    USART_vSendData_Asynch(VfyPwd,16);


    u16 LedSum = 0x3D + LED_COLOR + LED_CTRL + LED_SPD + LED_TIMES;
    f_auraLED[14]= LedSum >>8;
    f_auraLED[15] = (u8) LedSum;

    volatile u8 buffers_count =0;
    while(1)
    {
        // do your job and
        if(data_sent == 0x01)
        {
            LCD_vWriteString("Sent ");
            data_sent = 0;
            buffers_count++;
            if(buffers_count == 1)
            {
                LCD_vWriteCommand(LCD_vClearScreen);
                LCD_vWriteString("done twice");
                _delay_ms(500);
                break;
            }
            USART_vSendData_Asynch(f_auraLED,16);
            // USART_u8ReceiveData_Asynch(RecivedData,16);
        }

        // if(data_recieved == 0x01)
        // {
        //     LCD_vWriteString(",Recieved ");
        //     data_recieved = 0;
        // }
    }

    while (1)
    {
        // stop here
    }
    

}



int main_one ()
{
    LCD_vInit();
    USART_vInit();
    // USART_u8ReceiveData_Asynch(RX_data,6);

    _delay_ms(500);
    USART_vSendData_Asynch(VfyPwd,16);

    while(1)
    {
        // do your job and
        if(data_sent == 0x01)
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