/*
 * main.c
 *
 *  Created on: Oct 30, 2020
 *      Author: hussam
 */

#include  "BIT_MATH.h"
#include  "STD_TYPES.h"

#include "GPIO_interface.h"
#include "LED_interface.h"
#include "SWITCH_interface.h"
#include "EXTI_interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"

void fun (void)
{
	LED_voidTurnOn(GPIOA , 2);
	_delay_ms(400);
	LED_voidTurnOff(GPIOA,2);
}
int main()
{
	SWITCH_voidInterrupt(EXTI_INT0 , &fun);
	while (1)
	{

	}
}
