/*
 * main.c
 *
 *  Created on: Dec 15, 2020
 *      Author: hussam
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "LED_interface.h"

#define F_CPU 8000000UL
#include  "util/delay.h"

int main()
{

	while (1)
	{

			LED_voidTurnOn(GPIOA , 0);
			_delay_ms(500);
			LED_voidTurnOff(GPIOA,0);
			_delay_ms(500);
	}

}
