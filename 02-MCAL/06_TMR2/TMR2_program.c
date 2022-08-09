/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 18 Nov 2020								 */	
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
	
	void TMR2_voidInit(void)
	{
		//MODE ADJUSTMENT
		#if TMR2_MODE == 0
			CLEAR_BIT(TCCR2 ,WGM20 );
			CLEAR_BIT(TCCR2 ,WGM21 );
		#elif TMR2_MODE == 1
			SET_BIT(TCCR2 ,WGM20 );
			CLEAR_BIT(TCCR2 ,WGM21 );
		#elif TMR2_MODE == 2
			SET_BIT(TCCR2 ,WGM21 );
			CLEAR_BIT(TCCR2 ,WGM20 );	
		#elif TMR2_MODE == 3
			SET_BIT(TCCR2 ,WGM20 );
			SET_BIT(TCCR2 ,WGM21 );
		#endif
		//SET COM
			TCCR2 &= 0xCF ;
		#if TMR2_COM_NONPWM =!0x00
			TCCR2 |= TMR2_COM_NONPWM ;
		#elif TMR2_COM_FASTPWM =!0x00
			TCCR2 |= TMR2_COM_FASTPWM ;
		#elif TMR2_COM_PCPWM =! 0x00
			TCCR2 |= TMR2_COM_PCPWM ;
		#endif
		
		#if TMR_FOC2 == 0
			CLEAR_BIT (TCCR2 ,FOC2);
		#else 
			SET_BIT (TCCR2 , FOC2);
		#endif
		
		#if TMR2_STATE ==0
			CLEAR_BIT (ASSR , AS2);
		#else
			SET_BIT (ASSR , AS2);
		#endif
			
		
	}
	void TMR2_voidStart(u8 copy_u8PreScalar)
	{
		
		TCCR2 &= 0xf8 ;
		TCCR2 |= copy_u8PreScalar ;
		flag =0 ;
	}
	void TMR2_voidSetTCNT2 (u8 copy_u8InitVal)
	{
		TCNT2 = copy_u8InitVal ;
	}
	u32  TMR2_u32ReadTmr2	(void)
	{
		u32 return_val ;
		return_val = (TOV_Counter * 256)+ TCNT2 ;
		return return_val ;
	}
	void TMR2_voidSetNormWInt( void (*copy_CB)(void))
	{
		if (copy_CB =! 0)
		{
			flag =1 ;
			Global_CBTOV = copy_CB ; 
		}
		
		
	}
	void TMR2_voidSetOCR2 (u8 copy_u8InitVal)
	{
		OCR2 = copy_u8InitVal ;
	}
	void TMR2_voidSetCTCWInt( void (*copy_CB)(void))
	{
		if (copy_CB =! 0)
		{
			
			Global_CBCTC = copy_CB ; 
		}
		
	}
	void TMR2_voidStopTmr(void)
	{
		TCCR2 &= 0xF8 ;
	}
	void TMR2_voidDInit (void)
	{
		TCCR2 = 0x00 ;
	}