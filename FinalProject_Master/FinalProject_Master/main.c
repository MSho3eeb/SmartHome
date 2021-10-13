/*
 * FinalProject_Master.c
 *
 * Created: 8/10/2020 3:52:08 PM
 * Author : Mohamed Teleb
 */ 

#include "SPI.h"
#include "DIO.h"
#include "UART.h"
#include "LCD.h"
#include "ADC.h"
#include <avr/interrupt.h>
#include <stdlib.h>


int main(void)
{
	
	UART_Init();
	DIO_InIt();
	LCD_Init();
	ADC_Init();
	

	SPI_CFG config = {MASTER,OSC16};
	SPI_Init(&config);
	Slave_En();
	
	uint8 Command;
	char buffer[10];
	uint8 temp = 0;
	uint8 adc_result;
	
	
	
	while (1)
	{
		adc_result = SPDR;
		//adc_result = ADC_Read(0);
		//temp = adc_result / 2.01;
		Command = UART_Recive();
		if(Command == 'r'){
		if(SPI_SEND_GET('r') != 0x80){
		adc_result = SPDR;
		if(adc_result != 0x00){
			temp =  adc_result / 2.01;
			itoa(temp,buffer,10);
			LCD_Clear();
			LCD_String((uint8*)" TEMP = ");
			LCD_String((uint8*)buffer);
			LCD_String((uint8*)" C");
		}else{
			LCD_Clear();
			LCD_String((uint8*)" PRESS AGAIN PLZ!");
		}
		
		}
		}else{
		SPI_Send(Command);
		}
		
	}
}

