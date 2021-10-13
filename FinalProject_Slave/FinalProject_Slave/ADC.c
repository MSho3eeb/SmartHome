/*
 * ADC.c
 *
 * Created: 7/24/2020 10:10:03 PM
 *  Author: Mohamed Teleb
 */ 


#include "ADC.h"
void ADC_Init(void){
	/*ADMUX = (1<<REFS0) | (1<<REFS1) ;
	ADCSRA = (1<<ADEN) | (1<<ADATE) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2) | (1<<ADIE); 
	*/
	// AREF = AVcc
	ADMUX = (1<<REFS0);

	// ADC Enable and prescaler of 128
	
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

unsigned short ADC_Read(unsigned char channel){
	/*unsigned short data =0;
	ADMUX = (ADMUX & 0xE0) | (channel & 0x1F);
	ADCSRA |= (1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)));
	
	ADCSRA |= (1<<ADIF);
	
	data = ADCL;
	data |= ADCH << 8;
	
	return data;*/
	// select the corresponding channel 0~7
	
	channel &= 0b00000111;  // AND operation with 7
	ADMUX = (ADMUX & 0xF8)|channel;

	// start single conversion
	// write '1' to ADSC
	ADCSRA |= (1<<ADSC);

	// wait for conversion to complete
	// ADSC becomes '0' again
	
	while(ADCSRA & (1<<ADSC));

	return (ADC);
}