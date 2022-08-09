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


#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"





void LED_voidTurnOn(u8 copy_u8port , u8 copy_u8pin)
{
	GPIO_voidSetPinDDR(copy_u8port , copy_u8pin , OUTPUT );
	GPIO_voidWritePin (copy_u8port , copy_u8pin , HIGH);
}
void LED_voidTurnOff(u8 copy_u8port , u8 copy_u8pin)
{
	GPIO_voidSetPinDDR(copy_u8port , copy_u8pin , OUTPUT );
	GPIO_voidWritePin (copy_u8port , copy_u8pin , LOW);
}
void LED_voidTogLed (u8 copy_u8port , u8 copy_u8pin )
{
	GPIO_voidSetPinDDR(copy_u8port , copy_u8pin , OUTPUT );
		GPIO_voidTogPin (copy_u8port , copy_u8pin );


}




