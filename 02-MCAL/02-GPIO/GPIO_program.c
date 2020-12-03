/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 12 Aug 2020                                */
/* Version  : V01                                       */
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection(u8 copy_u8PortNum,u8 copy_u8PinNum,u8 copy_u8Mode)
{
	switch(copy_u8PortNum)
	{
		case GPIO_PORT_A:
						if(copy_u8PinNum <= 7)
						{
							GPIOA_CRL &= ~((0xF)<<(copy_u8PinNum*4));
							GPIOA_CRL |= (copy_u8Mode) << (copy_u8PinNum*4);
						}
						else if(copy_u8PinNum <= 15)
						{
							GPIOA_CRH &= ~((0xF)<<(copy_u8PinNum*4));
							GPIOA_CRH |= ((copy_u8Mode)<<(copy_u8PinNum*4));
						}
						break;
		case GPIO_PORT_B:
						if(copy_u8PinNum <= 7)
						{
							GPIOB_CRL &= ~((0xF)<<(copy_u8PinNum*4));
							GPIOB_CRL |= ((copy_u8Mode)<<(copy_u8PinNum*4));
						}
						else if(copy_u8PinNum <= 15)
						{
							GPIOB_CRH &= ~((0xF)<<(copy_u8PinNum*4));
							GPIOB_CRH |= ((copy_u8Mode)<<(copy_u8PinNum*4));
						}
						break;
		case GPIO_PORT_C:
						if(copy_u8PinNum <= 7)
						{
							GPIOC_CRL &= ~((0xF)<<(copy_u8PinNum*4));
							GPIOC_CRL |= ((copy_u8Mode)<<(copy_u8PinNum*4));
						}
						else if(copy_u8PinNum <= 15)
						{
							GPIOC_CRH &= ~((0xF)<<(copy_u8PinNum*4));
							GPIOC_CRH |= ((copy_u8Mode)<<(copy_u8PinNum*4));
						}
						break;
		default:break;
		
	}
	
	return;
}

void GPIO_voidSetPinValue(u8 copy_u8PortNum,u8 copy_u8PinNum,u8 copy_u8Value)
{
	if(copy_u8PortNum <= GPIO_PORT_C )
	{
		if(copy_u8PinNum <= GPIO_PIN_15)
		{
			switch(copy_u8PortNum)
			{
				case GPIO_PORT_A:
								GPIOA_ODR &= ~(1 << copy_u8PinNum);
								GPIOA_ODR |= (copy_u8Value << copy_u8PinNum);
								break;	
				case GPIO_PORT_B:
								GPIOB_ODR &= ~(1 << copy_u8PinNum);
								GPIOB_ODR |= (copy_u8Value << copy_u8PinNum);
								break;
				case GPIO_PORT_C:
								GPIOC_ODR &= ~(1 << copy_u8PinNum);
								GPIOC_ODR |= (copy_u8Value << copy_u8PinNum);
								break;
				default:break;
								
			}
		}
		else
		{
				/* return error */
		}
	}
	else
	{
		/*
			return error
		#error("wrong port number"); */
	}
}
u8 GPIO_u8GetPinValue(u8 copy_u8PortNum,u8 copy_u8PinNum)
{
	u8 LOC_u8PinValue=0;
	if(copy_u8PortNum <= GPIO_PORT_C )
	{
		switch (copy_u8PortNum)
		{
			case GPIO_PORT_A:
							LOC_u8PinValue = GET_BIT(GPIOA_IDR,copy_u8PinNum);
							break;
			case GPIO_PORT_B:
							LOC_u8PinValue = GET_BIT(GPIOB_IDR,copy_u8PinNum);
							break;
			case GPIO_PORT_C:
							LOC_u8PinValue = GET_BIT(GPIOC_IDR,copy_u8PinNum);
							break;
			default:break;							
		}
	}
	else
	{
		/*
			return error */
	}
	
	return LOC_u8PinValue;
}
