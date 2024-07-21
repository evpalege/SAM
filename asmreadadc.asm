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

wait_adc:						// цикл ожидания преобразования АЦП
		ldi r18, 0xBF			
		lds r19, ADCSRA
		and r19, r18			// проверка окончания (ADSC = 0?)
		com r19
		tst r19 
		breq wait_adc			// Если ADSC = 0 - спукаемся ниже)

		lds r24, ADCL			// сохраняем значение регистра АЦП
		lds r25, ADCH 
		andi r25, 0x03			// маска очистки старших значений

		ret