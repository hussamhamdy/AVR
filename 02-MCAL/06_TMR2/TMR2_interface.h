/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 18 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef TMR2_INTERFACE_H
#define TMR2_INTERFACE_H

#define TMR2_clk		0x01
#define	TMR2_clk_8		0x02
#define TMR2_clk_32 	0x03
#define TMR2_clk_64		0x04
#define TMR2_clk_128	0x05
#define	TMR2_clk_256	0x06
#define	TMR2_clk_1024	0x07




	void TMR2_voidInit(void);
	void TMR2_voidStart(u8 copy_u8PreScalar);
	void TMR2_voidSetTCNT0 (u8 copy_u8InitVal);
	u32  TMR2_u32ReadTmr0	(void);
	void TMR2_voidSetNormWInt( void (*copy_CB)(void));
	void TMR2_voidSetOCR0 (u8 copy_u8InitVal);
	void TMR2_voidSetCTCWInt( void (*copy_CB)(void));
	void TMR2_voidStopTmr(void);
	void TMR2_voidDInit (void);

#endif