/*
 * main.c
 *
 *  Created on: Oct 16, 2020
 *      Author: hussam
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SWITCH_interface.h"
#include "SEVSEG_interface.h"
#include "LED_interface.h"
#define F_CPU 8000000UL
#include  "util/delay.h"
#define Sec 1000
#define Min 600
#define Hour 600
u8 i ;

int main (void)
{
	SEVSEG_voidInitBcd (GPIOA , LOW_NIPPLE);
	SEVSEG_voidInitBcd (GPIOA , HIGH_NIPPLE);


	u8 i ,j ;
	while (1)
		{
		for (j=0 ; j<=9 ; j++)
		{
			SEVSEG_WriteBcd  (GPIOA , HIGH_NIPPLE ,j);
			for (i=0 ; i<=9 ; i++)
				{
				SEVSEG_WriteBcd  (GPIOA , LOW_NIPPLE ,i);
				_delay_ms(Sec);

				}


			}
		}


}



