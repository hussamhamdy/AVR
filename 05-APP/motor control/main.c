/*
 * main.c
 *
 *  Created on: Dec 16, 2020
 *      Author: hussam
 */


/*
 * main.c
 *
 *  Created on: Dec 15, 2020
 *      Author: hussam
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "EXTI_interface.h"

#include "SWITCH_interface.h"
#include "LED_interface.h"

void fun1 (void)
{
	LED_voidTurnOn(GPIOA , 0);
	LED_voidTurnOn(GPIOA , 2);
	LED_voidTurnOff(GPIOA , 1);

}
void fun2 (void)
{
		LED_voidTurnOn(GPIOA , 1);
		LED_voidTurnOn(GPIOA , 2);
		LED_voidTurnOff(GPIOA , 0);
}
void fun3 (void)
{
	LED_voidTurnOff(GPIOA , 2);
}

int main ()
{
	SWITCH_voidInterrupt(EXTI_INT0 , &fun1);
	SWITCH_voidInterrupt(EXTI_INT1 , &fun2);
	SWITCH_voidInterrupt(EXTI_INT2 , &fun3);


	while (1)
	{

	}
}
