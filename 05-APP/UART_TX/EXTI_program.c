/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 23 OCT 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

#include "avr/interrupt.h"


void (* Global_CBINT0)(void);
void (* Global_CBINT1)(void);
void (* Global_CBINT2)(void);



	void EXTI_voidInit(u8 copy_u8IntNum , void (* copy_CB)(void))
	{
		SET_BIT(SREG , GI);
		
		switch (copy_u8IntNum) 
		{
			case EXTI_INT0 :
			SET_BIT (GICR , INT0 );
			SET_BIT(GIFR, INTF0);
			CLEAR_BIT(DDRD , 2 );
			Global_CBINT0 = copy_CB ;
			break ; 
			
			case EXTI_INT1 :
			SET_BIT (GICR , INT1 );
			CLEAR_BIT(DDRD , 3 );
			Global_CBINT1 = copy_CB ;
			break ; 
			
			case EXTI_INT2 :
			SET_BIT (GICR , INT2 );
			CLEAR_BIT(DDRB , 2 );
			Global_CBINT2 = copy_CB ;
			break ; 
			
			default :
			break ;
			
		}
	}
	ISR(INT0_vect)
	{
		(*Global_CBINT0)();
	}
	ISR(INT1_vect)
	{
		(*Global_CBINT1)();
	}
	ISR(INT2_vect)
	{
		(*Global_CBINT2)();
	}
	