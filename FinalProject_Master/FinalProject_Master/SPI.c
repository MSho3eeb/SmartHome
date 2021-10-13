/*
 * SPI.c
 *
 * Created: 8/10/2020 1:20:01 PM
 *  Author: Mohamed Teleb
 */ 

#include "SPI.h"
void SPI_Init(SPI_CFG * config){//m for master , s for slave
	switch(config->State){
		case MASTER:
		Set_Bit(SPI_Dir,SS);
		Set_Bit(SPI_Dir,MOSI);
		Set_Bit(SPI_Dir,CLK);
		Clear_Bit(SPI_Dir,MISO);
		Slave_Dis();
		
		SPI->SPCR_Reg.MASTER = 1;
		break;
		case SLAVE:
		Clear_Bit(SPI_Dir,SS);
		Clear_Bit(SPI_Dir,MOSI);
		Clear_Bit(SPI_Dir,CLK);
		Set_Bit(SPI_Dir,MISO);
		break;
	}
	switch(config->Prescale){
		case OSC4:
		
		break;
		case OSC16:
		SPI ->SPCR_Reg.PreScaler0 = 1;
		break;
	}
	
	//deh a7sn
		
	SPI->SPCR_Reg.EN = 1;
	

}
void SPI_Send(uint8 data){
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

uint8 SPI_Get(void){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

void SPI_SendMany(uint8 data[]){
	uint8 i = 0;
	while(data[i] != '\0'){
		SPI_Send(data[i]);
		i++;
	}
}

uint8 SPI_SEND_GET(uint8 data){
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}