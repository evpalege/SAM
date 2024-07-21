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
		ldi r20, 0xC1			// инициализация захвата таймера 1 (ICNC-1, ICES-1, CS1-1)
		sts TCCR1B, r20

wait_front:						// цикл ожидания захвата по фронту
		ldi r22, 0x20
		lds r23, TIFR1
		and r23, r22			// проверяем выставлен ли флаг ICF1 (захват фронта)
		tst r23 
		breq wait_front			// ожидание выставления флага ICF1
		
		ldi r21, 0x20			// сбрасываем ICF1 установокой = 1
		sts TIFR1, r21
		lds r30, ICR1L			// сохраняем счетчик регистра таймера по фронту r31r30
		lds r31, ICR1H 

		ldi r20, 0x81			// устанавливаем захват по спаду ICNC-1, ICES-0, CS1-1
		sts TCCR1B, r20

wait_drop:						// цикл ожидания захвата по спаду
		ldi r18, 0x20			
		lds r19, TIFR1
		and r19, r18			// проверяем выставлен ли флаг ICF1 (захват спада)
		tst r19 
		breq wait_drop			// ожидание выставления флага захвата ICF1

		ldi r20, 0x20			// сбрасываем ICF1 установокой = 1
		sts TIFR1, r20
		lds r24, ICR1L			// сохраняем счетчик регистра таймера по фронту r25r24
		lds r25, ICR1H 

		sub r24, r30			// вычитаем значения счетчика регистра таймера a = Tспада - Tфронта 
		sbc r25, r31

		ret