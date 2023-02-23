/*
    file    :    DIO_interface.h
    author  :    Ahmed Shindy
    description:
*/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

typedef enum{DIO_PORTA,DIO_PORTB, DIO_PORTC, DIO_PORTD} PORT_TYPE;
typedef enum{LOW, HIGH , INPUT, OUTPUT} MODE_TYPE;
typedef enum {Pin0, Pin1, Pin2, Pin3, Pin4, Pin5, Pin6,Pin7}PIN_TYPE;


void DIO_SetPinDir(PORT_TYPE, PIN_TYPE, MODE_TYPE);
void DIO_SetPinValue(PORT_TYPE,PIN_TYPE,MODE_TYPE);

u8 Dio_GetPinValue(PORT_TYPE,PIN_TYPE);
void Set_InputPullUp(PORT_TYPE,PIN_TYPE);
void DIO_TogglePinValue(PORT_TYPE,PIN_TYPE);

#endif