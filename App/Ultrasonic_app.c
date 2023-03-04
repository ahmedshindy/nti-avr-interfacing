
#define  F_CPU 8000000UL

#include "STD_TYPES.h"
#include "STD_macros.h"
#include "DIO_interface.h"
#include "Timer_interface.h"
#include "avr/interrupt.h"


int main()
{
    Timer1_InitICU();
}