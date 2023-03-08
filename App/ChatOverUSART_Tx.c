
#define  F_CPU 8000000UL
 //#define  F_CPU 16000000UL

#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "USART_interface.h"

    u8 name[] = "Ahmed";
    u8 reply[];
    // u8 name[] = {'a','h','m','e','d','\0'};


int main ()
{
    LCD_vInit();
    USART_vInit();


        // LCD_vWriteData('A');
        USART_vSendString(name);
        LCD_vWriteString(name);
        // LCD_MoveCursor(2,1);
        //USART_vSendData_Synch(reply);
    
    while(1)
    {

        
    }

}