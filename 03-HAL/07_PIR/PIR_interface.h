/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 20 NOV 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef PIR_INTERFACE_H
#define PIR_INTERFACE_H

void PIR_voidIntit(u8 copy_u8Port , u8 copy_u8Pin );

u8 	PIR_u8Read(u8 copy_u8Port , u8 copy_u8Pin );	

void PIR_voidInterrupt(u8 copy_u8IntNum , void (*copy_voidFun)(void));



#endif
