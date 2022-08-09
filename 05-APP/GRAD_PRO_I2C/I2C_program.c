/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 18 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"
#include "I2C_config.h"
#include "I2C_private.h"

#define F_CPU 8000000UL


void I2C_voidInit (u32 copy_u32Scl)
{
	#if I2C_PreScaler ==1
		CLEAR_BIT(TWSR , TWS1);
		CLEAR_BIT(TWSR , TWS0);
	#elif I2C_PreScaler == 4
		CLEAR_BIT(TWSR , TWS1);
		SET_BIT(TWSR , TWS0);
	#elif I2C_PreScaler == 16
		CLEAR_BIT(TWSR , TWS0);
		SET_BIT(TWSR , TWS1);
	#else
		SET_BIT(TWSR , TWS1);
		SET_BIT(TWSR , TWS0);
	#endif
TWBR = (((F_CPU/copy_u32Scl)-16 )/2*(4^I2C_PreScaler));

}
void I2C_voidStart (void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while (GET_BIT(TWCR , TWINT) == 0);
	while ((TWSR&=0xF8) != StartHasBeenSent);

}
void I2C_voidWriteAddress (u8 copy_u8Address)
{
	TWDR = copy_u8Address ;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while (GET_BIT(TWCR , TWINT) == 0);
	while ((TWSR&=0xF8) != AddressSentAckRes);
}
void I2C_voidWriteData (u8 copy_u8Data)
{
	TWDR = copy_u8Data ;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while (GET_BIT(TWCR , TWINT) == 0);
	while ((TWSR&=0xF8) != DataSentAckRes);
}
void I2C_voidStop	(void)
{
	
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
}
void I2C_voidSetAddress(u8 copy_u8Address)
{
	TWAR = copy_u8Address ;
}
u8 I2C_u8SlaveRead (void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (GET_BIT(TWCR , TWINT) == 0);
	while ((TWSR&=0xF8) != SlaWResAckReturn);
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (GET_BIT(TWCR , TWINT) == 0);
	while ((TWSR&=0xF8) != SLADataSentAckRes);
	return TWDR ;
	
}
void I2C_repeated_start(void)
	{
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
		while(GET_BIT(TWCR,TWINT)==0); //wait to finish
		while ((TWSR & 0XF8) != 0x10); // repeated start condition has been transmitted
	}

unsigned char I2C_read_with_NACK(void)
	{
		TWCR=(1<<TWINT)|(1<<TWEN);
		while(GET_BIT(TWCR,TWINT)==0);
		while ((TWSR & 0XF8) != 0x58); // data byte has been received and Not ACK has been returned
		return TWDR ;
	}
