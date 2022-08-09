/*
 * main.c
 *
 *  Created on: Aug 20, 2021
 *      Author: Hussam
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "HLEDMAT_interface.h"

//u8 HIZ[8] ={0, 130, 100, 59, 123, 68, 130, 0} ;
//u8 WIZ [8] = {0, 130, 68, 123, 59, 100, 130, 0};
//u8 YA [8] ={0, 130, 68, 59, 59, 68, 130, 0} ;
u8 hussam[] = {0, 16, 32, 78, 64, 78, 32, 16, 4, 10, 17, 33, 65, 134, 134, 65, 33, 17, 10, 4, 0, 0, 128, 188, 164, 252, 32, 32, 32, 36, 36, 36, 40, 48, 32, 0, 62, 32, 32, 32, 32, 32, 32, 184, 32, 32, 32, 32, 34, 57, 2, 0, 4, 10, 17, 33, 65, 134, 134, 65, 33, 17, 10, 4};
u8 index = 0 , counter = 64;



void main (void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 ,RCC_GPIOA_ENABLE );
	RCC_voidEnableClock(RCC_APB2 ,RCC_GPIOB_ENABLE );
	MSTK_voidInit();
	HLEDMAT_voidInit();
	while(1)
	{

		if(counter > 7)
		{
			u8 temp[] = {hussam [counter ] , hussam[counter-1] , hussam [counter-2] , hussam [counter -3], hussam [counter -4], hussam [counter -5], hussam [counter -6], hussam [counter -7]  };
			for (index =0 ; index<10 ; index ++)
			{
				HLEDMAT_voidDisplayFrame(temp);
			}
			counter-- ;
		}
		else
		{
			counter = 64 ;
		}


	}
}
