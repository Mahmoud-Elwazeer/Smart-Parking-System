/*
 * LCD_Driver.h
 *
 * Created: 8/7/2022 10:41:40 PM
 *  Author: Elwazeer
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_


#include "LCD_config.h"


void LCD_Init();
void LCD_WriteCmd(u8 cmd);
void LCD_WriteData(u8 dataaaa);
void LCD_GOTO(u8 pos_x , u8 pos_y);
void LCD_WriteChar(u8 character);
void LCD_WriteString(char *str);
void LCD_WriteSpaces(u8 n);
void LCD_WriteNumber(u64 Number);
void LCD_WriteNumber5(u32 Number);
void LCD_WriteNumber2(u16 Number);
void LCD_WriteNumber3(u8 Number);
void LCD_WriteBinary(u8 num);
void Create_Character(u8 *Pattern,u8 Location);
void LCD_Clear(void);


#endif /* LCD_DRIVER_H_ */