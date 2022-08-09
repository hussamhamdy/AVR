/*
 * main.c
 *
 *  Created on: Oct 12, 2020
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
	SWITCH_voidIntit(GPIOC , 0);
	SWITCH_voidIntit (GPIOC ,1);
	u8 Local_u8Button1  , Local_u8Button2 ;
	u8 i , j;
	while (1){
		Local_u8Button1 = SWITCH_u8Read(GPIOC , 0);
		Local_u8Button2 = SWITCH_u8Read(GPIOC , 1);

		if (Local_u8Button1 == 0){

			for (i=0 ; i<8 ; i++)
				{
			LED_voidTurnOn(GPIOA,i);
			_delay_ms(50);
				}
			for (j=8 ; j>0 ; j--)
				{
				LED_voidTurnOff(GPIOA,j-1);
				_delay_ms(50);
				}
		}
		else if (Local_u8Button2 == 0){
			for (i=0 ; i<4 ; i++)
				{
					LED_voidTurnOn(GPIOA,i);
					LED_voidTurnOn(GPIOA,(7-i));
					_delay_ms(50);
				}
				for (i=5 ; i>0 ; i--)
					{
						LED_voidTurnOff(GPIOA,i-1);
						LED_voidTurnOff(GPIOA,8-i);
						_delay_ms(50);
					}
		}
		else{
			GPIO_voidSetPortDDR (GPIOA , OUTPUT);
			GPIO_voidWritePort (GPIOA , 0);

		}
	}
}

