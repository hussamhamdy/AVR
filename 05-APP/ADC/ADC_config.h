/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 08 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H
/* Options : 2 for Select devision by 2
			 4 for Select devision by 4
		     8 for Select devision by 8
			 16 for Select devision by 16
			 32 for Select devision by 32
			 64 for Select devision by 64
			 128 for Select devision by 128
*/
#define ADC_PRESCALER  64

/* Options : 0 for Select External Aref and stop interanl Aref
			 1 for Select AVcc and interanl Aref = 5 with External Capacitor on Aref
			 3 for Select AVcc and interanl Aref = 2.56 with External Capacitor on Aref
*/
#define ADC_VOLT_REF  1

/* Options : 0 for store 8bit in ADCL and 2bit in ADCH
	         1 for Store 2bit in ADCL and 8bit in ADCH
*/
#define ADC_STORE   0 




#endif 
	


