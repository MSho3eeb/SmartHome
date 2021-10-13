/*
 * UART.c
 *
 * Created: 7/28/2020 7:40:57 PM
 *  Author: Mohamed Teleb
 */ 

#include "UART.h"

void UART_Init(void){
	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
	UBRRL = UBRR_Value;
	UBRRH = UBRR_Value >> 8;
}

void UART_SendChar(char data){
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}

void UART_SendString(char* data){
	volatile unsigned char i = 0;
	while(data[i] != '\0'){
		UART_SendChar(data[i]);
		i++;
	}
}

char UART_Recive(){
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}