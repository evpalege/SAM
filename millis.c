/*
 * millis.c
 *
 * Created: 18/07/2024 23:00:10
 *  Author: 
 */ 
#include <avr/interrupt.h>
#include "millis.h"

volatile uint64_t tick;						// переменная для записи времени в мс
volatile uint64_t *pTick = &tick;		

void init_millis(){
	TIMSK0 = (1 << TOIE0);					// включаем timer0
	TCCR0B = (1 << CS01) | (1 << CS00);		// предделитель 1/64
	// На 16MГц кварце и делителем на 64, прерывание по переполнению счетчика будет вызаваться с частотой 1КГц, т.е. каждый вызов будет равняться одной миллисекунде
	//sei();
}

uint64_t millis(){
	return *pTick;
}

ISR(TIMER0_OVF_vect){
	tick++;
}