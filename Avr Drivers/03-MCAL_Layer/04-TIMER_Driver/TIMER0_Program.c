#include "../My_STD_Libraries/STD_Types.h"
#include "../My_STD_Libraries/BIT_CALC.h"
#include "TIMER0_Config.h"
#include "TIMER0_Interface.h"
#include "TIMER0_Private.h"


//////////////// Global Variables ///////////////
static u8 Global_u8_Clk_Src;
void (* Global_void_OV_Ptr)(void) = Null;
void (* Global_void_CM_Ptr)(void) = Null;





void TIMER0_void_INIT(u8 Copy_u8_Clk_Src,u8 Copy_u8_Operation_Mode,u8 Copy_u8_Compare_Output_Mode){
	//Setting Operation Mode Bits (3 , 6)
	Assign_Bit(TIMER_u8_TCCR0, TCCR0_WGM00, Get_Bit(Copy_u8_Operation_Mode,0));
	Assign_Bit(TIMER_u8_TCCR0, TCCR0_WGM01, Get_Bit(Copy_u8_Operation_Mode,1));

	//Setting Compare Output Mode Bits (4 , 5)
	Assign_Bit(TIMER_u8_TCCR0, TCCR0_COM00, Get_Bit(Copy_u8_Compare_Output_Mode,0));
	Assign_Bit(TIMER_u8_TCCR0, TCCR0_COM01, Get_Bit(Copy_u8_Compare_Output_Mode,1));

	Global_u8_Clk_Src = Copy_u8_Clk_Src;
}


//////////////// Operation Modes Functions ///////////////

void TIMER0_void_START_NORMAL(u8 Copy_u8_Preload_Value){

	//Setting Preload Value
	TIMER_u8_TCNT0 = Copy_u8_Preload_Value;

	//Start Timer
	TIMER_u8_TCCR0 |= Global_u8_Clk_Src;

}

//_________________________________________________________________________________________//

void TIMER0_void_START_CTC(u8 Copy_u8_OCR_Value){

	//Setting Output Compare Match Value
	TIMER_u8_OCR0 = Copy_u8_OCR_Value;

	//Start Timer
	TIMER_u8_TCCR0 |= Global_u8_Clk_Src;

}

//_________________________________________________________________________________________//

void TIMER0_void_START_FAST_PWM(u8 Copy_u8_OCR_Value){

	//Setting Output Compare Match Value
	TIMER_u8_OCR0 = Copy_u8_OCR_Value;

	//Start Timer
	TIMER_u8_TCCR0 |= Global_u8_Clk_Src;

}

//_________________________________________________________________________________________//

void TIMER0_void_START_PHASECORRECT_PWM(u8 Copy_u8_OCR_Value){

	//Setting Output Compare Match Value
	TIMER_u8_OCR0 = Copy_u8_OCR_Value;

	//Start Timer
	TIMER_u8_TCCR0 |= Global_u8_Clk_Src;

}



//////////////// Interrupts Functions ///////////////

void TIMER0_void_INTERRUPT_ENABLE_DISABLE(u8 Copy_u8_Type, u8 Copy_u8_State){
	switch (Copy_u8_State){
	case ENABLE:
		Set_Bit(TIMER_u8_SREG,7);
		switch(Copy_u8_Type){
		case TIMER0_OV_INT:
			Set_Bit(TIMER_u8_TIMSK,0);
			break;
		case TIMER0_CM_INT:
			Set_Bit(TIMER_u8_TIMSK,1);
			break;
		}
		break;
		case DISABLE:
			Clear_Bit(TIMER_u8_SREG,7);
			switch(Copy_u8_Type){
			case TIMER0_OV_INT:
				Clear_Bit(TIMER_u8_TIMSK,0);
				break;
			case TIMER0_CM_INT:
				Clear_Bit(TIMER_u8_TIMSK,1);
				break;
			}
			break;
	}
}

//_________________________________________________________________________________________//

void TIMER0_void_OVERFLOW_INTERRUPT(void (* Copy_void_Callback_OV_Ptr)(void)){
	Global_void_OV_Ptr = Copy_void_Callback_OV_Ptr;
}

void __vector_11(void){
	if(Global_void_OV_Ptr != Null){
		(*Global_void_OV_Ptr)();
	}
}
//_________________________________________________________________________________________//

void TIMER0_void_COMPARE_MATCH_INTERRUPT(void (* Copy_void_Callback_CM_Ptr)(void)){
	Global_void_CM_Ptr = Copy_void_Callback_CM_Ptr;
}

void __vector_10(void){
	if(Global_void_CM_Ptr != Null){
		(*Global_void_CM_Ptr)();
	}
}
