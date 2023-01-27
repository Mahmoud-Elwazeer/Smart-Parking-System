/*
 * Garage_System.c
 *
 * Created: 10/26/2022 8:20:26 PM
 *  Author: Elwazeer
 */ 


#include "Garage_System.h"

void Garage_System(void)
{
	
	DIO_Init();
	LCD_Init();
	Servo_Init();
	
	LCD_GOTO(0 , 5);
	LCD_WriteString("Welcome");
	
	LCD_GOTO(1 , 3);
	LCD_WriteString("Parking Car");
	
	_delay_ms(2000);
	
	LCD_Clear();
	
	LCD_GOTO(0 , 5);
	LCD_WriteString("Welcome!");
	
	LCD_GOTO(1 , 0);
	LCD_WriteString("Available:");
	
	s8 flag1 = 0 , flag2 = 0 , available = 3;
	
	LCD_GOTO(1 , 12);
	LCD_WriteNumber(available);
	
	
	// Such as Zero to Fit my Design 
	Servo_Angle(100);
	
	while(1)
	{
		
// initial value of sensor is HIGH when detect object value become low
	
		
		if(DIO_GetPinValue(PIND0) == LOW && flag1==0)
		{
			if(available>0)
			{
				flag1=1;
				if(flag2==0)
				{
					// servo
					Servo_Angle(0);
					available = available-1;
				}
			}
			else
			{
				LCD_Clear();
							
				LCD_GOTO(0 , 5);
				LCD_WriteString("Sorry");
							
				LCD_GOTO(1 , 2);
				LCD_WriteString("Parking Full");
				_delay_ms(2000);
							
				LCD_Clear();
							
				LCD_GOTO(0 , 5);
				LCD_WriteString("Welcome!");
							
				LCD_GOTO(1 , 0);
				LCD_WriteString("Available:");
							
			}
		}
					
		
		
		while(!DIO_GetPinValue(PIND0));
					
		if( DIO_GetPinValue(PIND1) == LOW && flag2==0)
		{
			flag2=1;
			if(flag1==0)
			{
				//servo
				Servo_Angle(0);
				available = available+1;
			}
		}
					
		
		while(!DIO_GetPinValue(PIND1));
		
		
		if(flag1==1 && flag2==1)
		{
			
			// servo
			Servo_Angle(100);
			flag1=0, flag2=0;
		}

		
		LCD_GOTO(1 , 12);
		LCD_WriteNumber(available);
	}
	
}