#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "USART_interface.h"

u8* RX_data= "fff";
int main ()
{
    LCD_vInit();
    USART_vInit();
    u8 x;
   
    while(1)
    {
        USART_u8ReceiveData_Asynch(RX_data,3);
        LCD_vWriteData(RX_data);
    }

}