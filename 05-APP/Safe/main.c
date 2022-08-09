/*
 * main.c
 *
 *  Created on: Nov 9, 2020
 *      Author: hussam
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "LCD_interface.h"
#include "GPIO_interface.h"
#include "EEPROM_interface.h"
#include "KEYPAD_interface.h"
#include "LED_interface.h"
#define F_CPU 8000000UL
#include "util/delay.h"









void set_pass(void) ;
void check_pass (void);


#define E_Key 0xED
/*#define EEPROM_address 0x00*/
u8 Num , counter , true =0 , try = 3 , d;
u8 Pass[4] , Password[4] ;

u8 flag = 0 ;

int main ()
{


	Keypad_voidInit( GPIOD );
	LCD_voidInit();

	while(1)
	{
	LCD_voidMoveCrusor(1,1);
	LCD_voidDispString("1-Set new Pass");
	LCD_voidMoveCrusor(2,1);
	LCD_voidDispString("2-Enter PassWord");
	do{

				Num =  Keypad_voidCheckVal(GPIOD);
			}while (Num==NOTPRESSED);
			 _delay_ms(30);
			 if (Num =='1'){
				 if(flag == 1 )
				 {
					d = check_pass();
					 if (d == 1){
						 set_pass();
					 }
					 else if (d ==2 && try == 0) {
						LCD_voidDispString("You Are Locked");
						 break;
						 }
					else{

					}


	}
			 else if (Num == '2')
			 {
				 do{
				d= check_pass();
				 }while (d==2 && try != 0);
        		}
			 else
			 {

			 }
	}
}
	void set_pass()
	{


		LCD_voidMoveCrusor(1,1);
		LCD_voidDispString("Enter 4 numbers");
		_delay_ms(200);
		LCD_voidClearScreen();
		LCD_voidMoveCrusor(1,1);
		LCD_voidDispString("When Done");
		LCD_voidMoveCrusor(2,1);
		LCD_voidDispString("Kindly Press *");
		_delay_ms(200);
		LCD_voidClearScreen();
		LCD_voidMoveCrusor(1,1);
		LCD_voidDispString("Enter Password");
		LCD_voidMoveCrusor(2,1);



		for(counter=0 ; counter<4 ; counter ++){
		do{

			Num =  Keypad_voidCheckVal(GPIOD);
		}while (Num==NOTPRESSED);
		 _delay_ms(30);
		 LCD_voidDispChar(Num);
		 Num ^= E_Key;
		 	 Password[counter] = Num ;





			}

		LCD_voidClearScreen();
		LCD_voidMoveCrusor(1,1);
		LCD_voidDispString("Pass is set");
		flag = 1 ;
		_delay_ms(300);

		}




	u8 check_pass()
	{ u8 z ;
		LCD_voidClearScreen();
		LCD_voidMoveCrusor(1,1);
		LCD_voidDispString("Enter Pass");
		LCD_voidMoveCrusor(2,1);


		for(counter=0 ; counter<4 ; counter ++){
		do{

			Num =  Keypad_voidCheckVal(GPIOD);
		}while (Num==NOTPRESSED);
		 _delay_ms(30);

		 	 Pass[counter] = Num ;

			LCD_voidDispChar('*');
		}
		for(counter = 0 ; counter <4 ; counter ++)
		{
			Password[counter] ^= E_Key ;
		}

		if(Pass[0]==Password[0] &&  Pass[1]==Password[1] && Pass[2]==Password[2] && Pass[3]==Password[3] )
		{
			LCD_voidClearScreen();
			LCD_voidDispString("Correct Pass :)");
			z=1;
			return z ;
		}
		else
		{
			LCD_voidClearScreen();
			LCD_voidDispString("Wrong pass :(");
			LCD_voidMoveCrusor(2,1);
			LCD_voidDispString("You have ");
			if (try < 0){
			try -- ;
			}
			LCD_voidDispString(try);
			LCD_voidDispString(" Try");
			z=2 ;

		}
		_delay_ms(50);


		return z ;
	}
