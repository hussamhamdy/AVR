/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 30 OCT 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef LCD_config_H
#define LCD_config_H

// OPTIONS 0 for 8BIT
//		   1 for 4bit

#define LCD_MODE 1

/* OPTIONS 0 for Low_nipple
		   1 for High_nipple
 */
 
 #define LCD_NIBBLE 0
 
 /* OPTIONS : GPIOA  -> 0 
			  GPIOB  -> 1
			  GPIOC  -> 2 
			  GPIOD  -> 3
*/
#define LCD_PORT 1

 

 /* OPTIONS : GPIOA  -> 0 
			  GPIOB  -> 1
			  GPIOC  -> 2 
			  GPIOD  -> 3
*/
#define LCD_RSPORT 1

// OPTIONS 0~7

#define LCD_RSPIN 4


 /* OPTIONS : GPIOA  -> 0 
			  GPIOB  -> 1
			  GPIOC  -> 2 
			  GPIOD  -> 3
*/
#define LCD_RWPORT 1

// OPTIONS 0~7

#define LCD_RWPIN 7


 /* OPTIONS : GPIOA  -> 0 
			  GPIOB  -> 1
			  GPIOC  -> 2 
			  GPIOD  -> 3
*/
#define LCD_ENPORT 1

// OPTIONS 0~7

#define LCD_ENPIN 5

#endif