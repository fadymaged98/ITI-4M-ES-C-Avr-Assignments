
#include "../My_STD_Libraries/STD_Types.h"
#include "../My_STD_Libraries/BIT_CALC.h"

#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"

void (*Array_of_Pointers_to_Functions[3])(void)={NULL,NULL,NULL};


void __vecor_1(void){
	if(Array_of_Pointers_to_Functions[0] != NULL)
		Array_of_Pointers_to_Functions[0]();
}
void __vecor_2(void){
	if(Array_of_Pointers_to_Functions[1] != NULL)
		Array_of_Pointers_to_Functions[1]();
}
void __vecor_3(void){
	if(Array_of_Pointers_to_Functions[2] != NULL)
		Array_of_Pointers_to_Functions[2]();
}


void EXTI_void_ISR_Function(u8 Copy_u8_Index,void (*Ptr_to_function)(void)){
	Array_of_Pointers_to_Functions[Copy_u8_Index]=Ptr_to_function;
}

u8 EXTI_u8_Configure_Detection(u8 Copy_u8_Index,u8 Copy_u8_Detection){

	switch(Copy_u8_Index){

	case EXTI_u8_INT_0:

		Assign_Bit(EXTI_u8_MCUCR,0,Get_Bit(Copy_u8_Detection,0));
		Assign_Bit(EXTI_u8_MCUCR,1,Get_Bit(Copy_u8_Detection,1));
		break;

	case EXTI_u8_INT_1:

		Assign_Bit(EXTI_u8_MCUCR,2,Get_Bit(Copy_u8_Detection,0));
		Assign_Bit(EXTI_u8_MCUCR,3,Get_Bit(Copy_u8_Detection,1));
		break;

	case EXTI_u8_INT_2:
		if (Copy_u8_Detection == EXTI_u8_LOW_LEVEL || Copy_u8_Detection == EXTI_u8_IOC){
			return Loc_u8_INT2_Err;
		}else{
			Assign_Bit(EXTI_u8_MCUCSR,6,Get_Bit(Copy_u8_Detection,0));
			break;
		}
	}
	return 0;
}

void EXTI_void_EN_DIS(u8 Copy_u8_Index,u8 Copy_u8_Status){

	switch(Copy_u8_Index){

	case EXTI_u8_INT_0:

		switch (Copy_u8_Status){
		case EXTI_u8_EN:
			Set_Bit(EXTI_u8_GICR,6);
			break;
		case EXTI_u8_DIS:
			Clear_Bit(EXTI_u8_GICR,6);
			break;
		}
		break;
		case EXTI_u8_INT_1:

			switch (Copy_u8_Status){
			case EXTI_u8_EN:
				Set_Bit(EXTI_u8_GICR,7);
				break;
			case EXTI_u8_DIS:
				Clear_Bit(EXTI_u8_GICR,7);
				break;
			}
			break;
			case EXTI_u8_INT_2:

				switch (Copy_u8_Status){
				case EXTI_u8_EN:
					Set_Bit(EXTI_u8_GICR,5);
					break;
				case EXTI_u8_DIS:
					Clear_Bit(EXTI_u8_GICR,5);
					break;
				}
				break;
	}
}

void EXTI_void_EN_DIS_GLOBAL (u8 Copy_u8_Global_Status){


	switch (Copy_u8_Global_Status){

	case EXTI_u8_EN:
		Set_Bit(EXTI_u8_SREG,7);
		break;
	case EXTI_u8_DIS:
		Clear_Bit(EXTI_u8_SREG,7);
		break;
	}

}






