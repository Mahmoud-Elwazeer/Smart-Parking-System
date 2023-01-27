/*
 * Servo.h
 *
 * Created: 10/27/2022 12:45:18 AM
 *  Author: Elwazeer
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "../../MCAL/Timer/Timer_Driver.h"

#define  SERVO_PIN       OCR1B

void Servo_Init(void);
void Servo_Angle(u8 angle);



#endif /* SERVO_H_ */