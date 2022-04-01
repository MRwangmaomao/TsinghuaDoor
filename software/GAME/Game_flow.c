#include "OLED.h" 
#include "GameMove.h"
#include "Game_flow.h"
#include "GameMap.h"

extern  Gamemove_t Gamemove;
extern  Game_state_t Game_state;
//被抛弃，蜜汁bug
u8 key;
u32 tick_ms=0;

void Game_State_Init(void)
{
	Gamemove.dead=0; 			 		//先初始化为0，存活状态
	Game_state.page=0;				//第一页
	Game_state.start_flag=0;	//一开始flag给到0
	Game_state.transt_flag=0;
	//放：开场画面
	//放：按OK进入游戏
	
	
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
					//清屏幕
							}
					// OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//熊猫人合掌
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
				//清屏幕
			}
				//OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP2);//熊猫人合掌
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
