/*
 * LCD.c
 *
 * Created: 7/17/2020 11:38:31 AM
 *  Author: Mohamed Teleb
 */ 

#include "LCD.h"

void LCD_Cmd(uint8 cmd){
	uint8 Send_Cmd;
	Send_Cmd = (LCD_Data_Port & (0x0F)) | (cmd & (0xF0));
	DIO_WritePort(LCD_Data_Port, Send_Cmd);
	DIO_Write(LCD_RS,STD_Low);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_High);
	_delay_ms(2);
	Send_Cmd = (LCD_Data_Port & (0x0F)) | (cmd << (4));
	DIO_WritePort(LCD_Data_Port, Send_Cmd);
	DIO_Write(LCD_RS,STD_Low);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_High);
	_delay_ms(2);
	
}
void LCD_Clear(void){
	LCD_Cmd(0x01);
}

void LCD_Init(void){
	DIO_Write(LCD_RW,STD_Low);
	_delay_ms(20);
	LCD_Cmd(0x33);
	_delay_ms(2);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);
	LCD_Cmd(0x06);
	LCD_Cmd(0x0C);
	LCD_Cmd(0x01);
	_delay_ms(2);
	
}
void LCD_Char(uint8 data){
	uint8 Send_Data;
	Send_Data = (LCD_Data_Port & (0x0F)) | (data & (0xF0));
	DIO_WritePort(LCD_Data_Port, Send_Data);
	DIO_Write(LCD_RS,STD_High);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_High);
	_delay_ms(2);
	
	Send_Data = (LCD_Data_Port & (0x0F)) | (data << (4));
	DIO_WritePort(LCD_Data_Port, Send_Data);
	DIO_Write(LCD_RS,STD_High);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_High);
	_delay_ms(2);
}

void LCD_String(uint8 string[]){
	uint8* data =(uint8*) string;
	int i = 0;
	while(data[i] != '\0'){
		LCD_Char(data[i]);
		i++;
	}
}


void LCD_GOTOString(uint8 line, uint8 pos,uint8 string[]){
	uint8 cmd;
	switch(line){
		case 1:
			cmd = 0x80 | (pos & 0x0F);
			LCD_Cmd(cmd);
		break;
		case 2:
			cmd = 0xC0 | (pos & 0x0F);
			LCD_Cmd(cmd);
		break;
	}
	LCD_String(string);
	
}