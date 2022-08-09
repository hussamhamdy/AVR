/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 10 OCT 2020								 */	
/* Version : V 1.0									 */
/* LOG : 	V 1.1 Set port DDR						 */
/*            V 1.2 Set Nipple						 */
/*													 */
/*****************************************************/

/* LIB include */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* driver Include */

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_privite.h"








	void GPIO_voidSetPinDDR (u8  copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Mode )
	{
		switch(copy_u8Port)
		{
			case GPIOA :
				if(copy_u8Mode ==OUTPUT )
				{
					SET_BIT(DDRA ,copy_u8Pin);
				}
				else {
					CLEAR_BIT(DDRA,copy_u8Pin);
				}
				break;
			case GPIOB :
				if(copy_u8Mode ==OUTPUT )
				{
					SET_BIT(DDRB ,copy_u8Pin);
				}
				else {
					CLEAR_BIT(DDRB,copy_u8Pin);
				}
				break;
			case GPIOC :
				if(copy_u8Mode ==OUTPUT )
				{
					SET_BIT(DDRC ,copy_u8Pin);
				}
				else {
					CLEAR_BIT(DDRC,copy_u8Pin);
				}
				break;
			case GPIOD :
				if(copy_u8Mode ==OUTPUT )
				{
					SET_BIT(DDRD ,copy_u8Pin);
				}
				else {
					CLEAR_BIT(DDRD,copy_u8Pin);
				}
				break;	
			default:
				break;
		}
	}
	
	void GPIO_voidWritePin (u8  copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Value )
	{
		switch(copy_u8Port)
		{
			case GPIOA :
				if(copy_u8Value ==HIGH )
				{
					SET_BIT(PORTA ,copy_u8Pin);
				}
				else {
					CLEAR_BIT(PORTA,copy_u8Pin);
				}
				break;
			case GPIOB :
				if(copy_u8Value ==HIGH )
				{
					SET_BIT(PORTB ,copy_u8Pin);
				}
				else {
					CLEAR_BIT(PORTB,copy_u8Pin);
				}
				break;
			case GPIOC :
				if(copy_u8Value ==HIGH )
				{
					SET_BIT(PORTC ,copy_u8Pin);
				}
				else {
					CLEAR_BIT(PORTC,copy_u8Pin);
				}
				break;
			case GPIOD :
				if(copy_u8Value == HIGH )
				{
					SET_BIT(PORTD ,copy_u8Pin);
				}
				else {
					CLEAR_BIT(PORTD,copy_u8Pin);
				}
				break;	
			default:
				break;
		}
		
	}
	
	u8	GPIO_u8ReadPin(	u8  copy_u8Port ,u8 copy_u8Pin )
	{
		u8 Local_u8ReturnValue ;
		switch(copy_u8Port){
			case GPIOA :
				Local_u8ReturnValue = GET_BIT(PINA,copy_u8Pin);
				break ;
			case GPIOB :
				Local_u8ReturnValue = GET_BIT(PINB,copy_u8Pin);
				break ;
			case GPIOC :
				Local_u8ReturnValue = GET_BIT(PINC,copy_u8Pin);
				break ;
			case GPIOD :
				Local_u8ReturnValue = GET_BIT(PIND,copy_u8Pin);
				break ;
			default:
			break;
		}
		return Local_u8ReturnValue ;
		
	}
	
	void GPIO_voidTogPin 	( u8 copy_u8Port , u8 copy_u8Pin )
	{
		switch(copy_u8Port){
			case GPIOA :
				TOG_BIT(PORTA,copy_u8Pin);
				break ;             
			case GPIOB :            
				TOG_BIT(PORTB,copy_u8Pin);
				break ;             
			case GPIOC :            
				TOG_BIT(PORTC,copy_u8Pin);
				break ;             
			case GPIOD : 
				TOG_BIT(PORTD,copy_u8Pin);
				break ;               
			default:
			break;
		}
		
		
	}
	void GPIO_voidSetPortDDR (u8  copy_u8Port , u8 copy_u8Mode )
	{
		switch(copy_u8Port)
		{
			case GPIOA :
				if(copy_u8Mode ==OUTPUT )
				{
					DDRA= 0xFF;
				}
				else {
					DDRA = 0x00 ;
				}
				break;
			case GPIOB :
				if(copy_u8Mode ==OUTPUT )
				{
					DDRB = 0xFF;
				}
				else {
					DDRB = 0x00;
				}
				break;
			case GPIOC :
				if(copy_u8Mode ==OUTPUT )
				{
					DDRC = 0xFF ;
				}
				else {
					DDRC = 0x00 ;
				}
				break;
			case GPIOD :
				if(copy_u8Mode ==OUTPUT )
				{
					DDRD = 0xFF;
				}
				else {
					DDRD = 0x00;
				}
				break;	
			default:
				break;
		}
	}
	void	GPIO_voidWritePort (u8 copy_u8Port , u8 copy_u8Value)
	{
			switch(copy_u8Port)
		{
			case GPIOA :
				PORTA = copy_u8Value ;
				break;
			case GPIOB :
				PORTB = copy_u8Value;
				break;
			case GPIOC :
				PORTC = copy_u8Value;
				break;
			case GPIOD :
				PORTD = copy_u8Value;
				break;	
			default:
				break;
		}
		
			
			
		}
	void GPIO_voidSetLowNippleDDR(u8 copy_u8Port , u8 copy_u8Mode)
	{
		u8 i ;
		for (i= 0 ; i<4 ; i++){
			GPIO_voidSetPinDDR(copy_u8Port , i ,copy_u8Mode );
		}
	}
	void GPIO_voidSetHighNippleDDR(u8 copy_u8Port , u8 copy_u8Mode)
	{
		u8 i ;
		for (i= 4 ; i<8 ; i++){
			GPIO_voidSetPinDDR(copy_u8Port , i ,copy_u8Mode );
		}
	}
	void GPIO_voidWriteLowNipple (u8 copy_u8Port , u8 copy_u8Value )
	{
		copy_u8Value &= 0x0F;
		switch (copy_u8Port) {
			case GPIOA :
				PORTA &= 0xF0 ; 
				PORTA |= copy_u8Value ;
				break;
			case GPIOB :
				PORTB &= 0xF0 ; 
				PORTB |= copy_u8Value ;
				break;
			case GPIOC :
				PORTC &= 0xF0 ; 
				PORTC |= copy_u8Value ;
				break;
			case GPIOD :
				PORTD &= 0xF0 ; 
				PORTD |= copy_u8Value ;
				break;	
		}
	}
	void GPIO_voidWriteHighNipple (u8 copy_u8Port , u8 copy_u8Value )
	{
		copy_u8Value &=0xf0;
			switch (copy_u8Port){
				case GPIOA:
					PORTA &=0x0f;
					PORTA |=copy_u8Value;
					break;
				case GPIOB:
					PORTB &=0x0f;
					PORTB |=copy_u8Value;
					break;
				case GPIOC:
					PORTC &=0x0f;
					PORTC |=copy_u8Value;
					break;
				case GPIOD:
					PORTD &=0x0f;
					PORTD |=copy_u8Value;
					break;
				default: break;
			}
	}

	

