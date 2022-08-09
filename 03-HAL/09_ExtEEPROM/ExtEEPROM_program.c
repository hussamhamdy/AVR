/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 23 Mar 2021								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"


#include "ExtEEPROM_interface.h"
#include "ExtEEPROM_private.h"
#include "ExtEEPROM_config.h"

void ExtEEPROM_voidWrite (u8 copy_u8Address , u8 copy_u8Data)
{
	I2C_start(); // transmit start condition
	I2C_write_address(0b10100000); // transmit device address and Write
	I2C_write_data(copy_u8Address); // transmit word address
	I2C_write_data(copy_u8Data); // transmit data
	I2C_stop(); // transmit stop condition
}

void ExtEEPROM_voidRead (u8 copy_u8Address , u8 copy_u8Data)
{
	I2C_start(); // transmit start condition
	I2C_write_address(0b10100000); // transmit device address and Write
	I2C_write_data(copy_u8Address); // transmit word address
	I2C_repeated_start(); // transmit repeated start condition
	I2C_write_address_and_read(0b10100001); // transmit device address and read
	x=I2C_read_with_NACK();
}