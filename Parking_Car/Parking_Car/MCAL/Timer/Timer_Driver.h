 /* Timer_Driver.h
 *
 * Created: 9/8/2022 7:42:24 PM
 *  Author: fage
 */ 


#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_


#include "../DIO/DIO.h"

typedef enum{
	Timer0_NORMAL,
	Timer0_PHASE_CORRECT,
	Timer0_CTC,
	Timer0_FAST_PWM
	}Timer0_mode;
	
typedef enum{
	Timer0_STOP,
	Timer0_SCALER_1,
	Timer0_SCALER_8,
	Timer0_SCALER_64,
	Timer0_SCALER_256,
	Timer0_SCALER_1024,
	Timer0_EXTERNAL_FALLING,
	Timer0_EXTERNAL_RISING
	}Timer0_Scaler;

typedef enum{
	OC0_DISCONNECTED,
	OC0_TOGGLE,
	OCO_NON_INVERTING,
	OCO_INVERTING
	}Timer0_OC0_mode;


/************************* Timer 0 Fuction **********************************/

void Timer0_Init(Timer0_mode mode0 , Timer0_Scaler scaler , Timer0_OC0_mode oc0);
void Timer0_OVF_Interrupt_Enable(void);
void Timer0_OVF_Interrupt_Disable(void);
void Timer0_OC_InterruptEnable(void);
void Timer0_OC_InterruptDisable(void);


/****************** *************************************************/

typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
}Timer1_Scaler;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE

}Timer1_Mode;

typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}Timer1_OC1A_Mode;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING

}Timer1_OC1B_Mode;


typedef enum
{
	RISING,
	FALLING
}ICU_Edge_type;

/************************* Timer 1 Fuction **********************************/

void Timer1_Init( Timer1_Mode mode1,Timer1_Scaler scaler,Timer1_OC1A_Mode oc1a_mode,Timer1_OC1B_Mode oc1b_mode);
void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);
void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));


#endif /*TIMER_DRIVER_H_ */