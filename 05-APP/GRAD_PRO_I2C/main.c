/*
 * main.c
 *
 *  Created on: Dec 16, 2021
 *      Author: Hussam Hamdy
 */


#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "UART_interface.h"
#include "I2C_interface.h"


int main ()
{
	u8 x ;
	USART_voidInit(9600);
	I2C_voidInit(50000);

	while(1)
	{
		x =USART_u8RecieveByte();
		if(x == 5 ){
		I2C_voidStart();
			I2C_voidWriteAddress(0b10100000);

			I2C_voidWriteData(0b00000000);
			I2C_voidWriteData(x);
			I2C_voidStop();
		}
	}
}
