/**
* Copyright (c), 2015-2025
* @file gui_2d_lib.c
* @brief 2d图形库主文件
* @author jdh
* @date 2015/9/6
* @update 2015/9/7
* @update 2015/11/22
*/

/*********************************************************************
*							头文件
**********************************************************************/

#include "gui_2d_lib.h"
#include "string.h"

/*********************************************************************
*							数据结构
**********************************************************************/

#pragma pack(1)

/**
* @brief 文件头
*/

struct _Bmp_File_Header
{
	//文件标志
	uint16_t type;
	//文件大小
	uint32_t size;
	//保留
	uint16_t reserved1;
	//保留
	uint16_t reserved2;
	//位图偏移量
	uint32_t offbits;
};

/**
* @bri信息头
*/

struct _Bmp_Info_Header
{
	//信息头大小
	uint32_t size;
	//位图宽度
	uint32_t width;
	//位图高度
	uint32_t height;
	//位图的位面数
	uint16_t planes;
	//每个像素点所需的数据位数（24）
	uint16_t offbits;
	//压缩算法
	uint32_t compression;
	//位图数据字节数
	uint32_t size_image;
	//以像素/米的单位表示水平分辨率
	uint32_t xpe_is_per_meter;
	//以像素/米的单位表示垂直分辨率
	uint32_t ype_is_per_meter;
	//位图使用的颜色数
	uint32_t color_used;
	//指定重要颜色数
	uint32_t color_important;
};

#pragma pack()

/*********************************************************************
*							函数
**********************************************************************/

/**
* @brief 绘制水平线条
* @param y:y位置
* @param x0:x起始位置
* @param x1:x结束位置
*/

void gui_draw_hline(uint16_t y,uint16_t x0,uint16_t x1)
{
	uint16_t x = 0;
	
	for (x = x0;x <= x1;x++)
	{
		gui_interface_draw_pixel(x,y,1);
	}
}

/**
* @brief 绘制垂直线条
* @param x:x位置
* @param y0:y起始位置
* @param y1:y结束位置
*/

void gui_draw_vline(uint16_t x,uint16_t y0,uint16_t y1)
{
	uint16_t y = 0;
	
	for (y = y0;y <= y1;y++)
	{
		gui_interface_draw_pixel(x,y,1);
	}
}

/**
* @brief 绘制线条
* @param x0:x起始位置
* @param y0:y起始位置
* @param x1:x结束位置
* @param y2:y结束位置
*/

void gui_draw_line(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1)
{
	float a = 0;
	float b = 0;
	float xx0 = x0;
	float yy0 = y0;
	float xx1 = x1;
	float yy1 = y1;
	uint16_t x = 0;
	uint16_t y = 0;
	
	a = (yy0 - yy1) / (xx0 - xx1);
	b = yy0 - (yy0 - yy1) * x0 / (x0 - x1);
	
	for (x = x0;x <= x1 - x0;x++)
	{
		y = a * x + b;
		gui_interface_draw_pixel(x,y,1);
	}
}

/**
* @brief 绘制矩形
* @param x0:左上角x坐标
* @param y0:左上角y坐标
* @param x1:右上角x坐标
* @param y2:右上角y坐标
*/

void gui_draw_rect(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1)
{
	gui_draw_hline(y0,x0,x1);
	gui_draw_hline(y1,x0,x1);
	gui_draw_vline(x0,y0,y1);
	gui_draw_vline(x1,y0,y1);
}

/**
* @brief 填充矩形
* @param x0:左上角x坐标
* @param y0:左上角y坐标
* @param x1:右上角x坐标
* @param y2:右上角y坐标
* @param show:0:不显示,1:显示
*/

void gui_fill_rect(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint8_t show)
{
	uint16_t i = 0;
	uint16_t j = 0;
	
	for (i = x0;i <= x1;i++)
	{
		for (j = y0;j <= y1;j++)
		{
			gui_interface_draw_pixel(i,j,show);
		}	
	}	
}
/**
* @brief 在指定位置显示图片
* @param x:x坐标
* @param y:y坐标
* @param bmp:图片
*/

void gui_draw_bitmap(uint16_t x,uint16_t y,const uint8_t *bmp)
{
	struct _Bmp_File_Header bmp_file_header;
	struct _Bmp_Info_Header bmp_info_header;
	uint8_t *buf_pt = 0;
	uint16_t i = 0;
	uint16_t j = 0;
	uint8_t bit = 0;
	uint8_t index_bit = 0;
	uint16_t row = 0;
	uint16_t column = 0;
	uint16_t num_bit_invalid = 0;
	
	//读取文件头
	memcpy(&bmp_file_header,bmp,sizeof(struct _Bmp_File_Header));
	//读取信息头
	memcpy(&bmp_info_header,bmp + sizeof(struct _Bmp_File_Header),sizeof(struct _Bmp_Info_Header));
	//图片数据
	buf_pt = (uint8_t *)bmp + bmp_file_header.offbits;
	//4字节对齐导致的无效位数
	num_bit_invalid = 32 - (bmp_info_header.width % 32);
	
	//显示图片
	for (i = 0;i < bmp_info_header.width * bmp_info_header.height;i++)
	{
		bit = (*buf_pt >> (7 - index_bit)) & 0x1;
		inf_lcd_draw_pixel(x + column,y + bmp_info_header.height -1 - row,bit);
		
		index_bit++;
		if (index_bit >= 8)
		{
			index_bit = 0;
			buf_pt++;
		}
		
		column++;
		if (column >= bmp_info_header.width)
		{
			column = 0;
			row++;
			
			//补齐
			for (j = 0;j < num_bit_invalid;j++)
			{
				index_bit++;
				if (index_bit >= 8)
				{
					index_bit = 0;
					buf_pt++;
				}
			}
		}
	}
}

