/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 1 OCT 2020                                */
/* Version  : V01                                       */
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"

#include "OS_private.h"
#include "OS_interface.h"
#include "OS_config.h"


static Task OS_Tasks[NUMBER_OF_TASKS]={0}

void SOS_voidCreateTask(u8 Copy_u8Periority , u16 Copy_u16Periodicity,u8 Copy_u8FirstDelay , void (*ptr)(void))
{
	OS_Tasks[Copy_u8Periority].periodicity = Copy_u16Periodicity;
	OS_Tasks[Copy_u8Periority].Fptr = ptr;
	OS_Tasks[Copy_u8Periority].firstDelay = Copy_u8FirstDelay;
}
void SOS_voidStart(void)
{
	/* initialization */
	MSTK_voidInit();
	/*Tick => 1 msec*/
	MSTK_voidSetIntervalPeriodic(1000,Scheduler);
}

volatile u16 TickCounts = 0;
void Scheduler(void)
{
	for(u8 i=0 ; i < NUMBER_OF_TASKS ;I++)
	{
		if((TickCounts % OS_Tasks[i].periodicity) == 0)
		{
			OS_Tasks[i].Fptr();
		}
		TickCounts++;
	}
}