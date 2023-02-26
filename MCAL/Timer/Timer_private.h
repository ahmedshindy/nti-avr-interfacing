

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H


#define     TCCR0_Reg               (*((volatile u8*)(0x53)))
#define     TCNT0_Reg               (*((volatile u8*)(0x52)))
#define     OCR0_Reg                (*((volatile u8*)(0x5C)))              
#define     TIMSK_Reg               (*((volatile u8*)(0x59)))
#define     TIFR_Reg                (*((volatile u8*)(0x58)))

#endif