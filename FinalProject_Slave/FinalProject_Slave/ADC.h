/*
 * ADC.h
 *
 * Created: 7/24/2020 10:10:23 PM
 *  Author: Mohamed Teleb
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>


void ADC_Init(void);
unsigned short ADC_Read(unsigned char channel);



#endif /* ADC_H_ */