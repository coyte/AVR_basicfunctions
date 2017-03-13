/*
 * timer.h
 *
 *  Created on: 13 Mar 2017
 *      Author: niels@teekens.info
 */

#include <avr/io.h>
#include <avr/interrupt.h>

//Prototypes

void Timer0_Init(void);
void Timer0_Start(void);
ISR( TIMER0_COMPA_vect );
