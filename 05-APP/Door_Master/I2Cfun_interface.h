/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 11 OCT 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef I2CFUN_INTERFACE_H
#define I2CFUN_INTERFACE_H

void I2Cfun_voidMasterSend(u8 copy_u8SlaveAddress , u8 copy_u8Data);
u8 I2Cfun_voidMasterRead(u8 copy_u8SlaveAddress);


#endif
