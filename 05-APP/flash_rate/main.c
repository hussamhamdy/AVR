/*
 * main.c
 *
 *  Created on: Dec 15, 2020
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
#include "LED_interface.h"
#include "SWITCH_interface.h"

#define F_CPU 8000000UL
#include  "util/delay.h"
u16 Timer = 1000 ;
void fun1 (void)
	{
	if(Timer > 0)
		{
			Timer-=200;
		}
	}
void fun2 (void)
	{

	Timer+=200;
	}
int main()
{


	SWITCH_voidInterrupt(EXTI_INT0 , &fun1 );
	SWITCH_voidInterrupt(EXTI_INT1, &fun2);


	while (1)
	{
		LED_voidTogLed(GPIOA , 0);
		_delay_ms(Timer);

	}

}

