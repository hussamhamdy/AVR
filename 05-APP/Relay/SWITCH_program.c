/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 11 OCT 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

// libaray
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"


#include "SWITCH_interface.h"
#include "SWITCH_private.h"
#include "SWITCH_config.h"

#define F_CPU 8000000UL
#include "util/delay.h"

void SWITCH_voidInit(u8 copy_u8Port , u8 copy_u8Pin )
{
	GPIO_voidSetPinDDR(copy_u8Port , copy_u8Pin ,INPUT);
	#if PULLUP_RES == 0 
	GPIO_voidWritePin (copy_u8Port , copy_u8Pin , HIGH );
	#endif
	
}

u8 	SWITCH_u8Read(u8 copy_u8Port , u8 copy_u8Pin )
{
	u8 Local_u8ReturnValue ;
	_delay_ms(50);
	Local_u8ReturnValue = GPIO_u8ReadPin(copy_u8Port , copy_u8Pin);
	return Local_u8ReturnValue ;
}

/*void SWITCH_voidInterrupt(u8 copy_u8IntNum , void (*copy_voidFun)(void))
{
	EXTI_voidInit(copy_u8IntNum , copy_voidFun );
}*/













