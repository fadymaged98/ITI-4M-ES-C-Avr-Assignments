#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

//Null Definition
#define Null    (void *)0

//Timer 0 Registers
#define TIMER_u8_TCCR0     *((volatile u8*)0x53)
#define TIMER_u8_TCNT0     *((volatile u8*)0x52)
#define TIMER_u8_TIMSK     *((volatile u8*)0x59)
#define TIMER_u8_OCR0      *((volatile u8*)0x5C)
#define TIMER_u8_SREG      *((volatile u8*)0x5F)
#define TIMER_u8_TIFR      *((volatile u8*)0x58)

//TCCR0 Bits
#define TCCR0_WGM01       3
#define TCCR0_WGM00       6
#define TCCR0_COM01       5
#define TCCR0_COM00       4

//ISR Prototypes
void __vector_11(void)__attribute__((signal,used));


#endif
