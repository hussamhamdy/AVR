/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 18 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

#define StartHasBeenSent	 0x08
#define AddressSentAckRes	 0x18
#define	DataSentAckRes		 0x28
#define SlaWResAckReturn	 0x60
#define SLADataSentAckRes	 0x80

/* OPtions :Pre_Scaler
		1 for 1
		4 foe 4
		16 for 16
		64 for 64
*/
	#define I2C_PreScaler 1
#endif
