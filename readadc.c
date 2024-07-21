/*
 * readadc.c
 *
 * Created: 18/07/2024 23:02:32
 *  Author: 
 */ 
#include "readadc.h"

void ADC0(){
	ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX3));
}

void ADC1(){
	ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX3));
	ADMUX |= (1 << MUX0);
}

void ADC2(){
	ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX3));
	ADMUX |= (1 << MUX1);
}

void ADC3(){
	ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX3));
	ADMUX |= (1 << MUX0) | (1 << MUX1);
}

void ADC4(){
	ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX3));
	ADMUX |= (1 << MUX2);
}

void ADC5(){
	ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX3));
	ADMUX |= (1 << MUX0) | (1 << MUX2);
}

void ADC6(){
	ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX3));
	ADMUX |= (1 << MUX2) | (1 << MUX1);
}

void ADC7(){
	ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX3));
	ADMUX |= (1 << MUX0) | (1 << MUX1) | (1 << MUX2);
}

void init_adc(){
	ADCSRA |= (1 << ADPS2);										// ADPS0 - 0, ADPS1-0, ADPS2-1 (коэф.деления АЦП 16. Скорость чт. 16 мкс)
	ADCSRA &= ~((1 << ADPS1) | (1 << ADPS0));
}

uint16_t readadc(void(*pinADC)()){
	pinADC();
	return asm_readadc();
}