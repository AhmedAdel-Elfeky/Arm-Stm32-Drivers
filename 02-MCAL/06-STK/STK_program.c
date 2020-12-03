/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 03 sep 2020                               */  
/* Version  : V01                                       */
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* Define Callback Global Variable */
static void(*STK_CallBack)(void);

/* Define Variable for interval mode */
static u8 STK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
	#if STK_CLOCK_SOURCE == STK_SRC_AHP_8
		 /* Disable STK - Disable STK Interrupt - Set clock source AHB/2 */
		 STK_REGISTERS -> STK_CTRL = 0;
	#elif STK_CLOCK_SOURCE == STK_SRC_AHP
		/* Disable STK - Disable STK Interrupt - Set clock source AHB*/
		 STK_REGISTERS -> STK_CTRL = 4;
	#else
		#error("Wrong Selection");
	#endif
}
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/* Load ticks to load register */
	STK_REGISTERS -> STK_LOAD = Copy_u32Ticks;
	/* Start Timer */
	SET_BIT(STK_REGISTERS -> STK_CTRL,0);
	/* Wait till flag is raised */
	while(GET_BIT(STK_REGISTERS -> STK_CTRL, 16) == 0);
	/* Stop Timer */
	CLR_BIT(STK_REGISTERS -> STK_CTRL,0);
	STK_REGISTERS -> STK_LOAD = 0;
	STK_REGISTERS -> STK_VAL  = 0; 
}
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_Ptr)(void))
{
	/* load Register with counter value */
	STK_REGISTERS -> STK_LOAD = Copy_u32Ticks;
	/* start the timer */
	SET_BIT(STK_REGISTERS -> STK_CTRL,0);
	/* call back function */
	STK_CallBack = Copy_Ptr;
	/* set mode to single */
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
	/* enable STK interrupt */
	SET_BIT(STK_REGISTERS -> STK_CTRL,1);
}
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_Ptr)(void))
{
	/* load Register with counter value */
	STK_REGISTERS -> STK_LOAD = Copy_u32Ticks;
	/* start the timer */
	SET_BIT(STK_REGISTERS -> STK_CTRL,0);
	/* call back function */
	STK_CallBack = Copy_Ptr;
	/* set mode to period */
	STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;
	/* enable STK interrupt */
	SET_BIT(STK_REGISTERS -> STK_CTRL,1);
	
}
void MSTK_voidStopInterval(void)
{
	CLR_BIT(STK_REGISTERS -> STK_CTRL , 1);
	CLR_BIT(STK_REGISTERS -> STK_CTRL , 0);
	STK_REGISTERS -> STK_LOAD = 0;
	STK_REGISTERS -> STK_VAL  = 0;
}
u32  MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = STK_REGISTERS-> STK_LOAD - STK_REGISTERS -> STK_VAL;
	return Local_u32ElapsedTime;
}
u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = STK_REGISTERS -> STK_VAL;
	return Local_u32ElapsedTime;
}

void SysTick_Handler(void)
{
	u8 Local_u8Temporary;
		
	if(STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK_REGISTERS -> STK_CTRL ,1);
		
		/* stop Timer */
		CLR_BIT(STK_REGISTERS -> STK_CTRL , 0);
		STK_REGISTERS -> STK_LOAD = 0;
		STK_REGISTERS -> STK_VAL  = 0;
	}
	
	/* Callback */
	STK_CallBack();
		
	/*to clear counter flag read it*/
	Local_u8Temporary = GET_BIT(STK_REGISTERS -> STK_CTRL , 16);
}

