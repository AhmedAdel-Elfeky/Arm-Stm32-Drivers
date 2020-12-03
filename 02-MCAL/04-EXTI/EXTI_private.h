/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 24 Aug 2020                               */  
/* Version  : V01                                       */
/********************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RSTR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
} EXTI_type;

#define EXTI_BASE_ADDRESS 0x40010400
#define EXTI_REGISTERS ((volatile EXTI_type *)EXTI_BASE_ADDRESS)

#define EXTI_LINE_0     0
#define EXTI_LINE_1     1
#define EXTI_LINE_2     2
#define EXTI_LINE_3     3
#define EXTI_LINE_4     4
#define EXTI_LINE_5     5
#define EXTI_LINE_6     6
#define EXTI_LINE_7     7 
#define EXTI_LINE_8     8 
#define EXTI_LINE_9     9 
#define EXTI_LINE_10    10
#define EXTI_LINE_11    11
#define EXTI_LINE_12    12
#define EXTI_LINE_13    13
#define EXTI_LINE_14    14
#define EXTI_LINE_15    15

#define EXTI_RISING_EDGE       0
#define EXTI_FALLING_EDGE      1
#define EXTI_ON_CHANGE_EDGE          2




#endif
