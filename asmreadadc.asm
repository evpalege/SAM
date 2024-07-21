/*
 * asmreadadc.asm
 *
 * Created: 18/07/2024 23:00:10
 *  Author: 
 */ 
#include "asmreadadc.h"
#include <avr/io.h>

.global asm_readadc

 asm_readadc:
		ldi r20, 0xC0
		sts ADCSRA, r20

wait_adc:						// ���� �������� �������������� ���
		ldi r18, 0xBF			
		lds r19, ADCSRA
		and r19, r18			// �������� ��������� (ADSC = 0?)
		com r19
		tst r19 
		breq wait_adc			// ���� ADSC = 0 - ��������� ����)

		lds r24, ADCL			// ��������� �������� �������� ���
		lds r25, ADCH 
		andi r25, 0x03			// ����� ������� ������� ��������

		ret