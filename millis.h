/*
 * millis.h
 *
 * Created: 18/07/2024 23:02:32
 *  Author: 
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef MILLIS
#define MILLIS

uint64_t millis();
void init_millis();

#endif