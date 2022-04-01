/**
* Copyright (c), 2015-2025
* @file gui_interface.c
* @brief gui接口主文件
* @author jdh
* @date 2015/9/6
*/

/*********************************************************************
*							头文件
**********************************************************************/

#include "gui_interface.h"

/*********************************************************************
*							函数
**********************************************************************/

/**
* @brief 画点
* @param x:x坐标
* @param y:y坐标
* @param show:0:不显示,1:显示
*/

void gui_interface_draw_pixel(uint8_t x,uint8_t y,uint8_t show)
{
	if (x >= LCD_WIDTH || y >= LCD_HEIGHT)
	{
		return;
	}
	
	inf_lcd_draw_pixel(x,y,show);
}

