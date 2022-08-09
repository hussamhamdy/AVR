/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 18 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

void I2C_voidInit (u32 copy_u32Scl);
void I2C_voidStart (void);
void I2C_voidWriteAddress (u8 copy_u8Address);
void I2C_voidWriteData (u8 copy_u8Data);
void I2C_voidStop	(void);
void I2C_voidSetAddress(u8 copy_u8Address);
u8 I2C_u8SlaveRead (void);
void I2C_repeated_start(void);
void I2C_write_address_and_read(u8 address);

unsigned char I2C_read_with_NACK(void);


#endif
