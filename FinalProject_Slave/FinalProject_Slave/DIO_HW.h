/*
 * DIO_HW.h
 *
 * Created: 7/10/2020 8:55:57 PM
 *  Author: Mohamed Teleb
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_

#include "STD_Types.h"
//PortA
#define PortA_Reg (*((uint8*)0x3B))
#define DDRA_Reg (*((uint8*)0x3A))
#define PINA_Reg (*((uint8*)0x39))
//PortB
#define PortB_Reg (*((uint8*)0x38))
#define DDRB_Reg (*((uint8*)0x37))
#define PINB_Reg (*((uint8*)0x36))
//PortC
#define PortC_Reg (*((uint8*)0x35))
#define DDRC_Reg (*((uint8*)0x34))
#define PINC_Reg (*((uint8*)0x33))
//PortD
#define PortD_Reg (*((uint8*)0x32))
#define DDRD_Reg (*((uint8*)0x31))
#define PIND_Reg (*((uint8*)0x30))




#endif /* DIO_HW_H_ */