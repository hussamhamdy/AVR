#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "HLEDMAT_config.h"

void HLEDMAT_voidInit(void)
{
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_0,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_1,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_2,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_3,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_4,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_5,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_6,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_7,0b0010);
	
	
	MGPIO_VidSetPinDirection(HLEDMAT_COL_0,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_1,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_2,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_3,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_4,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_5,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_6,0b0010);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_7,0b0010);
}

void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame)
{
	


	/* Reset the frame Start */
	 u8 HLEDMAT_u8CurrentIdx = 0;
	
	for (HLEDMAT_u8CurrentIdx = 0 ; HLEDMAT_u8CurrentIdx <8 ; HLEDMAT_u8CurrentIdx++)
	{
		SetRowsValue  (Copy_u8Frame[HLEDMAT_u8CurrentIdx]);
		ActivateColumn(HLEDMAT_u8CurrentIdx);
		MSTK_voidSetBusyWait(2500);
	}
	/* Start timer */
	
}


/*

void DisplayNextColumn(void)
{
	HLEDMAT_u8CurrentIdx++;
	if (HLEDMAT_u8CurrentIdx == 8)
	{
		HLEDMAT_u8CurrentIdx = 0;
	}
	
	/* Dislay The first Column
	ActivateColumn(HLEDMAT_u8CurrentIdx);
	SetRowsValue  (Copy_u8Frame[HLEDMAT_u8CurrentIdx]);
} */

void SetRowsValue  (u8 Copy_u8Value)
{
	u8 Local_u8Idx;
	u8 Local_u8Bit[8];
	for (Local_u8Idx =0; Local_u8Idx<8;Local_u8Idx++)
	{
		Local_u8Bit[Local_u8Idx] =GET_BIT(Copy_u8Value,Local_u8Idx);
	}
	
	MGPIO_VidSetPinValue(HLEDMAT_ROW_0,Local_u8Bit[0]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_1,Local_u8Bit[1]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_2,Local_u8Bit[2]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_3,Local_u8Bit[3]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_4,Local_u8Bit[4]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_5,Local_u8Bit[5]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_6,Local_u8Bit[6]);
	MGPIO_VidSetPinValue(HLEDMAT_ROW_7,Local_u8Bit[7]);
}

void ActivateColumn(u8 Copy_u8Col)
{
	/* Disable All */
	MGPIO_VidSetPinValue(HLEDMAT_COL_0,HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_1,HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_2,HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_3,HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_4,HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_5,HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_6,HIGH);
	MGPIO_VidSetPinValue(HLEDMAT_COL_7,HIGH);
	
	/* Enable the desired pin only */
	switch (Copy_u8Col)
	{
		case 0: MGPIO_VidSetPinValue(HLEDMAT_COL_0,LOW); break;
		case 1: MGPIO_VidSetPinValue(HLEDMAT_COL_1,LOW); break;
		case 2: MGPIO_VidSetPinValue(HLEDMAT_COL_2,LOW); break;
		case 3: MGPIO_VidSetPinValue(HLEDMAT_COL_3,LOW); break;
		case 4: MGPIO_VidSetPinValue(HLEDMAT_COL_4,LOW); break;
		case 5: MGPIO_VidSetPinValue(HLEDMAT_COL_5,LOW); break;
		case 6: MGPIO_VidSetPinValue(HLEDMAT_COL_6,LOW); break;
		case 7: MGPIO_VidSetPinValue(HLEDMAT_COL_7,LOW); break;
	}
}
