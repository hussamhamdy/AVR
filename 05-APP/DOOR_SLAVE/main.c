/*
 * main.c
 *
 *  Created on: Mar 26, 2021
 *      Author: hussam
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "LED_interface.h"
#include "Hbridge_interface.h"
#include "I2C_interface.h"



#include "util/delay.h"
#define F_CPU 8000000UL




#define HB1 0
#define HB2 1
int main (void)
{
	I2C_voidInit(50000);
	I2C_voidSetAddress(0xCC);
	GPIO_voidSetLowNippleDDR(GPIOA,OUTPUT);
	u8 Status ;
	while (1)
	{
		Status = I2C_u8SlaveRead();
		switch(Status)
		{
		case  3 :
			GPIO_voidWriteLowNipple(GPIOA,8);
			Hbridge_voidCW(GPIOB ,HB1 , HB2);
			_delay_ms(50);
			Hbridge_voidSTOP(GPIOB ,HB1 , HB2);
			break;
		case 2 :
			GPIO_voidWriteLowNipple(GPIOA,1);
			Hbridge_voidACW(GPIOB ,HB1 , HB2);
			_delay_ms(50);
			Hbridge_voidSTOP(GPIOB ,HB1 , HB2);
			break;
		case 1 :
			GPIO_voidWriteLowNipple(GPIOA,3);
			Hbridge_voidACW(GPIOB ,HB1 , HB2);
			_delay_ms(50);
			Hbridge_voidSTOP(GPIOB ,HB1 , HB2);
			break;
		case 0:
			GPIO_voidWriteLowNipple(GPIOA,7);
			Hbridge_voidACW(GPIOB ,HB1 , HB2);
			_delay_ms(50);
			Hbridge_voidSTOP(GPIOB ,HB1 , HB2);
			break;
		case 8 :
			GPIO_voidWriteLowNipple(GPIOA,8);
			Hbridge_voidACW(GPIOB ,HB1 , HB2);
			_delay_ms(50);
			Hbridge_voidSTOP(GPIOB ,HB1 , HB2);
			break;



		}
		*((volatile u8*)0x23) = 0xFF;
	}

}
