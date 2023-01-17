#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_



#define NULL   (void *)0

#define EXTI_u8_MCUCR    *((volatile u8*)(0x55))
#define EXTI_u8_MCUCSR   *((volatile u8*)(0x54))
#define EXTI_u8_SREG     *((volatile u8*)(0x5F))
#define EXTI_u8_GICR     *((volatile u8*)(0x5B))
#define EXTI_u8_GIFR     *((volatile u8*)(0x5A))

void __vector_1(void)__attribute__((signal,used));
void __vector_2(void)__attribute__((signal,used));
void __vector_3(void)__attribute__((signal,used));

#endif /* EXTI_PRIVATE_H_ */

