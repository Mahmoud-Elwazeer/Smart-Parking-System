/*
 * LCD_Driver.c
 *
 * Created: 8/7/2022 10:42:59 PM
 *  Author: Elwazeer
 */ 

#include "LCD_Driver.h"

/******************** 8 BIT mode functions ***********/

#if (LCD_MODE==LCD_8_BIT_MODE)

void LCD_Init()
{	
	_delay_ms(20);                     // said in Data sheet to delay after power on for 1st time
	
	LCD_WriteCmd(0x38);                // Enable 8-bit mode
	LCD_WriteCmd(0x0C);                // Display on , Cursor off (0x0E) Display on , Cursor blinking 
	LCD_WriteCmd(0x01);                // Clear LCD
	LCD_WriteCmd(0x06);               // shift cursor to right (increment cursor)
	LCD_WriteCmd(0x80);               // beginning of 1st line
}

void LCD_WriteCmd(u8 cmd)
{
	DIO_SetPortValue(DATA , cmd);
	
	DIO_SetPinValue( RS , LOW);
	DIO_SetPinValue( RW , LOW);
	DIO_SetPinValue( EN , HIGH);
	_delay_ms(1);
	DIO_SetPinValue( EN , LOW);
}

void LCD_WriteData(u8 dataaaa)
{
	DIO_SetPortValue(DATA , dataaaa);
	
	DIO_SetPinValue( RS , HIGH);
	DIO_SetPinValue( RW , LOW);
	DIO_SetPinValue( EN , HIGH);
	_delay_ms(1);
	DIO_SetPinValue( EN , LOW);
}


/******************** 4 BIT mode functions ***********/

#elif (LCD_MODE==LCD_4_BIT_MODE)

void LCD_Init()
{
	_delay_ms(20);                     // said in Data sheet to delay after power on for 1st time
	
	LCD_WriteCmd(0x02);                   
	LCD_WriteCmd(0x28);                // Enable 4-bit mode
	LCD_WriteCmd(0x0C);                // Display on , Cursor off (0x0E) Display on , Cursor blinking
	LCD_WriteCmd(0x01);                // Clear LCD
	LCD_WriteCmd(0x06);               // shift cursor to right (increment cursor)
	LCD_WriteCmd(0x80);               // beginning of 1st line
}

void LCD_WriteCmd(u8 cmd)
{
	DIO_SetPinValue(D4 , GET_BIT(cmd , 4));
	DIO_SetPinValue(D5 , GET_BIT(cmd , 5));
	DIO_SetPinValue(D6 , GET_BIT(cmd , 6));
	DIO_SetPinValue(D7 , GET_BIT(cmd , 7));
	
	DIO_SetPinValue( RS , LOW);
	DIO_SetPinValue( RW , LOW);
	DIO_SetPinValue( EN , HIGH);
	_delay_ms(1);
	DIO_SetPinValue( EN , LOW);
	
	DIO_SetPinValue(D4 , GET_BIT(cmd , 0));
	DIO_SetPinValue(D5 , GET_BIT(cmd , 1));
	DIO_SetPinValue(D6 , GET_BIT(cmd , 2));
	DIO_SetPinValue(D7 , GET_BIT(cmd , 3));
	
	DIO_SetPinValue( RS , LOW);
	DIO_SetPinValue( RW , LOW);
	DIO_SetPinValue( EN , HIGH);
	_delay_ms(1);
	DIO_SetPinValue( EN , LOW);
}

void LCD_WriteData(u8 dataaaa)
{
	DIO_SetPinValue(D4 , GET_BIT(dataaaa , 4));
	DIO_SetPinValue(D5 , GET_BIT(dataaaa , 5));
	DIO_SetPinValue(D6 , GET_BIT(dataaaa , 6));
	DIO_SetPinValue(D7 , GET_BIT(dataaaa , 7));
	
	DIO_SetPinValue( RS , HIGH);
	DIO_SetPinValue( RW , LOW);
	DIO_SetPinValue( EN , HIGH);
	_delay_ms(1);
	DIO_SetPinValue( EN , LOW);
	
	DIO_SetPinValue(D4 , GET_BIT(dataaaa , 0));
	DIO_SetPinValue(D5 , GET_BIT(dataaaa , 1));
	DIO_SetPinValue(D6 , GET_BIT(dataaaa , 2));
	DIO_SetPinValue(D7 , GET_BIT(dataaaa , 3));
	
	DIO_SetPinValue( RS , HIGH);
	DIO_SetPinValue( RW , LOW);
	DIO_SetPinValue( EN , HIGH);
	_delay_ms(1);
	DIO_SetPinValue( EN , LOW);
}


#endif


void LCD_GOTO(u8 pos_x , u8 pos_y)
{
	int address = 0;
	
	if (pos_x == 0)
	address = 0x80;
	else if (pos_x == 1)
	address = 0xC0;
	
	if (pos_y <= 15)
	address += pos_y;
	
	LCD_WriteCmd(address);
}

void LCD_WriteChar(u8 character)
{
	LCD_WriteData(character);
}


void LCD_WriteString(char *str)
{
	for(u8 i =0; str[i]  ; i++)
	{
		LCD_WriteData(str[i]);
		_delay_ms(1);
	}
	
}

void LCD_WriteSpaces(u8 n)
{
	for(u8 i =0; i < n ; i++)
	{
		LCD_WriteData(' ');
		_delay_ms(1);
	}
}

void LCD_WriteNumber(u64 Number)
{
	u8 i=0,arr[16];
	if(Number==0)
	LCD_WriteData('0');
	else{
		while(Number)
		{
			arr[i]=Number%10 +'0';
			Number/=10;
			i++;
		}
		for(;i>0;i--)
		{
			LCD_WriteData(arr[i-1]);
		}
	}
}

void LCD_WriteNumber5(u32 Number)
{
	LCD_WriteData(Number%100000/10000+'0');
	LCD_WriteData(Number%10000/1000+'0');
	LCD_WriteData(Number%1000/100+'0');
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
}


void LCD_WriteNumber2(u16 Number)
{
	LCD_WriteData(Number%10000/1000+'0');
	LCD_WriteData(Number%1000/100+'0');
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
}

void LCD_WriteNumber3(u8 Number)
{
	LCD_WriteData(Number%1000/100+'0');
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
}

void LCD_WriteBinary(u8 num)
{
	for(s8 i = 7; i >= 0; i--)
	{
		LCD_WriteData(((num>>i)&0x01) + '0');
	}
}

void Create_Character(u8 *Pattern,u8 Location) 
{
	
	LCD_WriteCmd(0x40+(Location*8)); //Send the Address of CGRAM
	for(u8 i = 0;i<8;i++)
	LCD_WriteData(Pattern[i]); //Pass the bytes of pattern on LCD

}

void LCD_Clear(void)
{

	LCD_WriteCmd(0x01);
	LCD_GOTO(0,0);

}