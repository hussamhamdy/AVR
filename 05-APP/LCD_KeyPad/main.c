/*
 * main.c
 *
 *  Created on: Nov 8, 2020
 *      Author: hussam
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"

int main (void)
{
	LCD_voidInit();
	Keypad_voidinit(GPIOD);
	u8 KEY;
	u8 num [1] ;
	num [1]= 2 ;
	while(1)
	{
		KEY = Keypad_voidCheckVal(GPIOD);
		if (KEY != NOTPRESSED)
		{

		LCD_voidDispString();
		_delay_ms(400);
	}

	}
}
