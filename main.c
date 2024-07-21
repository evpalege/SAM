/*
 * main.c
 *
 * Created: 18/07/2024 23:00:10
 *  Author: 
 */ 
#define F_CPU 16000000UL

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "asmpulsein.h"
#include "asmreadadc.h"
#include "readadc.h"
#include "millis.h"
#include "meander.h"


#define FALSE (0)
#define TRUE  !FALSE
typedef char bool;
// bool flag = FALSE; 

volatile uint16_t a;
volatile uint16_t b;
volatile uint32_t c;

extern uint16_t asm_pulsein();
extern uint16_t asm_readadc();

int main(void)
{
	init_millis();
	init_adc();
	init_meander();	
	start_meander();
	
	sei();
	
    while(1){
		a = asm_pulsein();
		b = readadc(ADC7);
		c = millis();
	}
	
}