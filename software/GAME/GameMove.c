#include "GameMove.h"
#include "OLED.h" 
#include "key.h"

 extern	u8 OLED_GRAM[128][8];	   		//显示数组
 extern u8 OLED_GRAM_Map[128][64];	//存放移动数组

 Gamemove_t Gamemove;
 
 
 	int x1=0; //目标坐标x
	int x2=0;	//前一坐标x
	int y1=0;	//目标坐标y
	int y2=0;	//前一坐标y
	

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
//	  if(OLED_GRAM_Map[x1][y1]==2) //陷阱
//		{
//			Gamemove.state = 2;
//		}
//		if(OLED_GRAM_Map[x1][y1]==3) //左传送
//		{
//			Gamemove.state = 3;
//		}
//		if(OLED_GRAM_Map[x1][y1]==4) //右传送
//		{
//			Gamemove.state = 4;
//		}
//		if(OLED_GRAM_Map[x1][y1]==5) //关卡左传送
//		{
//			Gamemove.state = 5;
//		}
//		if(OLED_GRAM_Map[x1][y1]==6) //关卡右传送
//		{
//			Gamemove.state = 6;
//		}
		
		
	if(dir==KEYRIGHT_PRES)
	{	
			
			//判断前一步是不是地图
			if(OLED_GRAM_Map[x1+1][y1]!=1)
		{
			x2=x1;	//保存上一步位置
			y2=y1;	//保存上一步位置
			x1++;
		  OLED_DrawPoint(x1,y1,1,0);	//画下一步移动
				if(OLED_GRAM_Map[x2][y2]!=1)	//判断前一步是不是地图，若不是，消除前一步移动
				{
				OLED_DrawPoint(x2,y2,0,0);	
				}
		}
		OLED_Refresh_Gram();
	}
	
	if(dir==KEYDOWN_PRES)
	{
		
			//判断前一步是不是地图
			if(OLED_GRAM_Map[x1][y1-1]!=1)
		{
			x2=x1;	//保存上一步位置
			y2=y1;	//保存上一步位置
			y1--;
		  OLED_DrawPoint(x1,y1,1,0);	//画下一步移动
			Gamemove.state = 0;					//位置状态属性为0，正常
				if(OLED_GRAM_Map[x2][y2]!=1)	//判断前一步是不是地图，若不是，消除前一步移动
				{
				OLED_DrawPoint(x2,y2,0,0);	
				}
		}
		OLED_Refresh_Gram();
	}
	
	
	if(dir==KEYLEFT_PRES)
	{
			//判断前一步是不是地图
			if(OLED_GRAM_Map[x1-1][y1]!=1)
		{
			x2=x1;	//保存上一步位置
			y2=y1;	//保存上一步位置
			x1--;
		  OLED_DrawPoint(x1,y1,1,0);	//画下一步移动
			Gamemove.state = 0;					//位置状态属性为0，正常
				if(OLED_GRAM_Map[x2][y2]!=1)	//判断前一步是不是地图，若不是，消除前一步移动
				{
				OLED_DrawPoint(x2,y2,0,0);	
				}
		}
		OLED_Refresh_Gram();
	}
	
	if(dir==KEYUP_PRES)
	{
		//判断前一步是不是地图
			if(OLED_GRAM_Map[x1][y1+1]!=1)
		{
			x2=x1;	//保存上一步位置
			y2=y1;	//保存上一步位置
			y1++;
		  OLED_DrawPoint(x1,y1,1,1);	//画下一步移动
			Gamemove.state = 0;					//位置状态属性为0，正常
				if(OLED_GRAM_Map[x2][y2]!=1)	//判断前一步是不是地图，若不是，消除前一步移动
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
//更新移动坐标信息
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
	  if(OLED_GRAM_Map[x1][y1]==2) //陷阱
		{
			Gamemove.state = 2;
		}
		if(OLED_GRAM_Map[x1][y1]==3) //左传送
		{
			Gamemove.state = 3;
		}
		if(OLED_GRAM_Map[x1][y1]==4) //右传送
		{
			Gamemove.state = 4;
		}
		if(OLED_GRAM_Map[x1][y1]==5) //关卡左传送
		{
			Gamemove.state = 5;
		}
		if(OLED_GRAM_Map[x1][y1]==6) //关卡右传送
		{
			Gamemove.state = 6;
		}
}
