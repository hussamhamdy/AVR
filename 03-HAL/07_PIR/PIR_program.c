/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 20 NOV 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

// libaray
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"


#include "PIR_interface.h"
#include "PIR_private.h"
#include "PIR_config.h"


void PIR_voidIntit(u8 copy_u8Port , u8 copy_u8Pin )
{
	GPIO_voidSetPinDDR(copy_u8Port , copy_u8Pin ,INPUT);
	
}

u8 	PIR_u8Read(u8 copy_u8Port , u8 copy_u8Pin )
{
	u8 Local_u8ReturnValue ;
	Local_u8ReturnValue = GPIO_u8ReadPin(copy_u8Port , copy_u8Pin);
	return Local_u8ReturnValue ;
}

void PIR_voidInterrupt(u8 copy_u8IntNum , void (*copy_voidFun)(void))
{
	EXTI_voidInit(copy_u8IntNum , copy_voidFun );
}













