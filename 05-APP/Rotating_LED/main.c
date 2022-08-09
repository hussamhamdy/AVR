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
u8 counter ;
	while (1)
	{
		for (counter = 0 ; counter <= 7 ; counter ++)
		{
			LED_voidTurnOn(GPIOA , counter);
			_delay_ms(300);
			LED_voidTurnOff(GPIOA,counter);
		}
	}

}
