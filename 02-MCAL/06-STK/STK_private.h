/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 03 sep 2020                               */  
/* Version  : V01                                       */
/********************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_BASE_ADDRESS	0xE000E010

typedef struct 
{
	volatile  u32 STK_CTRL;
	volatile  u32 STK_LOAD;
	volatile  u32 STK_VAL;
	volatile  u32 STK_VAL;
	volatile  u32 STK_CALIB;
}STK_type;

#define STK_REGISTERS    ((STK_type *)STK_BASE_ADDRESS)

#define STK_SRC_AHP           0
#define STK_SRC_AHP_8        1

#define STK_SINGLE_INTERVAL   0
#define STK_PERIOD_INTERVAL   1


#endif