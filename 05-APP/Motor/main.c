/*
 * main.c
 *
 *  Created on: Dec 15, 2020
 *      Author: hussam
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "EXTI_interface.h"

#include "SWITCH_interface.h"
#include "LED_interface.h"

void fun (void)
{
	LED_voidTogLed(GPIOB , 0);
}

int main ()
{
	SWITCH_voidInterrupt(EXTI_INT0 , &fun);

	while (1)
	{

	}
}
