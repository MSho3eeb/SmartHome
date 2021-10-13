/*
 * DIO.h
 *
 * Created: 7/10/2020 9:03:57 PM
 *  Author: Mohamed Teleb
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "DIO_HW.h"
#include "DIO_CFG.h"
#include "DIO_Types.h"
#include "BIt_Math.h"
#include "STD_Types.h"

void DIO_Write(DIO_ChannelTypes ChannelID,STD_Level Level);
uint8 DIO_Read(DIO_ChannelTypes channel);
void DIO_Invert(DIO_ChannelTypes ChannelID,STD_Level Level);
void DIO_WritePort (DIO_PortTypes Portx, uint8 data);


#endif /* DIO_H_ */