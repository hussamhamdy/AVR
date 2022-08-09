/*
 * main.c
 *
 * Created: 3/19/2021 8:14:48 AM
 *  Author: hussam
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Function.h"


#include "GPIO_interface.h"
#include "ExtEEPROM_interface.h"
#include "I2C_interface.h"
#include "I2Cfun_interface.h"
#include "KEYPAD_interface.h"
#include "LCD_interface.h"

#include "util/delay.h"
#define F_CPU 8000000UL
#define KEYDELAY 500


u8 Key , Correct ;

int main(void)
{
	LCD_voidInit();
	I2C_voidInit(50000);
	Keypad_voidinit(GPIOB);


    while(1)
    {
    	_delay_ms(500);
		if (ExtEEPROM_voidRead(TRY_ADDRESS) == 0)
		{
			LockedOut();
			break;

		}
		ExtEEPROM_voidWrite(TRY_ADDRESS,3);
		LCD_voidMoveCrusor(1,1);
		LCD_voidDispString("1-Set new Pass");
		LCD_voidMoveCrusor(2,1);
		LCD_voidDispString("2-Enter PassWord");
		do
		{
			Key = Keypad_voidCheckVal(GPIOB);

		} while (Key == NOTPRESSED);
		_delay_ms(KEYDELAY);
		if (Key == '1')
		{
			if (ExtEEPROM_voidRead(EEPROM_ADDRESS) == 0xff)
			{
				SetPass();
				ExtEEPROM_voidWrite(TRY_ADDRESS , 3);
				I2Cfun_voidMasterSend(SLAVE , 8);


			}
			else
			{

					do
					{


						if (CheckPass() == 1)
						{

							SetPass();
							ExtEEPROM_voidWrite(TRY_ADDRESS , 3);
							break;
						}
						else
						{
							Wrongpass();
						}

					}while (EEPROM_voidRead(TRY_ADDRESS) != 0);

					if (EEPROM_voidRead(TRY_ADDRESS)== 0)
					{
						LockedOut();
						break;
					}



			}
		}

		else if (Key == '2')
		{
			if(ExtEEPROM_voidRead(EEPROM_ADDRESS) ==0xFF)
			{
				SetPass();
				ExtEEPROM_voidWrite(TRY_ADDRESS , 3);
				continue;
			}

			do
			{
				Correct = CheckPass();
				if (Correct == 1)
				{
					I2Cfun_voidMasterSend(SLAVE , 15);
					ExtEEPROM_voidWrite(TRY_ADDRESS , 3);
					break;
				}
				else
				{
					Wrongpass();
				}


			}while(ExtEEPROM_voidRead(TRY_ADDRESS)!=0);
			break;

			if(ExtEEPROM_voidRead(TRY_ADDRESS)==0)
			{
				LockedOut();
				break;
			}




    }
  }

}


