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
#include "LCD_interface.h"


#define F_CPU 8000000UL
#include <util/delay.h>
int main()
{
	u8 X  , counter;
//	_delay_ms(25000);
	LCD_voidInit();
	I2C_voidSetAddress(0xE0);
	I2C_voidInit(50000);

	while (counter <10){
		_delay_ms(500);
		I2C_voidStart(); // transmit start condition
			I2C_voidWriteAddress(0b10100000); // transmit device address and Write
			I2C_voidWriteData(0x00); // transmit word address
			I2C_repeated_start(); // transmit repeated start condition
			I2C_write_address_and_read(0b10100001); // transmit device address and read
			X =I2C_read_with_NACK();
			I2C_voidStop();
			LCD_voidDispChar(X+38);
		counter ++ ;
	}
}
