/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 30 OCT 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidInit();
void LCD_voidSendCmd(u8 copy_u8Cmd);
void LCD_voidSendEnPulse ();
void LCD_voidMoveCrusor(u8 copy_u8Line , u8 copy_u8Position);
void LCD_voidClearScreen();
void LCD_voidDispChar(u8 copy_u8char);
void LCD_voidDispString(u8 *copy_u8String);
void LCD_voidDispNumber (f32 copy_f32Num);

#endif
