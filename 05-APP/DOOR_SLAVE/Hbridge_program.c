/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 23 Mar 2021								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"
#include "GPIO_interface.h"




void Hbridge_voidCW(u8 copy_u8port , u8 copy_u8pin1,u8 copy_u8pin2)
{
	GPIO_voidSetPinDDR(copy_u8port , copy_u8pin1 , OUTPUT);
	GPIO_voidSetPinDDR(copy_u8port , copy_u8pin2 , OUTPUT);
	GPIO_voidWritePin(copy_u8port, copy_u8pin1 , LOW);
	GPIO_voidWritePin(copy_u8port, copy_u8pin2 , HIGH);


	
}
void Hbridge_voidACW(u8 copy_u8port , u8 copy_u8pin1,u8 copy_u8pin2)
{
	GPIO_voidSetPinDDR(copy_u8port , copy_u8pin1 , OUTPUT);
	GPIO_voidSetPinDDR(copy_u8port , copy_u8pin2 , OUTPUT);
	GPIO_voidWritePin(copy_u8port, copy_u8pin1 , HIGH);
	GPIO_voidWritePin(copy_u8port, copy_u8pin2 , LOW);
	
}
void Hbridge_voidSTOP(u8 copy_u8port , u8 copy_u8pin1,u8 copy_u8pin2)
{
	GPIO_voidSetPinDDR(copy_u8port , copy_u8pin1 , OUTPUT);
	GPIO_voidSetPinDDR(copy_u8port , copy_u8pin2 , OUTPUT);
	GPIO_voidWritePin(copy_u8port, copy_u8pin1 , LOW);
	GPIO_voidWritePin(copy_u8port, copy_u8pin2 , LOW);
}
