#include "GameMap.h"
#include "OLED.h"

extern u8 OLED_GRAM_Map[128][64];	//存放移动数组
void Show_GameFrame(void)
{
 Map_data_Init(); //地图属性数组初始化，全部赋值0
	
//左边游戏区域框架
//障碍物
 OLED_DrawSquare(3,38,59,63,1,1);   
 OLED_DawaLine(12,40,12,54,1,1);
 OLED_DawaLine(22,45,22,62,1,1);
 OLED_DawaLine(32,40,32,50,1,1);
 OLED_DawaLine(32,56,58,56,1,1);
 OLED_DawaLine(45,45,45,56,1,1);
 OLED_DawaLine(50,47,58,47,1,1);
 OLED_DrawPoint(50,18,1,1);
	
//右边游戏区域框架
//障碍物
//地图数组存储：0为地图障碍物 1为正常行走 2为陷阱
 OLED_DrawSquare(69,38,125,63,1,1);	 //右边作战区域框架
 OLED_DawaLine(69,46,79,46,1,1);
 OLED_DawaLine(79,40,79,46,1,1);
 OLED_DawaLine(69,56,79,56,1,1);
 OLED_DawaLine(79,56,79,62,1,1);
 OLED_DrawSquare(82,50,86,52,1,1);
 OLED_DawaLine(90,42,90,62,1,1);
 OLED_DrawSquare(100,38,107,53,1,1);
 OLED_DawaLine(113,55,124,55,1,1);
 OLED_DrawPoint(72,18,1,1);

//下方出生区域框架
//障碍物
 OLED_DrawSquare(44,1,84,24,1,1);	 
 //传送区域
 OLED_DrawSquare(49,15,57,21,1,3);//左
 OLED_DrawSquare(71,15,79,21,1,4);//右
 
 //左关卡完成点
 OLED_DrawPoint(52,50,1,5); 
 OLED_DrawPoint(52,51,1,5);
 OLED_DrawPoint(53,50,1,5);
 OLED_DrawPoint(53,51,1,5);
 
 //右关卡完成点
 OLED_DrawPoint(120,44,1,6);
 OLED_DrawPoint(121,44,1,6);
 OLED_DrawPoint(120,45,1,6);
 OLED_DrawPoint(121,45,1,6);
 
 OLED_Refresh_Gram();//更新显示
}

void show_stage_left(void)
{
 OLED_DrawSquare(37,38,93,63,1,1);   
 OLED_DawaLine(46,40,46,54,1,1);
 OLED_DawaLine(22+34,45,22+34,62,1,1);
 OLED_DawaLine(32+34,40,32+34,50,1,1);
 OLED_DawaLine(32+34,56,58+34,56,1,1);
 OLED_DawaLine(45+34,45,45+34,56,1,1);
 OLED_DawaLine(50+34,47,58+34,47,1,1);
 OLED_Refresh_Gram();
}

void show_stage_right(void)
{
 OLED_DrawSquare(69-31,38,125-31,63,1,1);	 //右边作战区域框架
 OLED_DawaLine(69-31,46,79-31,46,1,1);
 OLED_DawaLine(79-31,40,79-31,46,1,1);
 OLED_DawaLine(69-31,56,79-31,56,1,1);
 OLED_DawaLine(79-31,56,79-31,62,1,1);
 OLED_DrawSquare(82-31,50,86-31,52,1,1);
 OLED_DawaLine(90-31,42,90-31,62,1,1);
 OLED_DrawSquare(100-31,38,107-31,53,1,1);
 OLED_DawaLine(113-31,55,124-31,55,1,1);
	OLED_Refresh_Gram();

}

void confirm(void)
{
OLED_GRAM_Map[120][44]=6;
OLED_GRAM_Map[121][44]=6;
OLED_GRAM_Map[120][45]=6;
OLED_GRAM_Map[121][45]=6;

}

//Laser trap
void OLED_DrawTrap1(void)
{
 OLED_DawaLine(95,40,95,62,1,2);
 OLED_Refresh_Gram();//更新显示

}

void OLED_EraseTrap1(void)
{
 OLED_DawaLine(95,40,95,62,0,0); 
 OLED_Refresh_Gram();//更新显示
	
}

void OLED_DrawTrap2(void)
{
 OLED_DawaLine(110,40,110,62,1,2);
 OLED_Refresh_Gram();//更新显示
}

void OLED_EraseTrap2(void)
{
 OLED_DawaLine(110,40,110,62,0,0);
 OLED_Refresh_Gram();//更新显示
}

void OLED_DrawTrap3(void)
{
 OLED_DawaLine(113,48,124,48,1,2);
	 OLED_Refresh_Gram();//更新显示
}
void OLED_EraseTrap3(void)
{
 OLED_DawaLine(113,48,124,48,0,0);
 OLED_Refresh_Gram();//更新显示
}
