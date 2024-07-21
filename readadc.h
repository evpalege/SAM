/*
 * readadc.h
 *
 * Created: 18/07/2024 23:02:32
 *  Author: 
 */ 
#include <avr/io.h>
#include "asmreadadc.h"

#ifndef READADC
#define READADC

void ADC0();
void ADC1();
void ADC2();
void ADC3();
void ADC4();
void ADC5();
void ADC6();
void ADC7();
void init_adc();
uint16_t readadc(void(*pinADC)());

#endif