/*
 * main.c
 *
 *  Created on: Oct 23, 2020
 *      Author: hussam
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "LED_interface.h"
#include "SWITCH_interface.h"
#define F_CPU 8000000UL
#include "util/delay.h"

int main (void)
{
SWITCH_voidInit(GPIOB , 0);
u8 SW ;
while (1){
	SW = SWITCH_u8Read(GPIOB , 0);
	if (SW == 0)
	{
		LED_voidTurnOn(GPIOA , 0);

	}
	else
	{
		LED_voidTurnOff(GPIOA , 0 );
	}

	}

}

