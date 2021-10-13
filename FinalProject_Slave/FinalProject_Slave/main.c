/*
* FinalProject_Slave.c
*
* Created: 8/10/2020 3:29:20 PM
* Author : Mohamed Teleb
*/

#include "SPI.h"
#include "DIO.h"
#include "LCD.h"
#include "ADC.h"
#include <stdlib.h>
#define speed1 767
#define speed2 511
#define speed3 255
#define speed4 10


int main(void)
{
	
	DIO_InIt();
	LCD_Init();
	ADC_Init();
	LCD_Clear();
	TCCR1A = (1<<WGM10) | (1<<WGM11) | (1<<COM1B0) | (1<<COM1B1);
	TCCR1B = (1<<WGM12) | (1<<CS10);
	OCR1B = speed1;
	SPI_CFG config = {SLAVE,OSC16};
	SPI_Init(&config);
	unsigned char Command = 0;
	short SpeedCommand = 0;
	
	uint8 temp;
	uint8 buffer[10];
	
	while (1)
	{
		temp = ADC_Read(0);
		
		Command = SPI_Get();
		if(Command == 'F'){
			LCD_Clear();
			LCD_String((uint8*)"MOTOR START");
			DIO_Write(DIO_ChannelC3,STD_High);
			DIO_Write(DIO_ChannelC4,STD_Low);
			}else if(Command == 'B'){
			SpeedCommand = 4;
			LCD_Clear();
			LCD_String((uint8*)"MOTOR STOP");
			DIO_Write(DIO_ChannelC3,STD_Low);
			DIO_Write(DIO_ChannelC4,STD_Low);
			}else if(Command == 'R'){
			SpeedCommand = 4;
			LCD_Clear();
			LCD_String((uint8*)"LED1 ON");
			DIO_Write(DIO_ChannelD0,STD_High);
			}else if(Command == 'L'){
			SpeedCommand = 4;
			LCD_Clear();
			LCD_String((uint8*)"LED1 OFF");
			DIO_Write(DIO_ChannelD0,STD_Low);
			
			}else if(Command == 'u'){
			SpeedCommand++;
			if(SpeedCommand > 3 || SpeedCommand < 0){
			SpeedCommand = 0;
			}
			switch(SpeedCommand){
				case 0:
				LCD_Clear();
				LCD_String((uint8*)"MOTOR SPEED 25%");
				OCR1B = speed1;
				break;
				case 1:
				LCD_Clear();
				LCD_String((uint8*)"MOTOR SPEED 50%");
				OCR1B = speed2;
				break;
				case 2:
				LCD_Clear();
				LCD_String((uint8*)"MOTOR SPEED 75%");
				OCR1B = speed3;
				break;
				case 3:
				LCD_Clear();
				LCD_String((uint8*)"MOTOR SPEED 99%");
				OCR1B = speed4;
				break;
			}
			}else if(Command == 'd'){
			SpeedCommand--;
			if(SpeedCommand > 3 || SpeedCommand < 0){
				SpeedCommand = 0;
			}
			switch(SpeedCommand){
				case 0:
				LCD_Clear();
				LCD_String((uint8*)"MOTOR SPEED 25%");
				OCR1B = speed1;
				break;
				case 1:
				LCD_Clear();
				LCD_String((uint8*)"MOTOR SPEED 50%");
				OCR1B = speed2;
				break;
				case 2:
				LCD_Clear();
				LCD_String((uint8*)"MOTOR SPEED 75%");
				OCR1B = speed3;
				break;
				case 3:
				LCD_Clear();
				LCD_String((uint8*)"MOTOR SPEED 99%");
				OCR1B = speed4;
				break;
			}
			}else if(Command == 'r'){
			
				LCD_Clear();
				SPI_Send(temp);
				if(SPI_SEND_GET(temp) == 'r'){
					LCD_String("SENT");
				}
				
			
			
			}else if(Command == 0x66){
			SPI_Send(temp);
			}
		
		
		
		
		
		
	}
}

