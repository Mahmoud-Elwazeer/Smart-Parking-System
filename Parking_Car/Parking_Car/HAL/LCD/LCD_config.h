/*
 * LCD_config.h
 *
 * Created: 10/18/2022 6:15:59 PM
 *  Author: Elwazeer
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#include "../../MCAL/DIO/DIO.h"

/********************************** LCD modes ***********************/

#define    LCD_4_BIT_MODE          0
#define    LCD_8_BIT_MODE          1


/********************************** LCD config ***********************/

#define   LCD_MODE          LCD_8_BIT_MODE

/*************** LCD config 8 Bit mode (OUTPUT IN DIO_CONFIG) **********/
#define    DATA             PA

/*************** LCD config 4 Bit mode (OUTPUT IN DIO_CONFIG)*********/
#define   D4              PINA0        
#define   D5              PINA1
#define   D6              PINA2
#define   D7              PINA3

/************ define control pins (OUTPUT IN DIO_CONFIG)    *************/

#define RS               PINB0
#define RW               PINB1
#define EN               PINB2



#endif /* LCD_CONFIG_H_ */