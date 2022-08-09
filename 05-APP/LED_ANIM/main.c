/*
 * main.c
 *
 *  Created on: Nov 26, 2020
 *      Author: hussam
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STP_interface.h"
#include "SWITCH_interface.h"

#define F_CPU 80000000UL
#include "util/delay.h"

int main(void)
{
	u8 i , j=0  , X , k;
	STP_voidIntit(GPIOA , 0 , GPIOA , 1 , GPIOA , 2 );
	SWITCH_voidInit(GPIOC , 0 );
	while(1){
		i = SWITCH_u8Read(GPIOC , 0);
		if (i == 0 )
		{
			_delay_ms (25);
			X =0 ;
			X = j%10 ;
			k = j/10 ;
			X &= 0x0F ;
			X |= k << 4;
			STP_voidSend(X);
			j++ ;
			if (j == 100)
			{
				j = 0;
			}

		}


	}

}

