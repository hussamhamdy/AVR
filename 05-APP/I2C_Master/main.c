/*
 * main.c
 *
 *  Created on: Dec 24, 2020
 *      Author: hussam
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "I2C_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

int main()

{
	u8 counter ;
	I2C_voidInit(50000);
	while (counter <10){
	_delay_ms(500);
	I2C_voidStart();
	I2C_voidWriteAddress(0b10100000);

	I2C_voidWriteData(counter +0b00000000);
	I2C_voidWriteData(counter );
	I2C_voidStop();


	counter ++ ;
	}







}
