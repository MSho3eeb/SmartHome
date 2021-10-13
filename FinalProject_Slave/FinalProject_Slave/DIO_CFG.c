/*
* DIO_CFG.c
*
* Created: 7/10/2020 9:23:07 PM
*  Author: Mohamed Teleb
*/

#include "DIO_CFG.h"

const DIO_PinCFG pinCFG[]={
	//portA
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	//portB
	{Output,STD_High},//0
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Input,STD_High},
	{Input,STD_High},
	{Output,STD_High},
	{Input,STD_High},
	//portC
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	//portD
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High}
};




void DIO_InIt(void){
	DIO_PortTypes portx;
	DIO_ChannelTypes channelpos;
	uint8 count = 0;
	
	for(count = DIO_ChannelA0; count<PinCount ;count++){
		portx = count/8;
		channelpos = count % 8;
		switch(portx){
			case DIO_PortA:
			if(pinCFG[count].PinDir == Output){
				Set_Bit(DDRA_Reg, channelpos);
				}else{
				Clear_Bit(DDRA_Reg,channelpos);
			}
			break;
			case DIO_PortB:
			if(pinCFG[count].PinDir == Output){
				Set_Bit(DDRB_Reg, channelpos);
				}else{
				Clear_Bit(DDRB_Reg,channelpos);
			}
			break;
			case DIO_PortC:
			if(pinCFG[count].PinDir == Output){
				Set_Bit(DDRC_Reg, channelpos);
				}else{
				Clear_Bit(DDRC_Reg,channelpos);
			}
			break;
			case DIO_PortD:
			if(pinCFG[count].PinDir == Output){
				Set_Bit(DDRD_Reg, channelpos);
				}else{
				Clear_Bit(DDRD_Reg,channelpos);
			}
			break;
			
		}
	}
}