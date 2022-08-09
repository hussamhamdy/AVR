/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 13 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TMR0_interface.h"
#include "TMR0_private.h"
#include "TMR0_config.h"

u32 TOV_Counter =0 ;
u8 flag =0 ;
void (*Global_CBTOV)(void) ;
void (*Global_CBCTC)(void);
	void TMR0_voidInit(void)
	{
		SET_BIT (SREG , 7);
		//MODE ADJUSTMENT
		#if TMR0_MODE == 0
			CLEAR_BIT(TCCR0 ,WGM00 );
			CLEAR_BIT(TCCR0 ,WGM01 );
		#elif TMR0_MODE == 1
			SET_BIT(TCCR0 ,WGM00 );
			CLEAR_BIT(TCCR0 ,WGM01 );
		#elif TMR0_MODE == 2
			SET_BIT(TCCR0 ,WGM01 );
			CLEAR_BIT(TCCR0 ,WGM00 );	
		#elif TMR0_MODE == 3
			SET_BIT(TCCR0 ,WGM00 );
			SET_BIT(TCCR0 ,WGM01 );
		#endif
		//SET COM
			TCCR0 &= 0xCF ;
		#if TMR0_COM_NONPWM =!0x00
			TCCR0 |= TMR0_COM_NONPWM ;
		#elif TMR0_COM_FASTPWM =!0x00
			TCCR0 |= TMR0_COM_FASTPWM ;
		#elif TMR0_COM_PCPWM =! 0x00
			TCCR0 |= TMR0_COM_PCPWM ;
		#endif
		// SET INTRUPT
		
		
		#if TMR_FOC0 == 0
			CLEAR_BIT (TCCR0 ,FOC0);
		#else 
			SET_BIT (TCCR0 , FOC0);
		#endif
			
			
		
	}
	void TMR0_voidStart(u8 copy_u8PreScalar)
	{
		
		TCCR0 &= 0xf8 ;
		TCCR0 |= copy_u8PreScalar ;
		flag =0 ;
	}
	void TMR0_voidSetTCNT0 (u8 copy_u8InitVal)
	{
		TCNT0 = copy_u8InitVal ;
	}
	u32  TMR0_u32ReadTmr0	(void)
	{
		u32 return_val ;
		return_val = (TOV_Counter * 256)+ TCNT0 ;
		return return_val ;
	}
	void TMR0_voidSetNormWInt( void (*copy_CB)(void))
	{
		if (copy_CB =! 0)
		{
			flag =1 ;
			Global_CBTOV = copy_CB ; 
		}
		
		
	}
	void TMR0_voidSetOCR0 (u8 copy_u8InitVal)
	{
		OCR0 = copy_u8InitVal ;
	}
	void TMR0_voidSetCTCWInt( void (*copy_CB)(void))
	{
		if (copy_CB =! 0)
		{
			
			Global_CBCTC = copy_CB ; 
		}
		
	}
	void TMR0_voidStopTmr(void)
	{
		TCCR0 &= 0xF8 ;
	}
	void TMR0_voidDInit (void)
	{
		TCCR0 = 0x00 ;
	}