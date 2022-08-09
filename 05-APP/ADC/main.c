/*
 * main.c
 *
 *  Created on: Nov 11, 2020
 *      Author: hussam
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "LM35_interface.h"

#include "util/delay.h"
#define F_CPU 8000000UL



int main (void)
{


	LCD_voidInit();

	u8 temp ;
	u16 Volt ;
	while(1)
	{
	ADC_voidInit(ADC1);
	Volt = ADC_u16Read();
	_delay_ms(1000);
	LM35_voidInit(ADC1);
	temp = LM35_voidRead();
	LCD_voidMoveCrusor(1,1);
	LCD_voidDispString("VOLtage =");
	LCD_voidDispNumber(Volt);
	LCD_voidMoveCrusor(2,1);
	LCD_voidDispNumber(temp);
	LCD_voidDispString("  0C");
	}

}
