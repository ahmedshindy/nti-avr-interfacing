#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "USART_interface.h"

int main ()
{
    LCD_vInit();
    USART_vInit();
    u8 x;
    u8 Hi = 'H';
    u8 bye = 'B';
    u8* name = "Ahmed";
    
    while(1)
    {
        x=UART_u8ReceiveData();
        LCD_vWriteData(x);
    }

}