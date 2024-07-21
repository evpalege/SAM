/*
 * meander.c
 *
 * Created: 20/07/2024 22:24:03
 *  Author:
 */ 
#include <avr/interrupt.h>
#include "meander.h"

ISR(TIMER2_OVF_vect) {											// вектор прерывания таймера2
	PORTD ^= (1 << PD3);
}

void init_meander(){
	DDRD |= (1 << DDD3);
	PORTD |= (1 << PD3);										// пин меандра
}

void start_meander(){
	TCNT2 = 0;													// обнуление счетчика
	TIMSK2 |= (1 << TOIE2);										// включение прерывания по переполнению
	TCCR2B |= (1 << CS22) |(1 << CS21) | (1 << CS20);			// предделитель таймера 1024 и запуск таймера
}

void stop_meander(){
	TCNT2 = 0;													// обнуление счетчика
	TIMSK2 &= ~(1 << TOIE2);									// включение прерывания по переполнению
	TCCR2B &= ~(1 << CS22) |(1 << CS21) | (1 << CS20);			// предделитель таймера 1024 и запуск таймера
}