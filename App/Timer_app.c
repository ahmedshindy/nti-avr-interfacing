
#define  F_CPU 8000000UL

#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "Timer_interface.h"
#include "avr/interrupt.h"

extern u32 Set_OVF_Glogal_count;


int main()
{

    Timer0_Init();

    Timer0_Start();

    DIO_SetPinDir(DIO_PORTB,Pin1,OUTPUT);
    DelayMs(1000);


    while (1)
    {
        /* code */
    }
    
    

    return 0;
}


ISR(TIMER0_OVF_vect)
{
   volatile static u32 counter =0;
    counter++;
    if(counter >= Set_OVF_Glogal_count)
    {
        counter =0;
        // toggle port B , bin 0
        DIO_TogglePinValue(DIO_PORTB,Pin1);
        
    }
}