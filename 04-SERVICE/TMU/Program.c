#include "TMR2_interface.h"
u8 x ;
void delay_ms(u32 delay){
	TMR2_voidInit();
	if (delay < 10 )
	{
		TMR2_voidSetTCNT2(0);
		TMR2_voidSetOCR2(8);
		x = delay ;
		TMR2_voidSetCTCWithInterrupt(&FUN);
		TMR2_voidStart(1024);
		while(x != 0 );
		TMR2_voidStopTMR2();
		}
	else
	{
		x = delay / 10 ;
		TMR2_voidSetTMR2(0);
		TMR2_voidSetOCR2(80);
		TMR2_voidSetCTCWithInterrupt(&FUN);
		TMR2_voidStart(1024);
		while(x != 0 );
		TMR2_voidStopTMR2();
		x = delay % 10 ;
		TMR2_voidSetTMR2(0);
		TMR2_voidSetOCR2(8);
		TMR2_voidSetCTCWithInterrupt(&FUN);
		TMR2_voidStart(1024);
		while(x != 0 );
		
		
		
		
	}

	
}
void FUN (void)
{
	x--
}
