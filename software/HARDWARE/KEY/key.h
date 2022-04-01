#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"  

#define KEYUP  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_0)//��ȡ������
#define KEYDOWN  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_1)//��ȡ������
#define KEYLEFT  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3)//��ȡ������
#define KEYRIGHT  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)//��ȡ������
#define KEYOK  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_4)//��ȡ����OK

#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//��ȡ����0
#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//��ȡ����1 

#define KEY0_PRES 1
#define KEY1_PRES 2
#define KEYUP_PRES 3
#define KEYDOWN_PRES 4
#define KEYLEFT_PRES 5
#define KEYRIGHT_PRES 6
#define KEYOK_PRES 7

void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8 mode);  	//����ɨ�躯��
u8 KEY01_Scan(void);

#endif
