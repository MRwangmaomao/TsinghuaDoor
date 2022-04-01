#include "key.h"
#include "delay.h"
#include "beep.h"

//������ʼ������ 
//PA15��PC5 ���ó�����
void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE,ENABLE);//ʹ��PORTA,PORTCʱ��

	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//�ر�jtag��ʹ��SWD��������SWDģʽ����
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;//PD0  UP
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��GPIOD0
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;//PD1  DOWN
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��GPIOD1
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;//PD2  RIGHT
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��GPIOD2
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;//PD3  LEFT
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��GPIOD3
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;//PD4  OK
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��GPIOD4
	 
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;//PE2  KEY0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE2
  
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;//PE3  KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE3
} 

//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//����ֵ��
//0��û���κΰ������� 
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>WK_UP!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//�������ɿ���־  ֻ�е�һ�γ�ʼ��ʱ��ֵ
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEYUP==0||KEYDOWN==0||KEYLEFT==0||KEYRIGHT==0||KEYOK==0))
	{
		delay_ms(10);//ȥ���� 
		key_up=0; 
		if(KEYUP==1)return KEYUP_PRES; 
		else if(KEYDOWN==1)return KEYDOWN_PRES;
		else if(KEYLEFT==1)return KEYLEFT_PRES;
		else if(KEYRIGHT==1)return KEYRIGHT_PRES;
		else if(KEYOK==1)return KEYOK_PRES;  
	}else if(KEYUP==1&&KEYDOWN==1&&KEYLEFT==1&&KEYRIGHT==1&&KEYOK==1)key_up=1; 	     
	return 0;// �ް�������
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
	return 0;// �ް�������
}

