/*
* DIO_CFG.h
*
* Created: 7/10/2020 9:22:50 PM
*  Author: Mohamed Teleb
*/


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "BIt_Math.h"
#include "STD_Types.h"
#define PinCount 32

typedef struct {
	DIO_DIR PinDir;
	STD_Level PinLevel;
}DIO_PinCFG;

void DIO_InIt(void);

#endif /* DIO_CFG_H_ */