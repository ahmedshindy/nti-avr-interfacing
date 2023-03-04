

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H


#define     TCCR0_Reg               (*((volatile u8*)(0x53)))
#define     TCNT0_Reg               (*((volatile u8*)(0x52)))
#define     OCR0_Reg                (*((volatile u8*)(0x5C)))              
#define     TIMSK_Reg               (*((volatile u8*)(0x59)))
#define     TIFR_Reg                (*((volatile u8*)(0x58)))
/***TIMER1 */

#define TCCR1A   *((volatile u8*)0x4F) // COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10 107
#define TCCR1B   *((volatile u8*)0x4E) // ICNC1 ICES1 � WGM13 WGM12 CS12 CS11 CS10 110
#define TCNT1H   *((volatile u8*)0x4D) // Timer/Counter1 � Counter Register High Byte 111
#define TCNT1L   *((volatile u8*)0x4C) // Timer/Counter1 � Counter Register Low Byte 111
//#define OCR1AH   *((volatile u8*)4B) // Timer/Counter1 � Output Compare Register A High Byte 111
#define OCR1AL   (*((volatile u16*)0x4A)) // Timer/Counter1 � Output Compare Register A Low Byte 111
#define OCR1BH   (*((volatile u8*)0x49)) // Timer/Counter1 � Output Compare Register B High Byte 111
#define OCR1BL   (*((volatile u16*)0x48)) // Timer/Counter1 � Output Compare Register B Low Byte 111
//#define ICR1H    *((volatile u8*)47) //Timer/Counter1 � Input Capture Register High Byte 111

typedef enum {OCIE2, TOIE2, TICIE1, OCIE1A, OCIE1B, TOIE1, OCIE0, TOIE0}TIMSK_Pin;
typedef enum {FOC0, WGM00 ,COM01, COM00, WGM01, CS02 ,CS01, CS00}TCCR0_Pins;


#define T0_Mode_Normal              0x00
#define T0_Mode_PhCorrPWM           0x01
#define T0_Mode_CTC                 0x02
#define T0_Mode_FastPWM             0x03


#define Normal_OC0 disconnected_NoPWM      0x00
#define Toggle_OC0_OnCompareMatch_NoPWM    0x01
#define Clear_OC0_OnCompareMatchNoPWM      0x02
#define Set_OC0_OnCompareMatchNoPWM        0x03


#define Normal_OC0 disconnected_NoPWM      0x00
#define Toggle_OC0_OnCompareMatch_NoPWM    0x01
#define Clear_OC0_OnCompareMatchNoPWM      0x02
#define Set_OC0_OnCompareMatchNoPWM        0x03


#endif