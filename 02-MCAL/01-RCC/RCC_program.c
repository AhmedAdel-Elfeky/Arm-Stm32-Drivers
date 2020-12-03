/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 8 Aug 2020                                */
/* Version  : V01                                       */
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSystemClock(void)
{
	#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000; /*Enable HSE with no bypass */
		RCC_CFGR = 0x00000001; /*select HSE to be system CLK */
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000; /*Enable HSE with bypass */
		RCC_CFGR = 0x00000001; /*select HSE to be system CLK */
	#elif RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /*Enable HSI */
		RCC_CFGR = 0x00000000; /*select HSI to be system CLK */
	#elif RCC_CLOCK_TYPE == RCC_PLL
		#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			SET_BIT(RCC_CFGR,1); /* select PLL to be system CLK */
			CLR_BIT(RCC_CFGR,0);
			CLR_BIT(RCC_CFGR,16); /* make HSI/2 input to PLL */
			RCC_CFGR &= (~(0x000f << 17)); /* Writing the MUL VAL */
			RCC_CFGR |= (RCC_PLL_MUL_VAL << 17);
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2 /* select PLL to be system CLK and HSE/2 */
			SET_BIT(RCC_CFGR,1); /* select PLL to be system CLK */
			CLR_BIT(RCC_CFGR,0);
			SET_BIT(RCC_CFGR,16); /* make HSI/2 input to PLL */
			SET_BIT(RCC_CFGR,17);
			RCC_CFGR &= (~(0xf << 17)); /* Writing the MUL VAL */
			RCC_CFGR |= (RCC_PLL_MUL_VAL << 17);
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			SET_BIT(RCC_CFGR,1); /* select PLL to be system CLK */
			CLR_BIT(RCC_CFGR,0);
			SET_BIT(RCC_CFGR,16); /* make HSI input to PLL */
			CLR_BIT(RCC_CFGR,17);
			RCC_CFGR &= (~(0x000f << 17)); /* Writing the MUL VAL */
			RCC_CFGR |= (RCC_PLL_MUL_VAL << 17);
		#endif
		SET_BIT(RCC_CR,24); /*Enable PLL */
	#else
		#error("you choosed wrong type")
	#endif
}


void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId); break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId); break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId); break;
			//default       : /*Return Error */                   break;
		}
	}
	else
	{
		/* Return error */
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId); break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId); break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId); break;
			//default       : /*Return Error */                   break;
		}
	}
	else
	{
		/* Return error */
	}
}

