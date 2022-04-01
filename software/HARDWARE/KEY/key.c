#include "key.h"
#include "delay.h"
#include "beep.h"

//按键初始化函数 
//PA15和PC5 设置成输入
void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE,ENABLE);//使能PORTA,PORTC时钟

	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//关闭jtag，使能SWD，可以用SWD模式调试
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;//PD0  UP
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIOD0
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;//PD1  DOWN
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIOD1
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;//PD2  RIGHT
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIOD2
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;//PD3  LEFT
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIOD3
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;//PD4  OK
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIOD4
	 
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;//PE2  KEY0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE2
  
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;//PE3  KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE3
} 

//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//返回值：
//0，没有任何按键按下 
//注意此函数有响应优先级,KEY0>KEY1>WK_UP!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志  只有第一次初始化时候赋值
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEYUP==0||KEYDOWN==0||KEYLEFT==0||KEYRIGHT==0||KEYOK==0))
	{
		delay_ms(10);//去抖动 
		key_up=0; 
		if(KEYUP==1)return KEYUP_PRES; 
		else if(KEYDOWN==1)return KEYDOWN_PRES;
		else if(KEYLEFT==1)return KEYLEFT_PRES;
		else if(KEYRIGHT==1)return KEYRIGHT_PRES;
		else if(KEYOK==1)return KEYOK_PRES;  
	}else if(KEYUP==1&&KEYDOWN==1&&KEYLEFT==1&&KEYRIGHT==1&&KEYOK==1)key_up=1; 	     
	return 0;// 无按键按下
}


u8 KEY01_Scan()
{	 
	if(KEY0==0)
	{
		
		delay_ms(10); 
		if(KEY0==0){
			BEEP=1;
			while(KEY0 == 0);
			BEEP=0;
			return KEY0_PRES;
		} 
	}
	if(KEY1==0)
	{
		
		delay_ms(10);
		
		if(KEY1==0){
			BEEP=1;
			while(KEY1 == 0);
			BEEP=0;
			return KEY1_PRES;
		} 
	}
	if(KEYUP==0)
	{ 
		delay_ms(10); 
		if(KEYUP==0){
			BEEP=1;
			while(KEYUP == 0);
			BEEP=0;
			return KEYUP_PRES;
		} 
	}
	if(KEYDOWN==0)
	{ 
		delay_ms(10); 
		if(KEYDOWN==0){
			BEEP=1;
			while(KEYDOWN == 0);
			BEEP=0;
			return KEYDOWN_PRES;
		} 
	} 
	if(KEYLEFT==0)
	{ 
		delay_ms(10); 
		if(KEYLEFT==0){
			BEEP=1;
			while(KEYLEFT == 0);
			BEEP=0;
			return KEYLEFT_PRES;
		} 
	} 
	if(KEYRIGHT==0)
	{ 
		delay_ms(10); 
		if(KEYRIGHT==0){
			BEEP=1;
			while(KEYRIGHT == 0);
			BEEP=0;
			return KEYRIGHT_PRES;
		} 
	}
	if(KEYOK==0)
	{ 
		delay_ms(10); 
		if(KEYOK==0){
			BEEP=1;
			while(KEYOK == 0);
			BEEP=0;
			return KEYOK_PRES;
		} 
	} 
	return 0;// 无按键按下
}

