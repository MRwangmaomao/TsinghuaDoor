#include "OLED.h" 
#include "GameMove.h"
#include "Game_flow.h"
#include "GameMap.h"

extern  Gamemove_t Gamemove;
extern  Game_state_t Game_state;
//����������֭bug
u8 key;
u32 tick_ms=0;

void Game_State_Init(void)
{
	Gamemove.dead=0; 			 		//�ȳ�ʼ��Ϊ0�����״̬
	Game_state.page=0;				//��һҳ
	Game_state.start_flag=0;	//һ��ʼflag����0
	Game_state.transt_flag=0;
	//�ţ���������
	//�ţ���OK������Ϸ
	
	
}
/*
int a=0;
int b=0;
int c=o
switch(Gamemove.dead)
	case 0:
	{
		if(key==OK&&page==0)
			{	a++;
						if(a==1)
							{
					//����Ļ
							}
					// OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//��è�˺���
						delay_ms(10);
					if(key==OK)
							{
								page=1
							}	
			}
		if(key==OK&&page==1)
			{
			b++;
			if(b==1)
			{
				//����Ļ
			}
				//OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP2);//��è�˺���
				delay_ms(10);
							if(key==OK)
							{
								page=3
							}	
			}
		if(key==OK&&page==2)	
		{
		Game_state.start_flag=1;
		}
		if(Game_state.start_flag==1)
		{
		Show_GameFrame();
		Set_Start_Point(64,5);
		move2(key);
		}
		
	}




*/
