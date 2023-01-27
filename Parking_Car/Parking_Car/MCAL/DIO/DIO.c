/*
 * DIO.c
 *
 * Created: 10/12/2022 11:34:52 PM
 *  Author: Elwazeer
 */ 

#include "DIO.h"

void DIO_Init()
{
	DIO_PORT_ID port ;
	DIO_Direction status ;
	u8 pin_ID ;
	u8 Current_pin;
	for(Current_pin = 0; Current_pin < Total_pin; Current_pin++)
		{
			status = direction[Current_pin];
			port = Current_pin / 8;
			pin_ID = Current_pin % 8 ;
			
			switch(status)
			{
				case OUTPUT:
				switch(port)
				{
					case PA:
					SET_BIT(DDRA , pin_ID);
					break;
					case PB:
					SET_BIT(DDRB , pin_ID);
					break;
					case PC:
					SET_BIT(DDRC , pin_ID);
					break;
					case PD:
					SET_BIT(DDRD , pin_ID);
					break;
				}
				break;
				case INPUT:
				switch(port)
				{
					case PA:
					CLEAR_BIT(DDRA , pin_ID);
					CLEAR_BIT(PORTA , pin_ID);
					break;
					case PB:
					CLEAR_BIT(DDRB , pin_ID);
					CLEAR_BIT(PORTB , pin_ID);
					break;
					case PC:
					CLEAR_BIT(DDRC , pin_ID);
					CLEAR_BIT(PORTC , pin_ID);
					break;
					case PD:
					CLEAR_BIT(DDRD , pin_ID);
					CLEAR_BIT(PORTD , pin_ID);
					break;
				}
				break;
				case INPUT_PULL_UP:
				switch(port)
				{
					case PA:
					CLEAR_BIT(DDRA , pin_ID);
					SET_BIT(PORTA , pin_ID);
					break;
					case PB:
					CLEAR_BIT(DDRB , pin_ID);
					SET_BIT(PORTB , pin_ID);
					break;
					case PC:
					CLEAR_BIT(DDRC , pin_ID);
					SET_BIT(PORTC , pin_ID);
					break;
					case PD:
					CLEAR_BIT(DDRD , pin_ID);
					SET_BIT(PORTD , pin_ID);
					break;
				}
				break;
			}
		}
}
 
void DIO_SetPortValue(DIO_PORT_ID port , u8 value)
{
	if (port <= PD)
		{
			switch(port)
			{
				case PA: PORTA = value; break ;
				case PB: PORTB = value; break ;
				case PC: PORTC = value; break ;
				case PD: PORTD = value; break ;
			}
		}
}

void DIO_SetPinValue(DIO_PIN_ID pin , DIO_Value value)
{
	if (pin < Total_pin)
		{
			DIO_PORT_ID port ;
			port = pin / 8;
			
			u8 pin_ID ;
			pin_ID = pin % 8;
			
			switch(value)
			{
				case HIGH:
				switch (port)
				{
					case PA : SET_BIT(PORTA , pin_ID); break ;
					case PB : SET_BIT(PORTB , pin_ID); break ;
					case PC : SET_BIT(PORTC , pin_ID); break ;
					case PD : SET_BIT(PORTD , pin_ID); break ;
				}
				break;
				case LOW:
				switch (port)
				{
					case PA : CLEAR_BIT(PORTA , pin_ID); break ;
					case PB : CLEAR_BIT(PORTB , pin_ID); break ;
					case PC : CLEAR_BIT(PORTC , pin_ID); break ;
					case PD : CLEAR_BIT(PORTD , pin_ID); break ;
				}
				break;
			}
		}
}

u8 DIO_GetPortValue(DIO_PORT_ID port)
{
	if (port <= PD)
		{
			switch(port)
			{
				case PA: return PINA ; break;
				case PB: return PINB ; break;
				case PC: return PINC ; break;
				case PD: return PIND ; break;
				default: return 0x00; break;
			}
		}
	
	return 0x00;
}

DIO_Value DIO_GetPinValue(DIO_PIN_ID pin )
{
	if (pin < Total_pin)
		{
			DIO_PORT_ID port ;
			port = pin / 8;
			
			u8 pin_ID ;
			pin_ID = pin % 8;
			
			switch(port)
			{
				case PA: return GET_BIT(PINA , pin_ID); break;
				case PB: return GET_BIT(PINB , pin_ID); break;
				case PC: return GET_BIT(PINC , pin_ID); break;
				case PD: return GET_BIT(PIND , pin_ID); break;
				default: return 0x00; break;
			}
		}
	return 0x00;
}

void DIO_TogglePin(DIO_PIN_ID pin)
{
	if (pin < Total_pin)
		{
			DIO_PORT_ID port ;
			port = pin / 8;
			
			u8 pin_ID ;
			pin_ID = pin % 8;
			
			switch(port)
			{
				case PA: TOGGLE_BIT(PORTA , pin_ID); break;
				case PB: TOGGLE_BIT(PORTB , pin_ID); break;
				case PC: TOGGLE_BIT(PORTC , pin_ID); break;
				case PD: TOGGLE_BIT(PORTD , pin_ID); break;
			}
		}
}