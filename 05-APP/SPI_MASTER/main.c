/*
 * main.c
 *
 *  Created on: Dec 18, 2020
 *      Author: hussam
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SWITCH_interface.h"
#include "EXTI_interface.h"
#define F_CPU 8000000UL
#include "util/delay.h"


int main ()
{
	SPI_voidInit();
	SWITCH_voidInit(GPIOA , 0);
	SWITCH_voidInit(GPIOA , 1);
	u8 SW1 , SW2  , temp =0 ;
	while (1)
	{
		SW1 =	SWITCH_u8Read(GPIOA ,  0);
		SW2 = SWITCH_u8Read(GPIOA , 1);

		if (SW1 == 0)
		{
			temp = SPI_u8SendRes(1);
		}
		if (SW2 == 0)
		{
			temp = SPI_u8SendRes(2);
		}
	}

	}

