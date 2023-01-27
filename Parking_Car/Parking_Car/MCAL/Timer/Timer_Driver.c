 /* Timer_Driver.c
 *
 * Created: 9/8/2022 7:41:59 PM
 *  Author: fage
 */


#include "Timer_Driver.h"

/****************************Pointer to functions to be assigned to ISR*********************************/

static void (*Timer1_OVF_Fptr) (void)=NULLptr;
static void (*Timer1_OCA_Fptr) (void)=NULLptr;
static void (*Timer1_OCB_Fptr) (void)=NULLptr;
static void (*Timer1_ICU_Fptr) (void)=NULLptr;
/********************************Timer 0************************************/
void Timer0_Init(Timer0_mode mode0 , Timer0_Scaler scaler , Timer0_OC0_mode oc0)
{
	switch(mode0)
	{
		case Timer0_NORMAL:
		CLEAR_BIT(TCCR0 , WGM00);
		CLEAR_BIT(TCCR0 , WGM01);
		break;
		case Timer0_PHASE_CORRECT:
		SET_BIT(TCCR0 , WGM00);
		CLEAR_BIT(TCCR0 , WGM01);
		break;
		case Timer0_CTC:
		CLEAR_BIT(TCCR0 , WGM00);
		SET_BIT(TCCR0 , WGM01);
		break;
		case Timer0_FAST_PWM:
		SET_BIT(TCCR0 , WGM00);
		SET_BIT(TCCR0 , WGM01);
		break;
	}
	
	// CS02 , CS01 , CS00
	TCCR0 &= 0xF8;  // 11111000
	TCCR0 |= scaler;
	
	switch(oc0)
	{
		case OC0_DISCONNECTED:
		CLEAR_BIT(TCCR0 , COM00);
		CLEAR_BIT(TCCR0 , COM01);
		break;
		case OC0_TOGGLE:
		SET_BIT(TCCR0 , COM00);
		CLEAR_BIT(TCCR0 , COM01);
		break;
		case OCO_NON_INVERTING:
		CLEAR_BIT(TCCR0 , COM00);
		SET_BIT(TCCR0 , COM01);
		break;
		case OCO_INVERTING:
		SET_BIT(TCCR0 , COM00);
		SET_BIT(TCCR0 , COM01);
		break;
	}
}

void Timer0_OVF_Interrupt_Enable(void)
{
	SET_BIT(TIMSK , TOIE0);
}

void Timer0_OVF_Interrupt_Disable(void)
{
	CLEAR_BIT(TIMSK , TOIE0);
}

void Timer0_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE0);
}

void Timer0_OC_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE0);
}

/****************************** Timer 1 *************************************/

void Timer1_Init(Timer1_Mode mode1,Timer1_Scaler scaler,Timer1_OC1A_Mode oc1a_mode,Timer1_OC1B_Mode oc1b_mode)
{
	switch (mode1)
	{
		case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
	
	
	TCCR1B&=0XF8;
	TCCR1B|=scaler;

}

void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_BIT(TCCR1B,ICES1);
	
	else if(edge==FALLING)
	CLEAR_BIT(TCCR1B,ICES1);

}

/****************************Timer 1 Interrupt functions**************************************/

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}

void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}

/*********************************Timer 1 Call Back functions*****************************************/

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}


/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_Fptr!=NULLptr)
	{
		Timer1_OVF_Fptr();
	}
}
ISR(TIMER1_COMPA_vect)
{
	if(Timer1_OCA_Fptr!=NULLptr)
	{
		Timer1_OCA_Fptr();
	}
}
ISR(TIMER1_COMPB_vect)
{
	if(Timer1_OCB_Fptr!=NULLptr)
	{
		Timer1_OCB_Fptr();
	}
}
ISR(TIMER1_CAPT_vect)
{
	if(Timer1_ICU_Fptr!=NULLptr)
	{
		Timer1_ICU_Fptr();
	}
}