/*
* DIO.c
*
* Created: 7/10/2020 9:04:07 PM
*  Author: Mohamed Teleb
*/

#include "DIO.h"



void DIO_Write(DIO_ChannelTypes ChannelID,STD_Level Level){
	DIO_PortTypes portx = ChannelID / 8;
	DIO_ChannelTypes channelpos = ChannelID %8;
	switch(portx){
		case DIO_PortA:
		if(Level == STD_High){
			Set_Bit(PortA_Reg, channelpos);
			}else{
			Clear_Bit(PortA_Reg,channelpos);
		}
		break;
		case DIO_PortB:
		if(Level == STD_High){
			Set_Bit(PortB_Reg, channelpos);
			}else{
			Clear_Bit(PortB_Reg,channelpos);
		}
		break;
		case DIO_PortC:
		if(Level == STD_High){
			Set_Bit(PortC_Reg, channelpos);
			}else{
			Clear_Bit(PortC_Reg,channelpos);
		}
		break;
		case DIO_PortD:
		if(Level == STD_High){
			Set_Bit(PortD_Reg, channelpos);
			}else{
			Clear_Bit(PortD_Reg,channelpos);
		}
		break;
		
	}
}

uint8 DIO_Read(DIO_ChannelTypes channel){
	DIO_PortTypes portx = channel/8;
	DIO_ChannelTypes channelpos = channel %8;
	switch(portx){
		case DIO_PortA:
		return Get_Bit(PINA_Reg, channelpos);
		break;
		case DIO_PortB:
		return Get_Bit(PINB_Reg, channelpos);
		break;
		case DIO_PortC:
		return Get_Bit(PINC_Reg, channelpos);
		break;
		case DIO_PortD:
		return Get_Bit(PIND_Reg, channelpos);
		break;
		
	}
}
void DIO_Invert(DIO_ChannelTypes ChannelID,STD_Level Level){
	DIO_PortTypes portx = ChannelID / 8;
	DIO_ChannelTypes channelpos = ChannelID %8;
	switch(portx){
		case DIO_PortA:
		if(Level == STD_High){
			Toggle_Bit(PortA_Reg, channelpos);
			}else{
			Clear_Bit(PortA_Reg,channelpos);
		}
		break;
		case DIO_PortB:
		if(Level == STD_High){
			Toggle_Bit(PortB_Reg, channelpos);
			}else{
			Clear_Bit(PortB_Reg,channelpos);
		}
		break;
		case DIO_PortC:
		if(Level == STD_High){
			Toggle_Bit(PortC_Reg, channelpos);
			}else{
			Clear_Bit(PortC_Reg,channelpos);
		}
		break;
		case DIO_PortD:
		if(Level == STD_High){
			Toggle_Bit(PortD_Reg, channelpos);
			}else{
			Clear_Bit(PortD_Reg,channelpos);
		}
		break;
		
	}
}

void DIO_WritePort (DIO_PortTypes Portx, uint8 data){
	switch(Portx){
		case DIO_PortA:
			PortA_Reg = data;
		break;
		case DIO_PortB:
			PortB_Reg = data;
		break;
		case DIO_PortC:
			PortC_Reg = data;
		break;
		case DIO_PortD:
			PortD_Reg = data;
		break;
	}
}