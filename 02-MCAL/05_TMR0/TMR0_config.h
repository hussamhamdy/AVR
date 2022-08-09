/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 13 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef TMR0_CONFIG_H
#define TMR0_CONFIG_H

/*  Options : 0 for normal mode
			  1 for Phase PWM
			  2 for CTC mode
			  3 for Fast PWM mode
*/
	#define TMR0_MODE 
/* Options : for Non PWM
				0x00 for normal port op
				0x10 for toggle OC0 on compare Match
				0x20 for Clear OC0 on compare Match
				0x30 for Set 0C0 on compare Match
*/
	#define TMR0_COM_NONPWM
/* Options : for Fast PWM
				0x00 for normal port op
				0x20 for Clear OC0 on compare Match and Set on bottom
				0x30 for Set 0C0 on compare Match and cleat on bottom
*/
	#define TMR0_COM_FASTPWM
/* Options : for Phase correct PWM
				0x00 for normal port op
				0x20 for Clear OC0 on compare Match on Up count and Set on Down count
				0x30 for Set 0C0 on compare Match on Up count and Clear on Down count
*/
	#define TMR0_COM_PCPWM
/* Options : 0 for Disable FOC0
			 1 for Enable  FOC0
	*/
	#define TMR_FOC0

#endif