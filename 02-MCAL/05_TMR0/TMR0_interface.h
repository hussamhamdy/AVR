/*****************************************************/
/* Author : Hussam hamdy 						   	 */
/* Data : 13 Nov 2020								 */	
/* Version : V 1.0									 */
/* LOG : 											 */
/*													 */
/*****************************************************/

#ifndef TMR0_INTERFACE_H
#define TMR0_INTERFACE_H

#define TMR0_clk		0x01
#define	TMR0_clk_8		0x02
#define TMR0_clk_64 	0x03
#define TMR0_clk_256	0x04
#define TMR0_clk_1024	0x05
#define	TMR0_event_FE	0x06
#define	TMR0_event_RE	0x07




	void TMR0_voidInit(void);
	void TMR0_voidStart(u8 copy_u8PreScalar);
	void TMR0_voidSetTCNT0 (u8 copy_u8InitVal);
	u32  TMR0_u32ReadTmr0	(void);
	void TMR0_voidSetNormWInt( void (*copy_CB)(void));
	void TMR0_voidSetOCR0 (u8 copy_u8InitVal);
	void TMR0_voidSetCTCWInt( void (*copy_CB)(void));
	void TMR0_voidStopTmr(void);
	void TMR0_voidDInit (void);

#endif