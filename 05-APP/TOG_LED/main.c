/*
 * main.c
 *
 *  Created on: Oct 13, 2020
 *      Author: hussam
 */

#include "STD_TYPES.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "LED_interface.h"
#include "SWITCH_interface.h"

int main(void){
	SWITCH_voidIntit(GPIOB,0);
	while (1)
	{
		u8 Local_u8returnValue ;
		Local_u8returnValue = SWITCH_u8Read(GPIOB,0);
		if (Local_u8returnValue == 0){
			GPIO_voidSetPinDDR (GPIOA , 0 , OUTPUT);
			GPIO_voidTogPin (GPIOA,0);
		}
	}

	return 0;
}
