/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 26 Aug 2020                               */  
/* Version  : V01                                       */
/********************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

void MAFIO_voidSetEXTIConfiguration(u8 copy_u8LineNum , u8 copy_u8PortMap);

0000: AFIO_PORT_A_PIN_0
0001: AFIO_PORT_B_PIN_0
0010: AFIO_PORT_C_PIN_0

#define AFIO_PORT_A_PIN_0_15    0000
#define AFIO_PORT_B_PIN_0_15    0001
#define AFIO_PORT_C_PIN_13_15   0010




#endif