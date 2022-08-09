/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 05 NOV 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#define NOTPRESSED  0xff

void Keypad_voidInit(u8 copy_u8Port);

u8 Keypad_voidCheckVal (u8 copy_u8Port);

#endif
