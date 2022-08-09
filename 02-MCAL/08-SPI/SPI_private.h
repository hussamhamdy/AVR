/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 18 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPDR *((volatile u8*)0x2F)
#define SPSR *((volatile u8*)0x2E)
	#define SPIF 7
	#define WCOL 6
	#define SPI2X 5
#define SPCR *((volatile u8*)0x2D)
	#define SPIE 7
	#define SPE  6
	#define DORD 5
	#define MSTR 4
	#define CPOL 3
	#define CPHA 2
	#define SPR1 1
	#define SPR0 0
#define DDRB *((volatile u8*)0x37)
#define PORTB *((volatile u8*)0x38)


#define SREG 	*((volatile u8*)0x5F)
	#define		GI		 7


#define MASTER 1
#define SLAVE  0

#define LSB 0
#define MSB 1

#define IDEL_LOW 0
#define IDEL_HIGH 1

#define RISING 1
#define FALLING 0

#define NORMAL_SPEED 0
#define DOUBLE_SPEED 1

#define F_4 	0
#define F_16	 1
#define F_64 	2
#define F_128 	3
#define F_2  	4
#define F_8		 5
#define F_32	 6
#define FD_64	 7

#endif