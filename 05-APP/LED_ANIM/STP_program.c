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


#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

#define F_CPU 8000000UL
#include "util/delay.h"

u8 DataSerPort ,DataSerPin , DataClkPort , DataClkPin , StrPort  , StrPin ;

void STP_voidIntit(u8 copy_u8DataSerPort ,u8 copy_u8DataSerPin , u8 copy_u8DataClkPort ,u8 copy_u8DataClkPin ,u8 copy_u8StrPort ,u8 copy_u8StrPin)
{
	DataSerPort = copy_u8DataSerPort ;
	DataSerPin = copy_u8DataSerPin;
	DataClkPort =  copy_u8DataClkPort ;
	DataClkPin = copy_u8DataClkPin ;
	StrPort = copy_u8StrPort ;
	StrPin = copy_u8StrPin ; 
	GPIO_voidSetPinDDR (copy_u8DataSerPort , copy_u8DataSerPin , OUTPUT);
	GPIO_voidSetPinDDR (copy_u8DataClkPort ,copy_u8DataClkPin , OUTPUT );
	GPIO_voidSetPinDDR (copy_u8StrPort , copy_u8StrPin , OUTPUT);
}

void STP_voidSend (u8 copy_u8DataSend)
{
	u8 Counter  ;
	for (Counter = 8 ; Counter > 0 ; Counter -- )
	{
		//Local_u8Data =  GET_BIT (copy_u8DataSend , Counter);
		GPIO_voidWritePin (DataSerPort ,DataSerPin , GET_BIT (copy_u8DataSend , Counter-1) );
		GPIO_voidWritePin (DataClkPort , DataClkPin , HIGH);
		_delay_us(1);
		GPIO_voidWritePin (DataClkPort , DataClkPin , LOW);
		_delay_us(1);
	}
	GPIO_voidWritePin (StrPort , StrPin , HIGH);
		_delay_us(1);
		GPIO_voidWritePin (StrPort , StrPin , LOW);
		_delay_us(1);
	
}















