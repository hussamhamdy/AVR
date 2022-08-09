/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 08 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7



	void ADC_voidinit (u8 copy_u8Channel);
	u16	ADC_u16Read (void);
#endif
