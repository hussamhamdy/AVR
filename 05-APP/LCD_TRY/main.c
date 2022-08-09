/*
 * main.c
 *
 *  Created on: Oct 31, 2020
 *      Author: hussam
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "LCD_interface.h"
#include "EXTI_interface.h"
#include "SWITCH_interface.h"
#include "KEYPAD_interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"

int main (void)
{
	LCD_voidInit();
	Keypad_voidinit(GPIOD);
	u8 Key;
	while (1)
	{
		if (Key != 256)
		{
			Key = Keypad_voidCheckVal(GPIOD);
			LCD_voidDispChar(Key);
		}
	}








}

