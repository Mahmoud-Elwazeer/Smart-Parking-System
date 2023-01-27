/*
 * DIO_Types.h
 *
 * Created: 10/12/2022 11:45:13 PM
 *  Author: Elwazeer
 */ 


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_


typedef enum{
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	Total_pin
}DIO_PIN_ID;

typedef enum{
	LOW,
	HIGH
}DIO_Value;

typedef enum{
	OUTPUT,
	INPUT,
	INPUT_PULL_UP
}DIO_Direction;

typedef enum{
	PA,
	PB,
	PC,
	PD
}DIO_PORT_ID;


extern const  DIO_Direction direction[Total_pin];

#endif /* DIO_TYPES_H_ */