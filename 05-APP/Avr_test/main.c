/*
 * main.c
 *
 *  Created on: Oct 4, 2020
 *      Author: Hussam
 */

#include "avr/io.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void){
	DDRA =0xff ;



	while (1)
	{

		PORTA=0x01;
		_delay_ms(1000);
		PORTA=0x02;
		_delay_ms(1000);
		PORTA=0x04;
		_delay_ms(1000);
		PORTA=0x08;
		_delay_ms(1000);
		PORTA=0x10;
		_delay_ms(1000);
		PORTA=0x20;
		_delay_ms(1000);
		PORTA=0x40;
		_delay_ms(1000);
		PORTA=0x80;
		_delay_ms(1000);
	}
	return 0;
}
