/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 11 OCT 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

void SWITCH_voidIntit(u8 copy_u8Port , u8 copy_u8Pin );

u8 	SWITCH_u8Read(u8 copy_u8Port , u8 copy_u8Pin );	

void SWITCH_voidInterrupt(u8 copy_u8IntNum , void (*copy_voidFun)(void));



#endif
