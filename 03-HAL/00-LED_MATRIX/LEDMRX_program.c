/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 8 SEP 2020                               */  
/* Version  : V01                                       */
/********************************************************/

#include "STD_TYPES"
#include "BIT_MATH"
#include "GPIO_interface"
#include "STK_interface"


#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

void HLEDMRX_voidInit()
{
	     
	GPIO_voidSetPinDirection(LEDMRX_ROW0_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW1_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW2_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW3_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW4_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW5_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW6_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW7_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	
	GPIO_voidSetPinDirection(LEDMRX_COL0_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COL1_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COL2_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COL3_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COL4_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COL5_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COL6_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COL7_PIN,GPIO_OUTPUT_SPEED_2MHZ_PP);

}

void HLEDMRX_voidDisply (u8 *Copy_u8Data)
{
	
	/* Column 0*/
	DisableAllCOLS();
	SetRowsValues(Copy_u8Data[0]);
	GPIO_voidSetPinValue(LEDMRX_COL0_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //dely 2.5 msec 
	
	/* Column 1*/
	DisableAllCOLS();
	SetRowsValues(Copy_u8Data[1]);
	GPIO_voidSetPinValue(LEDMRX_COL1_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //dely 2.5 msec 
	
	/* Column 2*/
	DisableAllCOLS();
	SetRowsValues(Copy_u8Data[2]);
	GPIO_voidSetPinValue(LEDMRX_COL2_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //dely 2.5 msec 

	/* Column 3*/
	DisableAllCOLS();
	SetRowsValues(Copy_u8Data[3]);
	GPIO_voidSetPinValue(LEDMRX_COL3_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //delay 2.5 msec 

	/* Column 4*/
	DisableAllCOLS();
	SetRowsValues(Copy_u8Data[4]);
	GPIO_voidSetPinValue(LEDMRX_COL4_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //delay 2.5 msec 

	/* Column 5*/
	DisableAllCOLS();
	SetRowsValues(Copy_u8Data[5]);
	GPIO_voidSetPinValue(LEDMRX_COL5_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //dely 2.5 msec 

	/* Column 6*/
	DisableAllCOLS();
	SetRowsValues(Copy_u8Data[6]);
	GPIO_voidSetPinValue(LEDMRX_COL6_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //dely 2.5 msec 

	/* Column 7*/
	DisableAllCOLS();
	SetRowsValues(Copy_u8Data[7]);
	GPIO_voidSetPinValue(LEDMRX_COL7_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //dely 2.5 msec 
	
}


static void DisableAllCOLS(void)
{
	GPIO_voidSetPinValue(LEDMRX_COL0_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL1_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL2_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL3_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL4_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL5_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL6_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL7_PIN,GPIO_HIGH);
	
}

static void SetRowsValues(u8 Copy_u8Data)
{
	u8 Local_u8BitValue;
	
	Local_u8BitValue = GET_BIT(Copy_u8Data,0);
	GPIO_voidSetPinValue(LEDMRX_ROW0_PIN,Local_u8BitValue);
	
	Local_u8BitValue = GET_BIT(Copy_u8Data,1);
	GPIO_voidSetPinValue(LEDMRX_ROW1_PIN,Local_u8BitValue);
	
	Local_u8BitValue = GET_BIT(Copy_u8Data,2);
	GPIO_voidSetPinValue(LEDMRX_ROW2_PIN,Local_u8BitValue);
	
	Local_u8BitValue = GET_BIT(Copy_u8Data,3);
	GPIO_voidSetPinValue(LEDMRX_ROW3_PIN,Local_u8BitValue);
	
	Local_u8BitValue = GET_BIT(Copy_u8Data,4);
	GPIO_voidSetPinValue(LEDMRX_ROW4_PIN,Local_u8BitValue);
	
	Local_u8BitValue = GET_BIT(Copy_u8Data,5;
	GPIO_voidSetPinValue(LEDMRX_ROW5_PIN,Local_u8BitValue);
	
	Local_u8BitValue = GET_BIT(Copy_u8Data,6);
	GPIO_voidSetPinValue(LEDMRX_ROW6_PIN,Local_u8BitValue);
	
	Local_u8BitValue = GET_BIT(Copy_u8Data,7);
	GPIO_voidSetPinValue(LEDMRX_ROW7_PIN,Local_u8BitValue);

}

