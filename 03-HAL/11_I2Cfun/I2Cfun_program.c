/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 11 OCT 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2Cfun_interface.h"

#include "I2C_interface.h"
#include "I2C_config.h"
#include "I2C_private.h"




void I2Cfun_voidMasterSend(u8 copy_u8SlaveAddress , u8 copy_u8Data)
{
	I2C_start(); // transmit start condition
		I2C_write_address(copy_u8SlaveAddress); // transmit SLA+W
		I2C_write_data(copy_u8Data); // transmit data
		I2C_stop(); // transmit stop condition 
}
u8 I2Cfun_voidMasterRead(u8 copy_u8SlaveAddress)
{
	u8 RETURN
	I2C_start(); // transmit start condition
	I2C_write_address(copy_u8SlaveAddress); // transmit device address and Write
	I2C_repeated_start(); // transmit repeated start condition
	I2C_write_address_and_read(copy_u8SlaveAddress+ 1); // transmit device address and read
	RETURN=I2C_read_with_NACK();
	I2C_stop();
	return RETURN ;
}
