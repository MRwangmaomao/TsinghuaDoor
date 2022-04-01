/**
* Copyright (c), 2015-2025
* @file gui_text_lib.h
* @brief 文本显示库头文件
* @author jdh
* @date 2015/9/6
*/

#ifndef _GUI_TEXT_LIB_H_
#define _GUI_TEXT_LIB_H_

/*********************************************************************
*							头文件
**********************************************************************/

#include "gui_interface.h"
#include "font.h"

/*********************************************************************
*							函数
**********************************************************************/

/**
* @brief 在指定位置显示单个字符
* @param x:x坐标
* @param y:y坐标
* @param font:字体
* @param c:字符
*/

void gui_disp_char_at(uint16_t x,uint16_t y,uint8_t font,uint16_t c);

/**
* @brief 在指定位置显示字符串
* @param x:x坐标
* @param y:y坐标
* @param font:字体
* @param s:字符
*/

void gui_disp_string_at(uint16_t x,uint16_t y,uint8_t font,char *s);

/**
* @brief 在指定位置显示字符串,并清除本行剩余部分直至行末
* @param x:x坐标
* @param y:y坐标
* @param font:字体
* @param s:字符
*/

void gui_disp_string_at_ceol(uint16_t x,uint16_t y,uint8_t font,char *s);

#endif


