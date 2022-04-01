/**
* Copyright (c), 2015-2025
* @file gui_widget_text.h
* @brief 文本控件头文件
* @author jdh
* @date 2015/9/8
*/

#ifndef _GUI_WIDGET_TEXT_H_
#define _GUI_WIDGET_TEXT_H_

/*********************************************************************
*							头文件
**********************************************************************/

#include "gui_interface.h"

/*********************************************************************
*							宏定义
**********************************************************************/

/**
* @brief 文本长度.单位:字节
*/

#define LEN_WIDGET_TEXT				32

/*********************************************************************
*							数据结构
**********************************************************************/

/**
* @brief 文本框数据结构
*/

typedef struct _Widget_Text
{
	//x轴位置
	uint16_t x;
	//y轴位置
	uint16_t y;
	//水平尺寸
	uint16_t xsize;
	//垂直尺寸
	uint16_t ysize;
	//字体
	uint8_t font;
	//文本
	char s[LEN_WIDGET_TEXT];
}*Widget_Text_Handle;

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

Widget_Text_Handle gui_widget_text_create(uint16_t x,uint16_t y,uint16_t xsize,uint16_t ysize,uint8_t font,char *s);

/**
* @brief 设置文本
* @param s:文本
*/

void gui_widget_text_set_text(Widget_Text_Handle handle,uint8_t font,char *s);

#endif


