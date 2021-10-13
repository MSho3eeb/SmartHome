/*
 * SPI.h
 *
 * Created: 8/10/2020 1:20:13 PM
 *  Author: Mohamed Teleb
 */ 


#ifndef SPI_H_
#define SPI_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "BIt_Math.h"
#include "STD_Types.h"
#define SS 4
#define MOSI 5
#define MISO 6
#define CLK 7
#define SPI_Dir DDRB
#define SPI_PORT PORTB

#define Slave_En() (Clear_Bit(SPI_PORT,SS))
#define Slave_Dis() (Set_Bit(SPI_PORT,SS))



typedef struct{
	unsigned char PreScaler0:1;
	unsigned char BIT1:1;
	unsigned char BIT2:1;
	unsigned char BIT3:1;
	unsigned char MASTER:1;
	unsigned char BIT5:1;
	unsigned char EN:1;
	unsigned char IE:1;
}SPCR_Bits;

typedef enum{
	MASTER =0,
	SLAVE
}SPI_Status;

typedef enum{
	OSC4 = 4,
	OSC16 = 16
	
}SPI_PreScale;

typedef struct{
	SPI_Status State;
	SPI_PreScale Prescale;
	
}SPI_CFG;

typedef struct{
	unsigned char BIT0:1;
	unsigned char BIT1:1;
	unsigned char BIT2:1;
	unsigned char BIT3:1;
	unsigned char BIT4:1;
	unsigned char BIT5:1;
	unsigned char BIT6:1;
	unsigned char PIF:1;
}SPSR_Bits;


typedef struct{
	SPCR_Bits SPCR_Reg;
	SPSR_Bits SPSR_Reg;
	unsigned char SPDR_Reg;	
}SPI_Reg;

#define SPI ((volatile SPI_Reg* const)(0x2D))

void SPI_Init(SPI_CFG * config);
void SPI_Send(uint8 data);
uint8 SPI_SEND_GET(uint8 data);
void SPI_SendMany(uint8 data[]);
uint8 SPI_Get(void);
uint8 SPI_GetMany(void);




#endif /* SPI_H_ */