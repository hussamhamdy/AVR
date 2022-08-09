/*
 * main.c
 *
 *  Created on: Oct 10, 2020
 *      Author: hussam
 */
/*
 * main.c
 *
 *  Created on: Oct 10, 2020
 *      Author: hussam
 */
#include "stdio.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "LED_interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"
int main (void)
{
	u8 i , j;
for(i=0;i<200;i++){

printf("HI");
	for (i=0 ; i<8 ; i++){
	LED_voidTurnOn(GPIOA,i);
	_delay_ms(50);
		}
	for (j=7 ; j>=0 ; j--){
		LED_voidTurnOff(GPIOA,j);
		_delay_ms(50);
			}
}
/*
	for (i=0 ; i<4 ; i++){
		LED_voidTurnOn(GPIOA,i);
		LED_voidTurnOn(GPIOA,(7-i));
		_delay_ms(50);
	}
	for (i=4 ; i>=0 ; i--){
			LED_voidTurnOff(GPIOA,i);
			LED_voidTurnOff(GPIOA,(7-i));
			_delay_ms(50);
		}
*/





return 0;
}

