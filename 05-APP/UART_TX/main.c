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

#include "SWITCH_interface.h"

int main ()
{
	u8 x ;
	USART_voidInit(9600);
	SWITCH_voidInit(GPIOB , 0);
	while(1)
	{
	x=	SWITCH_u8Read(GPIOB , 0);
	while (x == 0 )
	{
		USART_voidSendByte(1);
		x=1;
	}

	}
}
