/*
 * LCD.h
 *
 * Created: 7/17/2020 11:38:44 AM
 *  Author: Mohamed Teleb
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define LCD_RS DIO_ChannelB1
#define LCD_RW DIO_ChannelB2
#define LCD_E DIO_ChannelB3

#define LCD_Data_Port DIO_PortA
#define LCD_Control_Port DIO_PortB

void LCD_Cmd(uint8 cmd);
void LCD_Init(void);
void LCD_Char(uint8 data);
void LCD_String( uint8 * data);
void LCD_Clear(void);
void LCD_GOTOString(uint8 line, uint8 pos,uint8 string[]);




#endif /* LCD_H_ */