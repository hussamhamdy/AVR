/*********************************************************************************/
/* Author    : Ahmed Assaf                                                       */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2

#define RCC_AFIO_ENABLE	    	0


#define RCC_GPIOA_ENABLE		2
#define RCC_GPIOB_ENABLE		3
#define RCC_GPIOC_ENABLE    	4

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);


#endif