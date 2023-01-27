/*
 * DIO.h
 *
 * Created: 10/12/2022 11:35:03 PM
 *  Author: Elwazeer
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../ATMEGA32_REG.h"
#include "../../BIT_Math.h"
#include "../../Std_types.h"
#include "DIO_Types.h"

 /**************************** Init DIO (Digital input Output) ********/
 /*************************** To Config Pins Go To DIO_Config.c *******/
void DIO_Init();

 /*************************** Write value on Port  *******************/
void DIO_SetPortValue(DIO_PORT_ID port , u8 value);

/********************************* SET (HIGH) OR Clear (LOW) Pin value ***/ 
void DIO_SetPinValue(DIO_PIN_ID pin , DIO_Value value);

 /************************ Read value Form Port **************************/
u8 DIO_GetPortValue(DIO_PORT_ID port);

/************************** Read Value of Pin (One or Zero) **********/ 
DIO_Value DIO_GetPinValue(DIO_PIN_ID pin );

/*************************** Toggle Pin **************************/
void DIO_TogglePin(DIO_PIN_ID pin);


#endif /* DIO_H_ */