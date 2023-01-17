#include "../My_STD_Libraries/STD_Types.h"
#include "../My_STD_Libraries/BIT_CALC.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"




//Default Global Variables-------------------------------
static u8 Global_u8_Mode       = ADC_u8_SCM;
static u8 Global_u8_Adjustment = ADC_u8_LFT_ADJ;
//-------------------------------------------------------




void ADC_void_INIT(u8 Copy_u8_Vref, u8 Copy_u8_Adjustment, u8 Copy_u8_Prescalar){

	//ADC Enable
	Set_Bit(ADC_u8_ADCSRA,7);

	//Vref Selection
	switch(Copy_u8_Vref){
	case ADC_u8_AVCC:
		Set_Bit(ADC_u8_ADMUX,6);
		Clear_Bit(ADC_u8_ADMUX,7);
		break;
	case ADC_u8_AREF:
		Clear_Bit(ADC_u8_ADMUX,6);
		Clear_Bit(ADC_u8_ADMUX,7);
		break;
	case ADC_u8_INTERNAL:
		Set_Bit(ADC_u8_ADMUX,6);
		Set_Bit(ADC_u8_ADMUX,7);
		break;
	}

	//Adjustment Selection
	Global_u8_Adjustment = Copy_u8_Adjustment;
	switch(Copy_u8_Adjustment){
	case ADC_u8_LFT_ADJ:
		Set_Bit(ADC_u8_ADMUX,5);
		break;
	case ADC_u8_RGT_ADJ:
		Clear_Bit(ADC_u8_ADMUX,5);
		break;
	}

	//Prescalar Selection
	switch(Copy_u8_Prescalar){
	case ADC_u8_PS_2:
		Clear_Bit(ADC_u8_ADCSRA,0);
		Clear_Bit(ADC_u8_ADCSRA,1);
		Clear_Bit(ADC_u8_ADCSRA,2);
		break;
	case ADC_u8_PS_4:
		Clear_Bit(ADC_u8_ADCSRA,0);
		Set_Bit(ADC_u8_ADCSRA,1);
		Clear_Bit(ADC_u8_ADCSRA,2);
		break;
	case ADC_u8_PS_8:
		Set_Bit(ADC_u8_ADCSRA,0);
		Set_Bit(ADC_u8_ADCSRA,1);
		Clear_Bit(ADC_u8_ADCSRA,2);
		break;
	case ADC_u8_PS_16:
		Clear_Bit(ADC_u8_ADCSRA,0);
		Clear_Bit(ADC_u8_ADCSRA,1);
		Set_Bit(ADC_u8_ADCSRA,2);
		break;
	case ADC_u8_PS_32:
		Set_Bit(ADC_u8_ADCSRA,0);
		Clear_Bit(ADC_u8_ADCSRA,1);
		Set_Bit(ADC_u8_ADCSRA,2);
		break;
	case ADC_u8_PS_64:
		Clear_Bit(ADC_u8_ADCSRA,0);
		Set_Bit(ADC_u8_ADCSRA,1);
		Set_Bit(ADC_u8_ADCSRA,2);
		break;
	case ADC_u8_PS_128:
		Set_Bit(ADC_u8_ADCSRA,0);
		Set_Bit(ADC_u8_ADCSRA,1);
		Set_Bit(ADC_u8_ADCSRA,2);
		break;
	}

}

