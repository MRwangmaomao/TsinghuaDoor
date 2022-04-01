/**
* Copyright (c), 2015-2025
* @file gui_2d_lib.c
* @brief 2d图形库主文件
* @author jdh
* @date 2015/9/6
* @update 2015/9/7
* @update 2015/11/22
*/

#ifndef _GUI_2D_LIB_H_
#define _GUI_2D_LIB_H_

/*********************************************************************
*							头文件
**********************************************************************/

#include "gui_interface.h"

/*********************************************************************
*							函数
**********************************************************************/

/**
* @brief 绘制水平线条
* @param y:y位置
* @param x0:x起始位置
* @param x1:x结束位置
*/

void gui_draw_hline(uint16_t y,uint16_t x0,uint16_t x1);

/**
* @brief 绘制垂直线条
* @param x:x位置
* @param y0:y起始位置
* @param y1:y结束位置
*/

void gui_draw_vline(uint16_t x,uint16_t y0,uint16_t y1);

/**
* @brief 绘制线条
* @param x0:x起始位置
* @param y0:y起始位置
* @param x1:x结束位置
* @param y2:y结束位置
*/

void gui_draw_line(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1);

/**
* @brief 绘制矩形
* @param x0:左上角x坐标
* @param y0:左上角y坐标
* @param x1:右上角x坐标
* @param y2:右上角y坐标
*/

void gui_draw_rect(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1);

/**
* @brief 填充矩形
* @param x0:左上角x坐标
* @param y0:左上角y坐标
* @param x1:右上角x坐标
* @param y2:右上角y坐标
* @param show:0:不显示,1:显示
*/

void gui_fill_rect(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint8_t show);

/**
* @brief 在指定位置显示图片
* @param x:x坐标
* @param y:y坐标
* @param bmp:图片
*/

void gui_draw_bitmap(uint16_t x,uint16_t y,const uint8_t *bmp);

#endif


