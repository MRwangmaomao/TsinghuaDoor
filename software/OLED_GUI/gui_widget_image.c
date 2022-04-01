/**
* Copyright (c), 2015-2025
* @file gui_widget_image.c
* @brief Í¼Æ¬¿Ø¼şÖ÷ÎÄ¼ş
* @author jdh
* @date 2015/9/8
*/

/*********************************************************************
*							Í·ÎÄ¼ş
**********************************************************************/

#include "gui_widget_image.h"
#include "gui_2d_lib.h"
#include "stdlib.h"
#include "string.h"

/*********************************************************************
*							¾²Ì¬º¯Êı
**********************************************************************/

/**
* @brief ¿Ø¼şÏÔÊ¾
* @param handle:¿Ø¼ş¾ä±ú
*/

static void show(Widget_Image_Handle handle);

/*********************************************************************
*							º¯Êı
**********************************************************************/

/**
* @brief ´´½¨¿Ø¼ştext
* @param x:×óÉÏ½Çx×ø±ê
* @param y:×óÉÏ½Çy×ø±ê
* @param xsize:Ë®Æ½³ß´ç
* @param ysize:´¹Ö±³ß´ç
*/

Widget_Image_Handle gui_widget_image_create(uint16_t x,uint16_t y,uint16_t xsize,uint16_t ysize)
{
	Widget_Image_Handle handle;
	
	//¿Ø¼ş³õÊ¼»¯
	handle = malloc(sizeof(*handle));
	handle->x = x;
	handle->y = y;
	handle->xsize = xsize;
	handle->ysize = ysize;
	
	return handle;
}

/**
* @brief ÉèÖÃÍ¼Æ¬
* @param addr:Í¼Æ¬µØÖ·
*/

void gui_widget_image_set_bmp(Widget_Image_Handle handle,const uint8_t *addr)
{
	handle->addr = addr;
	
	//ÏÔÊ¾
	show(handle);
}

/**
* @brief ¿Ø¼şÏÔÊ¾
* @param handle:¿Ø¼ş¾ä±ú
*/

static void show(Widget_Image_Handle handle)
{
	//Çå³ıÇøÓò
	gui_fill_rect(handle->x,handle->y,handle->x + handle->xsize,handle->y + handle->ysize,0);
	//ÏÔÊ¾
	gui_draw_bitmap(handle->x,handle->y,handle->addr);
}


