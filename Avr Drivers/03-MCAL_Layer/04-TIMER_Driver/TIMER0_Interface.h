
#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


//Clk Src Values In TCCR0
#define TIMER0_INTERNAL_CLK_NO_PRE          0b001
#define TIMER0_INTERNAL_CLK_PRE_8           0b010
#define TIMER0_INTERNAL_CLK_PRE_64          0b011
#define TIMER0_INTERNAL_CLK_PRE_256         0b100
#define TIMER0_INTERNAL_CLK_PRE_1024        0b101
#define TIMER0_EXTERNAL_CLK_FALLING         0b110
#define TIMER0_EXTERNAL_CLK_RISING          0b111

//Operation Modes Values In TCCR0
#define TIMER0_NORMAL_MODE                  0b00
#define TIMER0_PHASECORRECT_PWM_MODE        0b01
#define TIMER0_CTC_MODE                     0b10
#define TIMER0_FAST_PWM_MODE                0b11

//Compare Output Modes Values In Normal / CTC MODES
#define TIMER0_NO_OC0            0b00
#define TIMER0_TOGGLE_OC0        0b01
#define TIMER0_CLEAR_OC0         0b10
#define TIMER0_SET_OC0           0b11

//Compare Output Modes Values In Fast PWM
#define TIMER0_NO_OC0            0b00
#define TIMER0_NON_INV_MODE      0b10 //Clear OC0 on compare match, set OC0 at TOP
#define TIMER0_INV_MODE          0b11 //Set OC0 on compare match, clear OC0 at TOP

//Compare Output Modes Values In Phase Correct PWM
#define TIMER0_NO_OC0            0b00
#define TIMER0_NON_INV_MODE      0b10 //Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
#define TIMER0_INV_MODE          0b11 //Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.

//Interrupts
#define DISABLE                0
#define ENABLE                 1
#define TIMER0_OV_INT          0
#define TIMER0_CM_INT          1

//Functions Prototypes
void TIMER0_void_INIT(u8 Copy_u8_Clk_Src,u8 Copy_u8_Operation_Mode,u8 Copy_u8_Compare_Output_Mode);

void TIMER0_void_START_NORMAL(u8 Copy_u8_Preload_Value);
void TIMER0_void_START_CTC(u8 Copy_u8_OCR_Value);
void TIMER0_void_START_FAST_PWM(u8 Copy_u8_OCR_Value);
void TIMER0_void_START_PHASECORRECT_PWM(u8 Copy_u8_OCR_Value);


void TIMER0_void_INTERRUPT_ENABLE_DISABLE(u8 Copy_u8_Type, u8 Copy_u8_State);
void TIMER0_void_OVERFLOW_INTERRUPT(void (* Copy_void_Callback_OV_Ptr)(void));
void TIMER0_void_COMPARE_MATCH_INTERRUPT(void (* Copy_void_Callback_CM_Ptr)(void));


#endif
