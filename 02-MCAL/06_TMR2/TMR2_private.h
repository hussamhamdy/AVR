/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 18 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef TMR0_PRIVATE_H
#define TMR0_PRIVATE_H


	#define TCNT2 	*((volatile u8*)0x44)
	#define OCR2 	*((volatile u8*)0x43)
	#define TCCR2 	*((volatile u8*)0x45)
		#define CS20 	0	
		#define CS21 	1
		#define CS22 	2
		#define WFM21	3
		#define COM20	4
		#define COM21	5
		#define	WGM20	6
		#define	FOC2	7
	#define TIMSK 	*((volatile u8*)0x59)
		#define TOIE2	6
		#define	OCIE2	7
		
	#define TIFR 	*((volatile u8*)0x58)
		#define TOV2 6
		#define OCF2 7
	#define ASSR 	*((volatile u8*)0x42)
		#define AS2	3
	

#endif