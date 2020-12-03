/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 1 OCT 2020                                */  
/* Version  : V01                                       */
/********************************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct
{
	u16 periodicity   ;
	void (*Fptr)(void);
	u8 firstDelay;
	
}Task;




#endif  
