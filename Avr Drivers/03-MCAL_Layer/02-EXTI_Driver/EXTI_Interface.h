#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define EXTI_u8_EN           1
#define EXTI_u8_DIS          0

#define EXTI_u8_INT_0        0
#define EXTI_u8_INT_1        1
#define EXTI_u8_INT_2        2

#define EXTI_u8_LOW_LEVEL       0b00
#define EXTI_u8_IOC             0b01
#define EXTI_u8_FALLING_EDGE    0b10
#define EXTI_u8_RISING_EDGE     0b11

#define Loc_u8_INT2_Err         1

u8 EXTI_u8_Configure_Detection(u8 Copy_u8_Index,u8 Copy_u8_Detection);
void EXTI_void_EN_DIS(u8 Copy_u8_Index,u8 Copy_u8_Status);
void EXTI_void_EN_DIS_GLOBAL (u8 Copy_u8_Global_Status);

#endif /* EXTI_INTERFACE_H_ */
