/*
 * asmpulsein.asm
 *
 * Created: 18/07/2024 23:00:10
 *  Author: 
 */ 
#include "asmpulsein.h"
#include <avr/io.h>

.global asm_pulsein

asm_pulsein:
		ldi r20, 0xC1			// ������������� ������� ������� 1 (ICNC-1, ICES-1, CS1-1)
		sts TCCR1B, r20

wait_front:						// ���� �������� ������� �� ������
		ldi r22, 0x20
		lds r23, TIFR1
		and r23, r22			// ��������� ��������� �� ���� ICF1 (������ ������)
		tst r23 
		breq wait_front			// �������� ����������� ����� ICF1
		
		ldi r21, 0x20			// ���������� ICF1 ����������� = 1
		sts TIFR1, r21
		lds r30, ICR1L			// ��������� ������� �������� ������� �� ������ r31r30
		lds r31, ICR1H 

		ldi r20, 0x81			// ������������� ������ �� ����� ICNC-1, ICES-0, CS1-1
		sts TCCR1B, r20

wait_drop:						// ���� �������� ������� �� �����
		ldi r18, 0x20			
		lds r19, TIFR1
		and r19, r18			// ��������� ��������� �� ���� ICF1 (������ �����)
		tst r19 
		breq wait_drop			// �������� ����������� ����� ������� ICF1

		ldi r20, 0x20			// ���������� ICF1 ����������� = 1
		sts TIFR1, r20
		lds r24, ICR1L			// ��������� ������� �������� ������� �� ������ r25r24
		lds r25, ICR1H 

		sub r24, r30			// �������� �������� �������� �������� ������� a = T����� - T������ 
		sbc r25, r31

		ret