/*
 * main.c
 *
 *  Created on: Oct 10, 2020
 *      Author: hussam
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"

int main (void)
{
	GPIO_voidSetPinDDR(GPIOA,0,OUTPUT);
while (1){
	GPIO_voidTogPin(GPIOA,0);

}
return 0;
}
