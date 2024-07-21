/*
 * millis.c
 *
 * Created: 18/07/2024 23:00:10
 *  Author: 
 */ 
#include <avr/interrupt.h>
#include "millis.h"

volatile uint64_t tick;						// ���������� ��� ������ ������� � ��
volatile uint64_t *pTick = &tick;		

void init_millis(){
	TIMSK0 = (1 << TOIE0);					// �������� timer0
	TCCR0B = (1 << CS01) | (1 << CS00);		// ������������ 1/64
	// �� 16M�� ������ � ��������� �� 64, ���������� �� ������������ �������� ����� ���������� � �������� 1���, �.�. ������ ����� ����� ��������� ����� ������������
	//sei();
}

uint64_t millis(){
	return *pTick;
}

ISR(TIMER0_OVF_vect){
	tick++;
}