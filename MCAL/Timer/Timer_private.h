

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/* TCCR0 */
#define     TCCR0_Reg               (*((volatile u8*)(0x53)))
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

#define     TCNT0_Reg               (*((volatile u8*)(0x52)))
#define     OCR0_Reg                (*((volatile u8*)(0x5C)))              
/* TIMSK_Reg */
#define     TIMSK_Reg               (*((volatile u8*)(0x59)))
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

#define     TIFR_Reg                (*((volatile u8*)(0x58)))
/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0


/***TIMER1 ***/
#define TCCR1A   (*((volatile u8*)0x4F)) // COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10 107
/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0



/* TCCR1B */
#define TCCR1B   (*((volatile u8*)0x4E)) // ICNC1 ICES1 � WGM13 WGM12 CS12 CS11 CS10 110
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

#define TCNT1H   (*((volatile u8*)0x4D)) // Timer/Counter1 � Counter Register High Byte 111
#define TCNT1L   (*((volatile u8*)0x4C)) // Timer/Counter1 � Counter Register Low Byte 111
//#define OCR1AH   *((volatile u8*)4B) // Timer/Counter1 � Output Compare Register A High Byte 111
#define OCR1AL   (*((volatile u16*)0x4A)) // Timer/Counter1 � Output Compare Register A Low Byte 111
#define OCR1BH   (*((volatile u8*)0x49)) // Timer/Counter1 � Output Compare Register B High Byte 111
#define OCR1BL   (*((volatile u16*)0x48)) // Timer/Counter1 � Output Compare Register B Low Byte 111
//#define ICR1H    *((volatile u8*)47) //Timer/Counter1 � Input Capture Register High Byte 111

// typedef enum {OCIE2, TOIE2, TICIE1, OCIE1A, OCIE1B, TOIE1, OCIE0, TOIE0}TIMSK_Pin;

/* Timer 1 */
#define ICR1     (*((volatile u16*)0x26))
#define ICR1L    (*((volatile u8*)0x26))
#define ICR1H    (*((volatile u8*)0x27))


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


#define T1_Mode_Normal              0x00

#endif