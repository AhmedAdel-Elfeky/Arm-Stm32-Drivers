/********************************************************/
/* AUTHOR   : Ahmed Adel                                */
/* Date     : 12 Aug 2020                                */  
/* Version  : V01                                       */
/********************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/* GPIO ports */
#define GPIO_PORT_A  0
#define GPIO_PORT_B  1
#define GPIO_PORT_C  2

/* GPIO Pins */
#define GPIO_PIN_0   0 
#define GPIO_PIN_1   1
#define GPIO_PIN_2   2
#define GPIO_PIN_3   3
#define GPIO_PIN_4   4
#define GPIO_PIN_5   5
#define GPIO_PIN_6   6
#define GPIO_PIN_7   7
#define GPIO_PIN_8   8
#define GPIO_PIN_9   9
#define GPIO_PIN_10  10
#define GPIO_PIN_11  11
#define GPIO_PIN_12  12
#define GPIO_PIN_13  13
#define GPIO_PIN_14  14
#define GPIO_PIN_15  15

#define GPIO_OUTPUT_SPEED_10MHZ_PP    0b0001
#define GPIO_OUTPUT_SPEED_10MHZ_OD    0b0101
#define GPIO_OUTPUT_SPEED_10MHZ_AFPP  0b1001
#define GPIO_OUTPUT_SPEED_10MHZ_AFOD  0b1101

#define GPIO_OUTPUT_SPEED_2MHZ_PP     0b0010
#define GPIO_OUTPUT_SPEED_2MHZ_OD     0b0110
#define GPIO_OUTPUT_SPEED_2MHZ_AFPP   0b1010
#define GPIO_OUTPUT_SPEED_2MHZ_AFOD   0b1110

#define GPIO_OUTPUT_SPEED_50MHZ_PP    0b0011
#define GPIO_OUTPUT_SPEED_50MHZ_OD    0b0111
#define GPIO_OUTPUT_SPEED_50MHZ_AFPP  0b1011
#define GPIO_OUTPUT_SPEED_50MHZ_AFOD  0b1111

#define GPIO_INPUT_ANALOG               0b0000
#define GPIO_INPUT_FLOATING             0b0100
#define GPIO_INPUT_PULL_U_D             0b1000

#define GPIO_HIGH   1
#define GPIO_LOW    0


void GPIO_voidSetPinDirection(u8 copy_u8PortNum,u8 copy_u8PinNum,u8 copy_u8Mode);
void GPIO_voidSetPinValue(u8 copy_u8PortNum,u8 copy_u8PinNum,u8 copy_u8Value);
u8 GPIO_u8GetPinValue(u8 copy_u8PortNum,u8 copy_u8PinNum);




#endif