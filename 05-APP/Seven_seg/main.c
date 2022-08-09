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
#include "SEVSEG_interface.h"
u8 counter = 0 , dec ;
void fun (void)
{
	counter ++ ;
}

int main ()
{
	SWITCH_voidIntit(GPIOD , 2);
	SWITCH_voidInterrupt(EXTI_INT0 , &fun);
	SEVSEG_voidInitBcd(GPIOB , LOW_NIPPLE);
	SEVSEG_voidInitBcd(GPIOA , LOW_NIPPLE);

	while (1)
	{
	SEVSEG_WriteBcd(GPIOB , LOW_NIPPLE ,counter/10);
	SEVSEG_WriteBcd(GPIOA , LOW_NIPPLE ,counter%10);
	if (counter == 100)
	{
		counter = 0 ;
	}
	}
}
