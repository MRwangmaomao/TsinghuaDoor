/**
* Copyright (c), 2015-2025
* @file gui.h
* @brief gui头文件
* @author jdh
* @version 1.0
* @date 2015/9/6
*/

#ifndef _GUI_H_
#define _GUI_H_

/*********************************************************************
*							头文件
**********************************************************************/

#include "gui_interface.h"
#include "gui_text_lib.h"
#include "gui_2d_lib.h"
#include "gui_widget_text.h"
#include "gui_widget_image.h"
#include "gui_widget_progbar.h"

/*********************************************************************
*							函数
**********************************************************************/



/**
* @brief 初始化gui
*/

void gui_init(void);

/**
* @brief 销毁控件
* @param handle:控件句柄
*/

void gui_widget_delete(void *handle);

#endif


