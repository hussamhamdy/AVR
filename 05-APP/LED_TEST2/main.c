/*
 * main.c
 *
 *  Created on: Oct 31, 2020
 *      Author: hussam
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "LED_interface.h"

int main (void)
{
	while (1)
	{
	LED_voidTurnOn(GPIOA , 2);
	}
}
