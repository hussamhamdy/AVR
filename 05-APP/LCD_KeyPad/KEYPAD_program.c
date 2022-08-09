/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 05 NOV 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

u8 Keypad [4][4] = { {'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A', '0','=','+'}};

void Keypad_voidinit (u8 copy_u8Port )
{
	GPIO_voidSetLowNippleDDR (copy_u8Port , OUTPUT);
	GPIO_voidSetHighNippleDDR (copy_u8Port , INPUT);
	GPIO_voidWriteHighNipple (copy_u8Port , 0xF0);
}
u8 Keypad_voidCheckVal (u8 copy_u8Port)
{


	u8 Row , Column , Return  , Value = NOTPRESSED;
	for (Row = 0 ; Row < 4 ; Row ++)
		{
			GPIO_voidWriteLowNipple	(copy_u8Port , 0x0F);
			GPIO_voidWritePin (copy_u8Port , Row , LOW );
			
			for (Column = 0 ; Column <4 ; Column ++ )
			{
				
			Return=GPIO_u8ReadPin(copy_u8Port ,( Column+4 ));
		
			if (Return == 0 )
			{
				Value = Keypad [Row][Column];
				break;
			}
				
			}
			if (Return ==0)
			{
			break;
			}
		}
		return Value ;
	
}



