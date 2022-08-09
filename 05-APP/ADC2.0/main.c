/*
 * main.c
 *
 *  Created on: Jan 20, 2021
 *      Author: hussam
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"


int main (void)
{
	LCD_voidInit();
	u16 temp;
	while(1)
	{
		ADC_voidinit(1);
		temp = ADC_u16Read();
		LCD_voidDispNumber(temp);
		ADC_voidinit(2);
		LCD_voidMoveCrusor(2,1);
		temp=ADC_u16Read();
		LCD_voidDispNumber(temp);
		LCD_voidClearScreen();
		LCD_voidMoveCrusor(1 , 1);
	}
}
