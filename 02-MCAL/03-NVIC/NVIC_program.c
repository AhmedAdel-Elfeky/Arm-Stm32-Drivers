/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 22 Aug 2020                               */  
/* Version  : V01                                       */
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void _MNVIC_voidInit(void)
{
	#define SCB_AIRCR *((u32*)0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

void MNVIC_voidEnableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << copy_u8IntNumber);
	}
	else
	{
			/* return error */
	}
	return;
}

void MNVIC_voidDisableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << copy_u8IntNumber);
	}
	else
	{
			/* return error */
	}
	return;
}

void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << copy_u8IntNumber);
	}
	else
	{
			/* return error */
	}
	return;
}

void MNVIC_voidClearPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << copy_u8IntNumber);
	}
	else
	{
			/* return error */
	}
	return;
}

u8 MNVIC_u8GetActiveFlag(u8 copy_u8IntNumber)
{
	u8 Local_u8Result=0;
	if(copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 59)
	{
		copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,copy_u8IntNumber);
	}
	else
	{
			/* return error */
	}
	return Local_u8Result;
}

void MNVIC_voidSetIntPriority(s8 copy_s8IntID,u8 copy_u8GroupPriority, u8 copy_u8SubGroupPriority, u32 copy_u32Group)
{
	u8 Local_u8Priority = copy_u8SubGroupPriority | (copy_u8GroupPriority<<((copy_u32Group - 0x5FA0300)/256));	
	/* core peropheral */
	
	/* external peropheral */
	if(copy_s8IntID >= 0)
	{
		NVIC_IPR[copy_s8IntID] = Local_u8Priority << 4;
	}
	SCB_AIRCR = copy_u32Group ;

}
