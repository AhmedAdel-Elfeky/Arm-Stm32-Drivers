/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 1 OCT 2020                                */  
/* Version  : V01                                       */
/********************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void SOS_voidCreateTask(u8 Copy_u8Periority , u16 Copy_u16Periodicity , void (*Fptr)(void));
void SOS_voidStart(void);

#endif
