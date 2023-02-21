#include "DIO_private.h"
#include "DIO_interface.h"




void DIO_SetPinDir(PORT_TYPE Copy_u8Port, PIN_TYPE Copy_u8Pin, MODE_TYPE Copy_u8Mode)
{
    switch (Copy_u8Port)
    {
    case DIO_PORTA:
        if(Copy_u8Mode == INPUT)
        {
            DDRA &=~(1U << Copy_u8Pin);
        }
        else if (Copy_u8Mode == OUTPUT) 
        {
            DDRA |=(1<<Copy_u8Pin);
        }
        else { /*MISRA*/}
        break;
    case DIO_PORTB:
        if(Copy_u8Mode == INPUT)
        {
            DDRB &=~(1U << Copy_u8Pin);
        }
        else if (Copy_u8Mode == OUTPUT) 
        {
            DDRB |=(1<<Copy_u8Pin);
        }
        else { /*MISRA*/}
        
        break;
    case DIO_PORTC:
        if(Copy_u8Mode == INPUT)
        {
            DDRC &=~(1U << Copy_u8Pin);
        }
        else if (Copy_u8Mode == OUTPUT) 
        {
            DDRC |=(1<<Copy_u8Pin);
        }
        else { /*MISRA*/}
        break;
    case DIO_PORTD:
        if(Copy_u8Mode == INPUT)
        {
            DDRD &=~(1U << Copy_u8Pin);
        }
        else if (Copy_u8Mode == OUTPUT) 
        {
            DDRD |=(1<<Copy_u8Pin);
        }
        else { /*MISRA*/}
        break;
    default:
        /*generate Error_Stat (Recommended)*/
        break;
    }
}
void DIO_SetPinValue(PORT_TYPE Copy_u8Port, PIN_TYPE Copy_u8Pin, MODE_TYPE Copy_u8Mode)
{
    switch (Copy_u8Port)
    {
    case DIO_PORTA:
        if(Copy_u8Mode == LOW)
        {
            PORTA &=~(1U << Copy_u8Pin);
        }
        else if (Copy_u8Mode == HIGH) 
        {
            PORTA |=(1<<Copy_u8Pin);
        }
        else { /*MISRA*/}
        break;
    case DIO_PORTB:
        if(Copy_u8Mode == LOW)
        {
            PORTB &=~(1U << Copy_u8Pin);
        }
        else if (Copy_u8Mode == HIGH) 
        {
            PORTB |=(1<<Copy_u8Pin);
        }
        else { /*MISRA*/}
        break;
    case DIO_PORTC:
        if(Copy_u8Mode == LOW)
        {
            PORTC &=~(1U << Copy_u8Pin);
        }
        else if (Copy_u8Mode == HIGH) 
        {
            PORTC |=(1<<Copy_u8Pin);
        }
        else { /*MISRA*/}
        break;
    case DIO_PORTD:
        if(Copy_u8Mode == LOW)
        {
            PORTD &=~(1U << Copy_u8Pin);
        }
        else if (Copy_u8Mode == HIGH) 
        {
            PORTD |=(1<<Copy_u8Pin);
        }
        else { /*MISRA*/}
        break;
    default:
        /*generate Error_Stat (Recommended)*/
        break;
    }
}

u8 Dio_GetPinValue(PORT_TYPE PortNumber,PIN_TYPE PinNumber )
{
    u8 Return_value =0;
    switch (PortNumber)
    {
    case DIO_PORTA:
        Return_value = ( PINA &=(1U<<PinNumber));
        break;
    case DIO_PORTB:
        Return_value = ( PINB&=(1U<<PinNumber));
        break;
    case DIO_PORTC:
        Return_value = ( PINC&=(1U<<PinNumber));
        break;
    case DIO_PORTD:
        Return_value = ( PIND &=(1U<<PinNumber));
        break;
    default:
        /*generate Error_Stat (Recommended)*/
        break;
    } 
    
    return Return_value;
}

void Set_InputPullUp(PORT_TYPE portNumber,PIN_TYPE PinNumber)
{
    switch (portNumber)
    {
    case DIO_PORTA:
        DDRA &=~(1U << PinNumber);
        PORTA |=(1<<PinNumber);
        break;

    case DIO_PORTB:
        DDRB &=~(1U << PinNumber);
        PORTB |=(1<<PinNumber);
        break;

    case DIO_PORTC:
        DDRC &=~(1U << PinNumber);
        PORTC |=(1<<PinNumber);
        break;

    case DIO_PORTD:
        DDRD &=~(1U << PinNumber);
        PORTD |=(1<<PinNumber);
        break;

    default: /*generate Error_Stat (Recommended)*/ break;
    }
}
void DIO_TogglePinValue(PORT_TYPE PortNumber,PIN_TYPE PinNumber)
{
    switch (PortNumber)
    {
    case DIO_PORTA:
    PORTA ^=(1U << PinNumber);
    break;

    case DIO_PORTB:
        PORTB ^=(1U<<PinNumber);
        break;

    case DIO_PORTC:
        PORTC ^=(1U<<PinNumber);
        break;

    case DIO_PORTD:
        PORTD ^=(1U<<PinNumber);
        break;

    default: /*generate Error_Stat (Recommended)*/ break;
    }
}