#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void partirMinuterieCTC ( uint32_t duree, volatile uint8_t& minuterieExpiree ); 