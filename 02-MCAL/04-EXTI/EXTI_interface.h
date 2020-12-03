/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 24 Aug 2020                               */  
/* Version  : V01                                       */
/********************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 copy_u8LineNum);
void MEXTI_voidDisableEXTI(u8 copy_u8LineNum);
void MEXTI_voidSwTrigger(u8 copy_u8LineNum);
void MEXTI_voidSetSignalLatch(u8 copy_u8LineNum , u8 copy_u8Mode);







#endif
