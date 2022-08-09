/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 30 OCT 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

#define F_CPU 8000000UL
#include "util/delay.h"



void LCD_voidInit()
{
	_delay_ms(40);
	
	GPIO_voidSetPinDDR(LCD_RSPORT , LCD_RSPIN , OUTPUT);
	GPIO_voidSetPinDDR(LCD_RWPORT , LCD_RWPIN , OUTPUT);
	GPIO_voidSetPinDDR(LCD_ENPORT , LCD_ENPIN , OUTPUT);
	#if LCD_MODE == 0
		GPIO_voidSetPortDDR(LCD_PORT, OUTPUT);
		LCD_voidSendCmd(LCD_Function_8BIT_2Lines);
		_delay_ms(1);
		LCD_voidSendCmd(LCD_DISP_ON_CURSOR_ON);
		_delay_ms(1);
		LCD_voidSendCmd(LCD_CLEAR_SCREEN);
		_delay_ms(10);
		LCD_voidSendCmd(LCD_ENTRY_MODE);
		_delay_ms(1);
		
	#elif LCD_MODE == 1
		#if LCD_NIBBLE == 0 
			GPIO_voidSetLowNippleDDR(LCD_PORT , OUTPUT);
			LCD_voidSendCmd(LCD_RETURN_HOME);
			_delay_ms(15);
			LCD_voidSendCmd(LCD_Function_4BIT_2Lines);
			_delay_ms(1);
		    LCD_voidSendCmd(LCD_DISP_ON_CURSOR_ON);
		    _delay_ms(1);
		    LCD_voidSendCmd(LCD_CLEAR_SCREEN);
		    _delay_ms(10);
		    LCD_voidSendCmd(LCD_ENTRY_MODE);
		    _delay_ms(1);
			

		#elif LCD_NIBBLE == 1 
			GPIO_voidSetHighNippleDDR(LCD_PORT , OUTPUT);
			LCD_voidSendCmd(LCD_RETURN_HOME);
			_delay_ms(15);
			LCD_voidSendCmd(LCD_Function_4BIT_2Lines);
			_delay_ms(1);
		    LCD_voidSendCmd(LCD_DISP_ON_CURSOR_ON);
		    _delay_ms(1);
		    LCD_voidSendCmd(LCD_CLEAR_SCREEN);
		    _delay_ms(10);
		    LCD_voidSendCmd(LCD_ENTRY_MODE);
		    _delay_ms(1);

		#endif
	#endif
	
	
	

}

void LCD_voidSendCmd(u8 copy_u8Cmd)
{
	#if LCD_MODE == 0
		GPIO_voidWritePort (LCD_PORT , copy_u8Cmd);
		GPIO_voidWritePin  (LCD_RSPORT , LCD_RSPIN , 0);
		GPIO_voidWritePin  (LCD_RWPORT , LCD_RWPIN , 0);
		LCD_voidSendEnPulse();
		
	#elif LCD_MODE == 1
		#if LCD_NIBBLE == 0 
			GPIO_voidWriteLowNipple(LCD_PORT , copy_u8Cmd>>4);
			GPIO_voidWritePin  (LCD_RSPORT , LCD_RSPIN , 0);
			GPIO_voidWritePin  (LCD_RWPORT , LCD_RWPIN , 0);
			LCD_voidSendEnPulse();
		
			GPIO_voidWriteLowNipple(LCD_PORT , copy_u8Cmd);
			GPIO_voidWritePin  (LCD_RSPORT , LCD_RSPIN , 0);
			GPIO_voidWritePin  (LCD_RWPORT , LCD_RWPIN , 0);
			LCD_voidSendEnPulse();
			_delay_ms(2);
			#elif LCD_NIBBLE == 1
				GPIO_voidWriteHighNipple(LCD_PORT , copy_u8Cmd>>4);
			GPIO_voidWritePin  (LCD_RSPORT , LCD_RSPIN , 0);
			GPIO_voidWritePin  (LCD_RWPORT , LCD_RWPIN , 0);
			LCD_voidSendEnPulse();
		
			GPIO_voidWriteHighNipple(LCD_PORT , copy_u8Cmd);
			GPIO_voidWritePin  (LCD_RSPORT , LCD_RSPIN , 0);
			GPIO_voidWritePin  (LCD_RWPORT , LCD_RWPIN , 0);
			LCD_voidSendEnPulse();
			_delay_ms(2);
		#endif
	#endif
	
}
void LCD_voidSendEnPulse ()
{
	GPIO_voidWritePin  (LCD_ENPORT , LCD_ENPIN , 1);
	_delay_ms(2);
	GPIO_voidWritePin  (LCD_ENPORT , LCD_ENPIN , 0);

}
void LCD_voidMoveCrusor(u8 copy_u8Line , u8 copy_u8Position)
{
	u8 data ;
if(copy_u8Line < 1 || copy_u8Line > 2 || copy_u8Position >16 || copy_u8Position <1 )	
{
	data = 0x80 ;
}
else if (copy_u8Line ==1)
{
	data = 0x80 +(copy_u8Position -1);
}
else if (copy_u8Line==2)
{
	data = 0xC0 + (copy_u8Position -1 );
}
LCD_voidSendCmd(data);
_delay_ms(1);
}
void LCD_voidClearScreen()
{
	LCD_voidSendCmd(LCD_CLEAR_SCREEN);
	_delay_ms(10);
}
void LCD_voidDispChar(u8 copy_u8char)
{
#if LCD_MODE == 0
		GPIO_voidWritePort (LCD_PORT , copy_u8char);
		GPIO_voidWritePin  (LCD_RSPORT , LCD_RSPIN , 1);
		GPIO_voidWritePin  (LCD_RWPORT , LCD_RWPIN , 0);
		LCD_voidSendEnPulse();
		
	#elif LCD_MODE == 1
		#if LCD_NIBBLE == 0 
			GPIO_voidWriteLowNipple(LCD_PORT , copy_u8char>>4);
			GPIO_voidWritePin  (LCD_RSPORT , LCD_RSPIN , 1);
			GPIO_voidWritePin  (LCD_RWPORT , LCD_RWPIN , 0);
			LCD_voidSendEnPulse();
		
			GPIO_voidWriteLowNipple(LCD_PORT , copy_u8char);
			GPIO_voidWritePin  (LCD_RSPORT , LCD_RSPIN , 1);
			GPIO_voidWritePin  (LCD_RWPORT , LCD_RWPIN , 0);
			LCD_voidSendEnPulse();
			_delay_ms(2);
			#elif LCD_NIBBLE == 1
				GPIO_voidWriteHighNipple(LCD_PORT , copy_u8char>>4);
			GPIO_voidWritePin  (LCD_RSPORT , LCD_RSPIN , 1);
			GPIO_voidWritePin  (LCD_RWPORT , LCD_RWPIN , 0);
			LCD_voidSendEnPulse();
		
			GPIO_voidWriteHighNipple(LCD_PORT , copy_u8char);
			GPIO_voidWritePin  (LCD_RSPORT , LCD_RSPIN , 1);
			GPIO_voidWritePin  (LCD_RWPORT , LCD_RWPIN , 0);
			LCD_voidSendEnPulse();
			_delay_ms(2);
		#endif
	#endif
		
}
void LCD_voidDispString(u8 *copy_u8String)
{
	while ((*copy_u8String) != '\0')
	{
		LCD_voidDispChar (*copy_u8String);
		copy_u8String ++ ;
	}
}
