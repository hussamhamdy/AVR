/*
 * main.c
 *
 *  Created on: Dec 17, 2020
 *      Author: hussam
 */


#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "UART_interface.h"


int main ()
{
	u8 x ;
	USART_voidInit(9600);
	GPIO_voidSetPinDDR(GPIOA , 0 , OUTPUT);
	while(1)
	{
	x=	USART_u8RecieveByte();
	if (x == 1 )
	{
		GPIO_voidTogPin(GPIOA , 0);
		x = 0 ;
	}
	}
}
