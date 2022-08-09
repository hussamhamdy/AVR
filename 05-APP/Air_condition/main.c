/*
 * main.c
 *
 *  Created on: Jan 23, 2021
 *      Author: hussam
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "ADC_interface.h"
#include "EXTI_interface.h"

#include "LED_interface.h"
#include "SWITCH_interface.h"
#include "LCD_interface.h"
#include "LM35_interface.h"

#include "util/delay.h"
#define F_CPU 8000000UL


u8 CondTemp = 24 ;

void TempUp (void)
{
	if (CondTemp <= 25)
	CondTemp++;
}
void TempDn (void)
{
	if (CondTemp >= 16)
	{
	CondTemp-- ;
	}
}





int main (void )
{
	LM35_voidInit(ADC1);
	LCD_voidInit();
	SWITCH_voidInit(GPIOD , 2);
	SWITCH_voidInit(GPIOD , 3);

	SWITCH_voidInterrupt(EXTI_INT0 ,&TempUp);
	SWITCH_voidInterrupt(EXTI_INT1 , &TempDn);
	u8 Temp ;
	u8 FANSW , HEATSW ;
	while (1)
		{
		Temp =LM35_voidRead();
		LCD_voidMoveCrusor(1,1);
		LCD_voidDispString("Temp=");
		LCD_voidDispNumber(Temp);
		LCD_voidMoveCrusor(2,1);
		LCD_voidDispString("cond=");
		LCD_voidDispNumber(CondTemp);
		_delay_ms (1000);
		FANSW = SWITCH_u8Read(GPIOD , 0);
		HEATSW = SWITCH_u8Read(GPIOD , 1);

		if (FANSW == 0 && Temp > CondTemp)
		{
			LED_voidTurnOn(GPIOD , 4);

		}
		else if (Temp < CondTemp || FANSW != 0)
		{
			LED_voidTurnOff(GPIOD , 4);
		}
		if (HEATSW == 0 && Temp < 15)
		{
			LED_voidTurnOn(GPIOD , 5);

		}
		else if (Temp > 15 || HEATSW != 0)
		{
			LED_voidTurnOff(GPIOD , 5);
		}






		}
}
