/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 18 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

	#define TWSR *((volatile u8*)0x21)
		#define		TWS7	7
		#define		TWS6	6
		#define		TWS5	5
		#define		TWS4	4
		#define		TWS3	3
		#define		TWS1	1
		#define		TWS0	0
	#define TWBR *((volatile u8*)0x20)
			
	#define TWDR *((volatile u8*)0x23)
	
	#define TWAR *((volatile u8*)0x22)
			#define TWA6	7
			#define TWA5	6
			#define TWA4	5
			#define TWA3	4
			#define TWA2	3
			#define TWA1	2
			#define TWA0	1
			#define TWGCE	0
			
	#define TWCR *((volatile u8*)0x56)
			#define TWINT 	7
			#define TWEA	6
			#define	TWSTA	5
			#define	TWSTO	4
			#define TWWC	3
			#define TWEN	2
			#define 	TWIE	0
			
#endif
