/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 18 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef TMR2_CONFIG_H
#define TMR2_CONFIG_H

/* Options : 0 for System clk
			 1 for Real Time Counter
	*/	
	#define TMR2_STATE


/*  Options : 0 for normal mode
			  1 for Phase PWM
			  2 for CTC mode
			  3 for Fast PWM mode
*/
	#define TMR2_MODE 
/* Options : for Non PWM
				0x00 for normal port op
				0x10 for toggle OC2 on compare Match
				0x20 for Clear OC2 on compare Match
				0x30 for Set 0C2 on compare Match
*/
	#define TMR2_COM_NONPWM
/* Options : for Fast PWM
				0x00 for normal port op
				0x20 for Clear OC2 on compare Match and Set on bottom
				0x30 for Set 0C2 on compare Match and cleat on bottom
*/
	#define TMR2_COM_FASTPWM
/* Options : for Phase correct PWM
				0x00 for normal port op
				0x20 for Clear OC2 on compare Match on Up count and Set on Down count
				0x30 for Set 0C2 on compare Match on Up count and Clear on Down count
*/
	#define TMR2_COM_PCPWM
/* Options : 0 for Disable FOC2
			 1 for Enable  FOC2
	*/
	#define TMR_FOC2

#endif