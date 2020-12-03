/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 22 Aug 2020                               */  
/* Version  : V01                                       */
/********************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define MNVIC_GROUP_4_SUB_0    0x05FA0300    //4 bits for group
#define MNVIC_GROUP_3_SUB_1    0x05FA0400    //3 bits for group and 1 for sub-group
#define MNVIC_GROUP_2_SUB_2    0x05FA0500    //2 bits for group and 2 for sub-group
#define MNVIC_GROUP_1_SUB_3    0x05FA0600    //1 bits for group and 3 for sub-group
#define MNVIC_GROUP_0_SUB_4    0x05FA0700    //0 bits for group and 4 for sub-group


#define NVIC_BASE_ADDRESS 0xE000E100

#define NVIC_ISER0   *((u32 *)(NVIC_BASE_ADDRESS + 0x00))
#define NVIC_ISER1   *((u32 *)(NVIC_BASE_ADDRESS + 0x04))

#define NVIC_ICER0   *((u32 *)(NVIC_BASE_ADDRESS + 0x80))
#define NVIC_ICER1   *((u32 *)(NVIC_BASE_ADDRESS + 0x84))

#define NVIC_ISPR0   *((u32 *)(NVIC_BASE_ADDRESS + 0x100))
#define NVIC_ISPR1   *((u32 *)(NVIC_BASE_ADDRESS + 0x104))

#define NVIC_ICPR0   *((u32 *)(NVIC_BASE_ADDRESS + 0x180))
#define NVIC_ICPR1   *((u32 *)(NVIC_BASE_ADDRESS + 0x184))

#define NVIC_IABR0   *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x200))
#define NVIC_IABR1   *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x204))

#define NVIC_IPR      ((volatile u8  *)(NVIC_BASE_ADDRESS + 0x300))

#define SCB_BASE_ADDRESS  0xE000ED00
//#define SCB_AIRCR    *((volatile u32 *)(SCB_BASE_ADDRESS + 0x0C))

#endif
