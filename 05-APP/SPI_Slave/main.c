/*
 * main.c
 *
 *  Created on: Dec 18, 2020
 *      Author: hussam
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "LCD_interface.h"

u8 x ,i ;

void fun (void)
{
	if (x == 1 )
	{
		LCD_voidDispChar('c');
	}
	else if (x == 2)
	{
		LCD_voidDispChar('d');
	}
}
int main ()
{
	LCD_voidInit();
	SPI_voidInit();
	SPI_voidIntruptEn(&fun);


	while (1)
	{
		x = SPI_u8SendRes(i);
		if (x == 1 )
			{
				LCD_voidDispChar('a');
			}
			else if (x == 2)
			{
				LCD_voidDispChar('b');
			}
	}

}

