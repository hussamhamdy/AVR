/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 18 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/*OPTIONS: MASTER OR SLAVE */
#define SPI_MODE MASTER
/*OPTIONS : MSB OR LSB */
#define SPI_DATAORDER LSB
/*OPTIONS : IDEL_LOW OR IDEL_HIGH */
#define SPI_OPERATINGLEVEL IDEL_LOW
/*OPTIONS : RISING OR FALLING */
#define SPI_CLOCKPHASE RISING
/*OPTIONS : NORMAL_SPEED OR DOUBLE_SPEED */
#define SPI_SPEEDMODE NORMAL_SPEED
/*F_4 , F_16 , F_64 , F_128 , F_2 , F_8 , F_32 ,FD_64*/
#define SPI_FREQUENCY_PRESCALER F_128



#endif
