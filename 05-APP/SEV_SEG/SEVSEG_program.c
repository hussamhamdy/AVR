/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 13 OCT 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SEVSEG_interface.h"

u8 copy_u8ArrNum[10] = {0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F};
u8 copy_u8ArrChar [6] = {0x77, 0x7F, 0x39, 0x3F, 0x79, 0x71};
void SEVSEG_voidInit(u8 copy_u8port ){
	GPIO_voidSetPortDDR ( copy_u8port , OUTPUT);
	
}
void SEVSEG_voidDisp(u8 copy_u8port,u8 copy_u8value){

GPIO_voidWritePort ( copy_u8port , copy_u8ArrNum[copy_u8value]);
	
	
}
void SEVSEG_voidDispChar(u8 copy_u8Port , u8 copy_u8value ){
	GPIO_voidWritePort ( copy_u8Port , copy_u8ArrChar [copy_u8value]);

}


