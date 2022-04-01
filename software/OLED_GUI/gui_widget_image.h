/**
* Copyright (c), 2015-2025
* @file gui_widget_image.h
* @brief 图片控件头文件
* @author jdh
* @date 2015/9/8
*/

#ifndef _GUI_WIDGET_IMAGE_H_
#define _GUI_WIDGET_IMAGE_H_

/*********************************************************************
*							头文件
**********************************************************************/

#include "gui_interface.h"
 
/*********************************************************************
*							数据结构
**********************************************************************/

/**
* @brief 图片控件数据结构
*/

typedef struct _Widget_Image
{
	//x轴位置
	uint16_t x;
	//y轴位置
	uint16_t y;
	//水平尺寸
	uint16_t xsize;
	//垂直尺寸
	uint16_t ysize;
	//图片地址
	const uint8_t *addr;
}*Widget_Image_Handle;

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

Widget_Image_Handle gui_widget_image_create(uint16_t x,uint16_t y,uint16_t xsize,uint16_t ysize);

/**
* @brief 设置图片
* @param addr:图片地址
*/

void gui_widget_image_set_bmp(Widget_Image_Handle handle,const uint8_t *addr);

#endif


