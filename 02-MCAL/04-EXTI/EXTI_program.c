/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 24 Aug 2020                               */  
/* Version  : V01                                       */
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (* EXTI0_CallBack[16])(void);

void MEXTI_voidInit()
{
#if EXTI_MODE == EXTI_RISING_EDGE
	SET_BIT(EXTI_REGISTERS -> RSTR , EXTI_LINE);
#elif EXTI_MODE == EXTI_FALLING_EDGE
	SET_BIT(EXTI_REGISTERS -> FTSR , EXTI_LINE);
#elif EXTI_MODE == EXTI_ON_CHANGE_EDGE
	SET_BIT(EXTI_REGISTERS -> FTSR , EXTI_LINE);
	SET_BIT(EXTI_REGISTERS -> RSTR , EXTI_LINE);
#else
	#error("Wrong Mode Selection");
#endif
/* Disable Interrupts */
	CLR_BIT(EXTI_REGISTERS -> IMR , EXTI_LINE);
}

void MEXTI_voidEnableEXTI(u8 copy_u8LineNum)
{
	SET_BIT(EXTI_REGISTERS -> IMR , copy_u8LineNum);
	return;
} 

void MEXTI_voidDisableEXTI(u8 copy_u8LineNum)
{
	CLR_BIT(EXTI_REGISTERS -> IMR , copy_u8LineNum);
	return;
}

void MEXTI_voidSwTrigger(u8 copy_u8LineNum)
{
	SET_BIT(EXTI_REGISTERS -> SWIER , copy_u8LineNum);

}
void MEXTI_voidSetSignalLatch(u8 copy_u8LineNum , u8 copy_u8Mode)
{
	switch(copy_u8Mode)
	{
		case EXTI_RISING_EDGE: 
									SET_BIT(EXTI_REGISTERS -> RSTR , copy_u8LineNum);
									break;
		case EXTI_FALLING_EDGE:
									SET_BIT(EXTI_REGISTERS -> FTSR , copy_u8LineNum);
									break;
		case EXTI_ON_CHANGE_EDGE:
									SET_BIT(EXTI_REGISTERS -> RSTR , copy_u8LineNum);
									SET_BIT(EXTI_REGISTERS -> FTSR , copy_u8LineNum);
									break;
		default:break;
	}
	SET_BIT(EXTI_REGISTERS -> IMR , copy_u8LineNum);

} 

void MEXTI0_voidSetCallBack( void (*Copy_ptr)(void))
{
	EXTI0_CallBack[0] = Copy_ptr;
}

void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack[0]();
	SET_BIT(EXTI_REGISTERS -> PR , 0);
}
