
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

//Vref Options
#define ADC_u8_AVCC        0
#define ADC_u8_AREF        1
#define ADC_u8_INTERNAL    2

//Adjustments Options
#define ADC_u8_LFT_ADJ     0
#define ADC_u8_RGT_ADJ     1

//Prescalar Options
#define ADC_u8_PS_2        0
#define ADC_u8_PS_4        1
#define ADC_u8_PS_8        2
#define ADC_u8_PS_16       3
#define ADC_u8_PS_32       4
#define ADC_u8_PS_64       5
#define ADC_u8_PS_128      6

//Operation Modes Options
#define ADC_u8_SCM         0  //Single Conversion Mode
#define ADC_u8_ATFRM       1  //AUTO TRIGGER Free Running Mode
#define ADC_u8_ATAC        2  //AUTO TRIGGER Analog Comparator Mode
#define ADC_u8_ATEXTI0     3  //AUTO TRIGGER External Interrupt Request 0 Mode
#define ADC_u8_ATT0CM      4  //AUTO TRIGGER TIMER 0 COMPARE MATCH Mode
#define ADC_u8_ATT0OV      5  //AUTO TRIGGER TIMER 0 OVERFLOW Mode
#define ADC_u8_ATT1CM      6  //AUTO TRIGGER TIMER 1 COMPARE MATCH Mode
#define ADC_u8_ATT1OV      7  //AUTO TRIGGER TIMER 1 OVERFLOW Mode
#define ADC_u8_ATT1CE      8  //AUTO TRIGGER TIMER 1 CAPTURE EVENT Mode


//Single Channels Options
#define ADC_u8_CH0         0
#define ADC_u8_CH1         1
#define ADC_u8_CH2         2
#define ADC_u8_CH3         3
#define ADC_u8_CH4         4
#define ADC_u8_CH5         5
#define ADC_u8_CH6         6
#define ADC_u8_CH7         7


//Functions
void ADC_void_INIT(u8 Copy_u8_Vref, u8 Copy_u8_Adjustment, u8 Copy_u8_Prescalar);
void ADC_void_MODE(u8 Copy_u8_Mode, u8 Copy_u8_Channel);
u16 ADC_u16_READ(void);




#endif
