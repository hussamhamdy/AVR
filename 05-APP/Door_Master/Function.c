

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
#define KEYDELAY 200


u8 PassKey , Index , PassIndex ;
u8 PassWord[5];

void SetPass (void)
{

	LCD_voidClearScreen();
	LCD_voidDispString("Set new Pass");
	_delay_ms(2000);
	LCD_voidClearScreen();
	Index = 0 ;
	LCD_voidMoveCrusor(1,6);
	LCD_voidDispString("<PIN>");
	LCD_voidMoveCrusor(2,4);
	do
	{
		do
		{
			PassKey = Keypad_voidCheckVal(GPIOB);

		} while (PassKey == NOTPRESSED);
		_delay_ms(KEYDELAY);
		LCD_voidDispChar(PassKey);
		PassKey ^= E_KEY ;
		PassWord[Index] = PassKey;
		Index ++ ;
	} while (Index != 5);
	do{
	do
	{
		PassKey = Keypad_voidCheckVal(GPIOB);

	} while (PassKey == NOTPRESSED);
	_delay_ms(KEYDELAY);

	if (PassKey == 'A')
	{
		LCD_voidClearScreen();
		LCD_voidMoveCrusor(1,3);
		for (Index = 0 ; Index<5 ; Index ++)
		{
			_delay_ms(500);
			ExtEEPROM_voidWrite(EEPROM_ADDRESS + Index , PassWord[Index]);
		}
		LCD_voidDispString("Pass Is Set");
		break;

	}
	else if (PassKey == '=')
	{
		LCD_voidClearScreen();
		SetPass();
	}
}while(PassKey != '='|| PassKey != 'A');
}

u8 CheckPass (void)
{
	LCD_voidClearScreen();
	PassIndex = 0 ;
	u8 Pass[5] , Pin[5];
	LCD_voidMoveCrusor(1,6);
	LCD_voidDispString("<PIN>");
	LCD_voidMoveCrusor(2,4);
	do
	{
		do
		{
			PassKey = Keypad_voidCheckVal(GPIOB);

		} while (PassKey == NOTPRESSED);
		_delay_ms(KEYDELAY);
		LCD_voidDispChar('*');
		Pass[PassIndex]= (PassKey ^= E_KEY) ;
		Pin[PassIndex] = ExtEEPROM_voidRead(EEPROM_ADDRESS + PassIndex );
		PassIndex ++ ;
	} while (PassIndex != 5);
do{
	do
	{
		PassKey = Keypad_voidCheckVal(GPIOB);

	} while (PassKey == NOTPRESSED);
	_delay_ms(KEYDELAY);

	if (PassKey == 'A')
	{
		LCD_voidClearScreen();
		LCD_voidMoveCrusor(1,3);
		if (Pass[0]==Pin[0] && Pass[1]==Pin[1] && Pass[2]==Pin[2] && Pass[3]==Pin[3] && Pass[4]==Pin[4] )
		{
			LCD_voidDispString("PASS IS Correct");
			_delay_ms(500);
			return 1 ;
		}
		else
		{
		LCD_voidDispString("PASS IS Wrong");
		_delay_ms(500);
		return 0 ;
		}
	}
	else if (PassKey == '=')
	{
		LCD_voidClearScreen();
		u8 r ;
		r = CheckPass() ;
		return  r ;
	}
	}while (PassKey != 'A' || '=');


}

void Wrongpass (void)
{
	u8 try ;
	try = ExtEEPROM_voidRead(TRY_ADDRESS);
	try -- ;
	ExtEEPROM_voidWrite(TRY_ADDRESS , try );
	I2Cfun_voidMasterSend(SLAVE,try);
	LCD_voidClearScreen();
	LCD_voidMoveCrusor(1,1);
	LCD_voidDispString("You have");
	LCD_voidMoveCrusor(2,1);
	LCD_voidDispNumber(try);
	LCD_voidMoveCrusor(2,3);
	LCD_voidDispString("Tries left");
	_delay_ms(2000);
	LCD_voidClearScreen();
}

void LockedOut (void)
{
	USART_voidSendByte(0);
	LCD_voidClearScreen();
	LCD_voidMoveCrusor(1,1);
	LCD_voidDispString("YOU ARE LOCKED");
	LCD_voidMoveCrusor(2,1);
	LCD_voidDispString("Contact Service");
	I2Cfun_voidMasterSend(SLAVE , 7);

}
