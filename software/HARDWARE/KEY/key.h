#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"  

#define KEYUP  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_0)//读取按键上
#define KEYDOWN  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_1)//读取按键下
#define KEYLEFT  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3)//读取按键左
#define KEYRIGHT  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)//读取按键右
#define KEYOK  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_4)//读取按键OK

#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//读取按键0
#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//读取按键1 

#define KEY0_PRES 1
#define KEY1_PRES 2
#define KEYUP_PRES 3
#define KEYDOWN_PRES 4
#define KEYLEFT_PRES 5
#define KEYRIGHT_PRES 6
#define KEYOK_PRES 7

void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8 mode);  	//按键扫描函数
u8 KEY01_Scan(void);

#endif
