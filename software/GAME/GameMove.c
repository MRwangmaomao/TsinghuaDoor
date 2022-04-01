#include "GameMove.h"
#include "OLED.h" 
#include "key.h"

 extern	u8 OLED_GRAM[128][8];	   		//��ʾ����
 extern u8 OLED_GRAM_Map[128][64];	//����ƶ�����

 Gamemove_t Gamemove;
 
 
 	int x1=0; //Ŀ������x
	int x2=0;	//ǰһ����x
	int y1=0;	//Ŀ������y
	int y2=0;	//ǰһ����y
	

void move2(int dir)
{
	 if(x1==0) x2=0;
	 if(y1==0) y2=0;
	 if(x1>127) x1=0;
	 if(y1>63)  y1=0;
	
	
//		if(OLED_GRAM_Map[x1][y1]==0)
//		{
//			Gamemove.state = 0;
//		}
//		if(OLED_GRAM_Map[x1][y1]==1)
//		{
//			Gamemove.state = 1;
//		}
//	  if(OLED_GRAM_Map[x1][y1]==2) //����
//		{
//			Gamemove.state = 2;
//		}
//		if(OLED_GRAM_Map[x1][y1]==3) //����
//		{
//			Gamemove.state = 3;
//		}
//		if(OLED_GRAM_Map[x1][y1]==4) //�Ҵ���
//		{
//			Gamemove.state = 4;
//		}
//		if(OLED_GRAM_Map[x1][y1]==5) //�ؿ�����
//		{
//			Gamemove.state = 5;
//		}
//		if(OLED_GRAM_Map[x1][y1]==6) //�ؿ��Ҵ���
//		{
//			Gamemove.state = 6;
//		}
		
		
	if(dir==KEYRIGHT_PRES)
	{	
			
			//�ж�ǰһ���ǲ��ǵ�ͼ
			if(OLED_GRAM_Map[x1+1][y1]!=1)
		{
			x2=x1;	//������һ��λ��
			y2=y1;	//������һ��λ��
			x1++;
		  OLED_DrawPoint(x1,y1,1,0);	//����һ���ƶ�
				if(OLED_GRAM_Map[x2][y2]!=1)	//�ж�ǰһ���ǲ��ǵ�ͼ�������ǣ�����ǰһ���ƶ�
				{
				OLED_DrawPoint(x2,y2,0,0);	
				}
		}
		OLED_Refresh_Gram();
	}
	
	if(dir==KEYDOWN_PRES)
	{
		
			//�ж�ǰһ���ǲ��ǵ�ͼ
			if(OLED_GRAM_Map[x1][y1-1]!=1)
		{
			x2=x1;	//������һ��λ��
			y2=y1;	//������һ��λ��
			y1--;
		  OLED_DrawPoint(x1,y1,1,0);	//����һ���ƶ�
			Gamemove.state = 0;					//λ��״̬����Ϊ0������
				if(OLED_GRAM_Map[x2][y2]!=1)	//�ж�ǰһ���ǲ��ǵ�ͼ�������ǣ�����ǰһ���ƶ�
				{
				OLED_DrawPoint(x2,y2,0,0);	
				}
		}
		OLED_Refresh_Gram();
	}
	
	
	if(dir==KEYLEFT_PRES)
	{
			//�ж�ǰһ���ǲ��ǵ�ͼ
			if(OLED_GRAM_Map[x1-1][y1]!=1)
		{
			x2=x1;	//������һ��λ��
			y2=y1;	//������һ��λ��
			x1--;
		  OLED_DrawPoint(x1,y1,1,0);	//����һ���ƶ�
			Gamemove.state = 0;					//λ��״̬����Ϊ0������
				if(OLED_GRAM_Map[x2][y2]!=1)	//�ж�ǰһ���ǲ��ǵ�ͼ�������ǣ�����ǰһ���ƶ�
				{
				OLED_DrawPoint(x2,y2,0,0);	
				}
		}
		OLED_Refresh_Gram();
	}
	
	if(dir==KEYUP_PRES)
	{
		//�ж�ǰһ���ǲ��ǵ�ͼ
			if(OLED_GRAM_Map[x1][y1+1]!=1)
		{
			x2=x1;	//������һ��λ��
			y2=y1;	//������һ��λ��
			y1++;
		  OLED_DrawPoint(x1,y1,1,1);	//����һ���ƶ�
			Gamemove.state = 0;					//λ��״̬����Ϊ0������
				if(OLED_GRAM_Map[x2][y2]!=1)	//�ж�ǰһ���ǲ��ǵ�ͼ�������ǣ�����ǰһ���ƶ�
				{
				OLED_DrawPoint(x2,y2,0,0);	
				}
		}
		OLED_Refresh_Gram();
	}
	
	if(dir==0)
	{
	}
	
	move_coordinate_update();
}
//�����ƶ�������Ϣ
void move_coordinate_update(void)
{
	Gamemove.x = x1;
	Gamemove.y = y1;
}

void Set_Start_Point(int x,int y)
{
	x1=x;
	y1=y;
}

void check_State(void)
{
		if(OLED_GRAM_Map[x1][y1]==0)
		{
			Gamemove.state = 0;
		}
		if(OLED_GRAM_Map[x1][y1]==1)
		{
			Gamemove.state = 1;
		}
	  if(OLED_GRAM_Map[x1][y1]==2) //����
		{
			Gamemove.state = 2;
		}
		if(OLED_GRAM_Map[x1][y1]==3) //����
		{
			Gamemove.state = 3;
		}
		if(OLED_GRAM_Map[x1][y1]==4) //�Ҵ���
		{
			Gamemove.state = 4;
		}
		if(OLED_GRAM_Map[x1][y1]==5) //�ؿ�����
		{
			Gamemove.state = 5;
		}
		if(OLED_GRAM_Map[x1][y1]==6) //�ؿ��Ҵ���
		{
			Gamemove.state = 6;
		}
}
