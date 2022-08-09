/*****************************************************/
/* Author : Hussam hamdy 						     */
/* Data : 10 OCT 2020							     */	
/* Version : V 1.0								     */
/* LOG : 	V 1.1 Set Port						     */
/*			V 1.2 Set Nipple					     */
/*****************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3

#define INPUT 	0
#define OUTPUT 	1

#define HIGH 	1
#define LOW 	0



/*	PIN	*/

	void GPIO_voidSetPinDDR(u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Mode );
	
	void GPIO_voidWritePin(u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Value );
	
	u8	GPIO_u8ReadPin(u8 copy_u8Port ,u8 copy_u8Pin );
	
	void GPIO_voidTogPin 	( u8 copy_u8Port , u8 copy_u8Pin );
	
	void GPIO_voidSetPortDDR (u8  copy_u8Port , u8 copy_u8Mode );
	
	void GPIO_voidWritePort (u8 copy_u8port , u8 copy_u8value);
	
	void GPIO_voidSetLowNippleDDR(u8 copy_u8port , u8 copy_u8Mode);

	void GPIO_voidSetHighNippleDDR(u8 copy_u8port , u8 copy_u8Mode);
	
	void GPIO_voidWriteLowNipple (u8 copy_u8Port , u8 copy_Value );

	void GPIO_voidWriteHighNipple (u8 copy_u8Port , u8 copy_Value );
	

#endif
