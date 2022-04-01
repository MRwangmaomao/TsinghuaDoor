/**
* Copyright (c), 2015-2025
* @file gui_widget_text.c
* @brief 文本控件主文件
* @author jdh
* @date 2015/9/8
*/

/*********************************************************************
*							头文件
**********************************************************************/

#include "gui_widget_text.h"
#include "gui_2d_lib.h"
#include "gui_text_lib.h"
#include "stdlib.h"
#include "string.h"

/*********************************************************************
*							静态函数
**********************************************************************/

/**
* @brief 控件显示
* @param handle:控件句柄
*/

static void show(Widget_Text_Handle handle);

/*********************************************************************
*							函数
**********************************************************************/

/**
* @brief 创建控件text
* @param x:左上角x坐标
* @param y:左上角y坐标
* @param xsize:水平尺寸
* @param ysize:垂直尺寸
* @param font:字体
* @param s:文本
* @retval 控件句柄
*/

Widget_Text_Handle gui_widget_text_create(uint16_t x,uint16_t y,uint16_t xsize,uint16_t ysize,uint8_t font,char *s)
{
	Widget_Text_Handle handle;
	
	//控件初始化
	handle = malloc(sizeof(*handle));
	handle->x = x;
	handle->y = y;
	handle->xsize = xsize;
	handle->ysize = ysize;
	handle->font = font;
	strcpy(handle->s,s);
	
	//显示
	show(handle);
	
	return handle;
}

/**
* @brief 设置文本
* @param s:文本
*/

void gui_widget_text_set_text(Widget_Text_Handle handle,uint8_t font,char *s)
{
	handle->font = font;
	strcpy(handle->s,s);
	
	//显示
	show(handle);
}

/**
* @brief 控件显示
* @param handle:控件句柄
*/

static void show(Widget_Text_Handle handle)
{
	//清除区域
	gui_fill_rect(handle->x,handle->y,handle->x + handle->xsize,handle->y + handle->ysize,0);
	//显示
	gui_disp_string_at(handle->x,handle->y,handle->font,handle->s);
}