void ADC_void_MODE(u8 Copy_u8_Mode, u8 Copy_u8_Channel){
	Global_u8_Mode = Copy_u8_Mode;
	switch (Copy_u8_Mode){
	case ADC_u8_SCM:
		Clear_Bit(ADC_u8_ADCSRA,5);
		break;
	case ADC_u8_ATFRM:
		Set_Bit(ADC_u8_ADCSRA,5);
		//		Set_Bit(ADC_u8_ADCSRA,3); //Interrupt Enable
		Clear_Bit(ADC_u8_SFIOR,0);
		Clear_Bit(ADC_u8_SFIOR,1);
		Clear_Bit(ADC_u8_SFIOR,2);
		break;
	case ADC_u8_ATAC:
		Set_Bit(ADC_u8_ADCSRA,5);
		Set_Bit(ADC_u8_SFIOR,0);
		Clear_Bit(ADC_u8_SFIOR,1);
		Clear_Bit(ADC_u8_SFIOR,2);
		break;
	case ADC_u8_ATEXTI0:
		Set_Bit(ADC_u8_ADCSRA,5);
		Clear_Bit(ADC_u8_SFIOR,0);
		Set_Bit(ADC_u8_SFIOR,1);
		Clear_Bit(ADC_u8_SFIOR,2);
		break;
	case ADC_u8_ATT0CM:
		Set_Bit(ADC_u8_ADCSRA,5);
		Set_Bit(ADC_u8_SFIOR,0);
		Set_Bit(ADC_u8_SFIOR,1);
		Clear_Bit(ADC_u8_SFIOR,2);
		break;
	case ADC_u8_ATT0OV:
		Set_Bit(ADC_u8_ADCSRA,5);
		Clear_Bit(ADC_u8_SFIOR,0);
		Clear_Bit(ADC_u8_SFIOR,1);
		Set_Bit(ADC_u8_SFIOR,2);
		break;
	}

	//Channel Selection
	ADC_u8_ADMUX &= 0b11100000;
	ADC_u8_ADMUX |= Copy_u8_Channel;

}



//Result Function
static u16 ADC_u16_Result(void){
	u16 Loc_u16_Result = 0;
	switch(Global_u8_Adjustment){
	case ADC_u8_LFT_ADJ:
		Loc_u16_Result  = (ADC_u8_ADCL>>6);
		Loc_u16_Result |= ((u16)ADC_u8_ADCH<<2);
		break;
	case ADC_u8_RGT_ADJ:
		Loc_u16_Result  = ADC_u8_ADCL;
		Loc_u16_Result |= ((u16)ADC_u8_ADCH<<8);
		break;
	}
	return Loc_u16_Result;
}


//MODES Read Functions
/*Single Conversion Mode*/
static u16 ADC_u16_SCM_Read(void){
	//Start Conversion
	Set_Bit(ADC_u8_ADCSRA,6);
	//Polling On A Flag(Waiting For Conversion)
	while(Get_Bit(ADC_u8_ADCSRA,4) != 1);
	//Clear Flag
	Set_Bit(ADC_u8_ADCSRA,4);
	//Result Read
	return ADC_u16_Result();
}
/*Free Running Mode*/
static u16 ADC_u16_ATFRM_Read(void){
	//Start Conversion
	Set_Bit(ADC_u8_ADCSRA,6);
	//Result Read
	return ADC_u16_Result();
}
/*EXTI 0 Mode*/
static u16 ADC_u16_EXTI0_Read(void){
	//Conversion will start by EXTI0 By H/W
	//Polling On A Flag(Waiting For Conversion)
	while(Get_Bit(ADC_u8_ADCSRA,4) != 1);
	//Clear Flag
	Set_Bit(ADC_u8_ADCSRA,4);
	//Result Read
	return ADC_u16_Result();
}




u16 ADC_u16_READ(void){
	//Modes Functions

	u16 Loc_u16_Read_Result = 0;
	switch(Global_u8_Mode){

	case ADC_u8_SCM:
		Loc_u16_Read_Result = ADC_u16_SCM_Read();
		break;
	case ADC_u8_ATFRM:
		Loc_u16_Read_Result = ADC_u16_ATFRM_Read();
		break;
	case ADC_u8_ATAC:
		//to be implemented
		break;
	case ADC_u8_ATEXTI0:
		Loc_u16_Read_Result = ADC_u16_EXTI0_Read();
		break;
	case ADC_u8_ATT0CM:
		//to be implemented
		break;
	case ADC_u8_ATT0OV:
		//to be implemented
		break;
	}


	return Loc_u16_Read_Result;
}
