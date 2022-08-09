/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 4 OCT 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

	#define SET_BIT(reg,bit)    reg|=(1<<bit)
	#define CLEAR_BIT(reg,bit)  reg&= ~(1<<bit)
	#define GET_BIT(reg,bit)   ((reg&(1<<bit))>>bit)
	#define TOG_BIT(reg,bit)     reg^=(1<<bit)   
	
	

	#endif