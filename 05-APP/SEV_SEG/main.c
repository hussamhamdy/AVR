/*
 * main.c
 *
 *  Created on: Oct 14, 2020
 *      Author: hussam
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SEVSEG_interface.h"
#include "SWITCH_interface.h"
#define F_CPU 8000000UL
#include "util/delay.h"

int main (void){
	SEVSEG_voidInit(GPIOA);
	u8 i=0 , Local_u8button1 , Local_u8button2 ;
	SWITCH_voidIntit(GPIOC , 0);
	SWITCH_voidIntit(GPIOC , 1);
	while (1){
		Local_u8button1 = SWITCH_u8Read(GPIOC, 0 );
		if (Local_u8button1 ==0){
			i++;
			if (i == 11) {i = 0 ;}
			_delay_ms(200);


		SEVSEG_voidDisp(GPIOA , i);
	}


	Local_u8button2 = SWITCH_u8Read(GPIOC, 1 );
			if (Local_u8button2 ==0){
				i--;
				if (i == 0) {i = 10 ;}
				_delay_ms(200);


			SEVSEG_voidDisp(GPIOA , i);

			}
}

}
