/*
 * Servo.c
 *
 * Created: 10/27/2022 12:45:09 AM
 *  Author: Elwazeer
 */ 


#include "Servo.h"

void Servo_Init(void)
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE , TIMER1_SCALER_8 , OCRA_DISCONNECTED , OCRB_NON_INVERTING);
	
	ICR1 = 19999;
	SERVO_PIN = 999;
}

void Servo_Angle(u8 angle)
{
	SERVO_PIN = ((u32)angle * 1000)/180 + 999;
	
}