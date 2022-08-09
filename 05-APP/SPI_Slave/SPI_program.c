/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 18 Dec 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void (* Global_CBSTC)(void);

void SPI_voidInit(void)
{
	/*ADJUST  MODE*/
	#if SPI_MODE == MASTER
	SET_BIT (SPCR , MSTR);
	SET_BIT (DDRB , 4);
	SET_BIT (DDRB , 5);
	SET_BIT (DDRB , 7);
	SET_BIT	(PORTB , 4);
	#else
	CLEAR_BIT (SPCR , MSTR);
	SET_BIT (DDRB , 6);
	#endif
	/*ADJUST DATA ORDER*/
	#if SPI_DATAORDER ==LSB
		SET_BIT (SPCR , DORD);
	#else
		CLEAR_BIT (SPCR , DORD);
	#endif
	/*ADJUST POLARITY*/
	#if SPI_OPERATINGLEVEL == IDEL_LOW
		CLEAR_BIT(SPCR , CPOL);
	#else 
		SET_BIT (SPCR , CPOL);
	#endif
	/*ADJUST CLK PHASE*/
	#if SPI_CLOCKPHASE == RISING
		CLEAR_BIT (SPCR , CPHA);
	#else
		SET_BIT (SPCR , CPHA);
	#endif
	/*ADJUST SPEED*/
	#if SPI_SPEEDMODE == NORMAL_SPEED
		CLEAR_BIT (SPSR , SPI2X);
		/*ADJUST  PRESCALER*/
		#if	SPI_FREQUENCY_PRESCALER == F_4
		CLEAR_BIT (SPCR , SPR0);
		CLEAR_BIT (SPCR , SPR1);
		#elif SPI_FREQUENCY_PRESCALER == F_16
		SET_BIT (SPCR , SPR0);
		CLEAR_BIT (SPCR , SPR1);
		#elif SPI_FREQUENCY_PRESCALER == F_64
		CLEAR_BIT_BIT (SPCR , SPR0);
		SET_BIT (SPCR , SPR1);
		#elif SPI_FREQUENCY_PRESCALER == F_128
		SET_BIT (SPCR , SPR0);
		SET_BIT (SPCR , SPR1);
		#endif
	#else 
		SET_BIT (SPSR , SPI2X);
		#if	SPI_FREQUENCY_PRESCALER == F_2
		CLEAR_BIT (SPCR , SPR0);
		CLEAR_BIT (SPCR , SPR1);
		#elif SPI_FREQUENCY_PRESCALER == F_8
		SET_BIT (SPCR , SPR0);
		CLEAR_BIT (SPCR , SPR1);
		#elif SPI_FREQUENCY_PRESCALER == F_32
		CLEAR_BIT_BIT (SPCR , SPR0);
		SET_BIT (SPCR , SPR1);
		#elif SPI_FREQUENCY_PRESCALER == FD_64
		SET_BIT (SPCR , SPR0);
		SET_BIT (SPCR , SPR1);
		#endif
	#endif
}
 
u8 SPI_u8SendRes (u8 copy_u8Data)
{
	/*Enable SPI */
	SET_BIT (SPCR , SPE);
	CLEAR_BIT (PORTB , 4);
	SPDR = copy_u8Data ;
	while (GET_BIT (SPSR , SPIF)== 0);
		SET_BIT	(PORTB , 4);

	return SPDR ;
	
}

void SPI_u8SendString (u8 *copy_u8PTR)
{
	volatile u8 temp ;
	while (*copy_u8PTR != '\0');
	{
		temp = SPI_u8SendRes ;
		copy_u8PTR ++ ;
	}
	
}

void SPI_voidIntruptEn ( void (* copy_CB)(void) )
{
	SET_BIT(SREG , GI);
	SET_BIT (SPCR , SPIE );
	SET_BIT(SPSR, SPIF);

	Global_CBSTC = copy_CB ;
}

ISR(STC_vect)
	{
		(*Global_CBSTC)();
	}

	
