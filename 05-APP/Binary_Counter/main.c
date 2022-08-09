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
GPIO_voidSetPortDDR(GPIOA,OUTPUT);
	while (1)
	{
		for (counter = 0 ; counter <= 255 ; counter ++)
		{

			GPIO_voidWritePort(GPIOA,counter);
			_delay_ms(500);
		}
	}

}
