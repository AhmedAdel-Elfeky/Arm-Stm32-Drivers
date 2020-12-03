/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 8 Aug 2020                                */  
/* Version  : V01                                       */
/********************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/* BUSes in system */
#define RCC_AHB    0
#define	RCC_APB1   1
#define	RCC_APB2   2

/* AHP peripherals */
#define RCC_AHP_SDIO_ID   10
#define RCC_AHP_FSMC_ID   8
#define RCC_AHP_CRC_ID    6
#define RCC_AHP_FLITF_ID  4
#define RCC_AHP_SRAM_ID   2
#define RCC_AHP_DMA2_ID   1
#define RCC_AHP_DMA1_ID   0

/* APB2 peripherals */
#define RCC_APB2_TIM11_ID   21
#define RCC_APB2_TIM10_ID   20
#define RCC_APB2_TIM9_ID    19
#define RCC_APB2_ADC3_ID    15
#define RCC_APB2_USART1_ID  14
#define RCC_APB2_TIM8_ID    13
#define RCC_APB2_SPI1_ID    12
#define RCC_APB2_TIM1_ID    11
#define RCC_APB2_ADC2_ID    10
#define RCC_APB2_ADC1_ID    9
#define RCC_APB2_IOPG_ID    8
#define RCC_APB2_IOPF_ID    7
#define RCC_APB2_IOPE_ID    6
#define RCC_APB2_IOPD_ID    5
#define RCC_APB2_IOPC_ID    4
#define RCC_APB2_IOPB_ID    3
#define RCC_APB2_IOPA_ID    2
#define RCC_APB2_AFIO_ID    0

/* APB1 peripherals */
#define RCC_APB1_DAC_ID     29
#define RCC_APB1_PWR_ID     28
#define RCC_APB1_BKP_ID     27
#define RCC_APB1_CAN_ID     25
#define RCC_APB1_USB_ID     23
#define RCC_APB1_I2C2_ID    22
#define RCC_APB1_I2C1_ID    21
#define RCC_APB1_USART5_ID  20
#define RCC_APB1_USART4_ID  19
#define RCC_APB1_USART3_ID  18
#define RCC_APB1_USART2_ID  17
#define RCC_APB1_SPI3_ID    15
#define RCC_APB1_SPI2_ID    14
#define RCC_APB1_WWDG_ID    11
#define RCC_APB1_TIM14_ID   8
#define RCC_APB1_TIM13_ID   7
#define RCC_APB1_TIM12_ID   6
#define RCC_APB1_TIM7_ID    5
#define RCC_APB1_TIM6_ID    4
#define RCC_APB1_TIM5_ID    3
#define RCC_APB1_TIM4_ID    2
#define RCC_APB1_TIM3_ID    1
#define RCC_APB1_TIM2_ID    0


void RCC_voidInitSystemClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);


#endif
