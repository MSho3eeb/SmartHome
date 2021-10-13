/*
 * UART.h
 *
 * Created: 7/28/2020 7:41:08 PM
 *  Author: Mohamed Teleb
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define Baud_Rate 9600
//#define DoubleSpeed
#ifndef DoubleSpeed 
#define UBRR_Value ((F_CPU/(16UL * Baud_Rate)) - 1)
#else
#define UBRR_Value ((F_CPU/(8UL * Baud_Rate)) - 1) 
#endif

void UART_Init(void);
void UART_SendChar(char data);
void UART_SendString(char* data);
char UART_Recive(void);

#endif /* UART_H_ */