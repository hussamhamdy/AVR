/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 11 NOV 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LM35_interface.h"
#include "LM35_config.h"
#include "LM35_private.h"

#include "ADC_interface.h"


void LM35_voidInit (u8 copy_u8Channel)
{
	ADC_voidinit(copy_u8Channel);
}
u8 LM35_voidRead (void)
{
	u16 LM35_read;

	u8 Temp ;

	LM35_read = ADC_u16Read() ;
	#if VREF == 2560
	Temp = LM35_read*.25 ;
	#elif VREF == 5000
	Temp = LM35_read * 0.48828125 ;
	#endif
	return Temp;
}

