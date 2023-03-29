
#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "Timer_interface.h"
#include "Timer_private.h"
#include "LCD_interface.h"
#include "Ultrasonic.h"
#include "avr/interrupt.h"
#include <util/delay.h>

int main(void)
{
    LCD_vInit();
    u16 ICR_a, ICR_b, Loc_PulseWidth, loc_Distance;

    DIO_SetPinDir(TRIG_PORT,TRIG_PIN,OUTPUT);
    while (1)
    {
        TCCR1A = 0x00;
        /* Clear ICF (Input Capture flag)  */
        TIFR = (1 << ICF1); 
        DIO_SetPinValue(TRIG_PORT,TRIG_PIN,HIGH);
        _delay_us(50);
        DIO_SetPinValue(TRIG_PORT,TRIG_PIN,LOW);
        // Configure ICU, Rising edge, no prescaler , noise canceler on
        TCCR1B = 0xc1; 
        // poll on the flag for the rising edge
        while ((TIFR & (1 << ICF1)) == 0);
        ICR_a = ICR1; 

        // clear ICF flag          
        TIFR = (1 << ICF1);
        //configure ICU falling edge, no prescaler ,noise canceler
        TCCR1B = 0x81;      
        // poll on the flag once again.
        while ((TIFR & (1 << ICF1)) == 0);
        // read ICR once again
        ICR_b = ICR1;      
        // clear the flag     
        TIFR = (1 << ICF1);
        TCNT1 = 0;
        //stop the timer 
        TCCR1B = 0; 
        Loc_PulseWidth = ICR_b - ICR_a;
        loc_Distance = ((Loc_PulseWidth * 34600) / (F_CPU * 2));
        if (loc_Distance >= 80)
        {
          LCD_vWriteString("no object");
            _delay_ms(500);
        }
        else
        {
            LCD_vClearScreen();
            LCD_vWriteString("D(cm): ");
            LCD_vWriteData((loc_Distance / 10) + 48);
            LCD_vWriteData((loc_Distance % 10) + 48);
            _delay_ms(500);
        }
    }
}
