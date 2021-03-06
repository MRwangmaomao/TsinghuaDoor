/**
* Copyright (c), 2015-2025
* @file gui_widget_image.c
* @brief 图片控件主文件
* @author jdh
* @date 2015/9/8
*/

/*********************************************************************
*							头文件
**********************************************************************/

#include "gui_widget_image.h"
#include "gui_2d_lib.h"
#include "stdlib.h"
#include "string.h"

/*********************************************************************
*							静态函数
**********************************************************************/

/**
* @brief 控件显示
* @param handle:控件句柄
*/

static void show(Widget_Image_Handle handle);

/*********************************************************************
*							函数
**********************************************************************/

/**
* @brief 创建控件text
* @param x:左上角x坐标
* @param y:左上角y坐标
* @param xsize:水平尺寸
* @param ysize:垂直尺寸
*/

Widget_Image_Handle gui_widget_image_create(uint16_t x,uint16_t y,uint16_t xsize,uint16_t ysize)
{
	Widget_Image_Handle handle;
	
	//控件初始化
	handle = malloc(sizeof(*handle));
	handle->x = x;
	handle->y = y;
	handle->xsize = xsize;
	handle->ysize = ysize;
	
	return handle;
}

/**
* @brief 设置图片
* @param addr:图片地址
*/

void gui_widget_image_set_bmp(Widget_Image_Handle handle,const uint8_t *addr)
{
	handle->addr = addr;
	
	//显示
	show(handle);
}

/**
* @brief 控件显示
* @param handle:控件句柄
*/

static void show(Widget_Image_Handle handle)
{
	//清除区域
	gui_fill_rect(handle->x,handle->y,handle->x + handle->xsize,handle->y + handle->ysize,0);
	//显示
	gui_draw_bitmap(handle->x,handle->y,handle->addr);
}


