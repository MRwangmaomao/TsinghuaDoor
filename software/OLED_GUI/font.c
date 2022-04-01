/**
* Copyright (c), 2015-2025
* @file font.c
* @brief 字库文件主文件
* @author jdh
* @date 2015/9/6
* @date 2015/9/7
*/

/*********************************************************************
*							头文件
**********************************************************************/

#include "font.h"
#include "string.h"

/**
* @brief 得到字体高度
* @param font:字体
* @retval 高度
*/

extern uint8_t GB18030_17X17_get_height(void);

/**
* @brief 得到地址
* @param font:字体
* @param ch:待读取的字符
* @param addr:数据存储地址
* @retval 读取结果.0:失败,1:成功
*/

extern uint8_t GB18030_17X17_get_address(uint16_t ch,struct _Font_Type *font_type,uint32_t *addr);

/**
* @brief 得到字体高度
* @param font:字体
* @retval 高度
*/

extern uint8_t GB18030_20X20_get_height(void);

/**
* @brief 得到地址
* @param font:字体
* @param ch:待读取的字符
* @param addr:数据存储地址
* @retval 读取结果.0:失败,1:成功
*/

extern uint8_t GB18030_20X20_get_address(uint16_t ch,struct _Font_Type *font_type,uint32_t *addr);

/**
* @brief 得到字体高度
* @param font:字体
* @retval 高度
*/

extern uint8_t GB18030_24X24_get_height(void);
	
/**
* @brief 得到地址
* @param font:字体
* @param ch:待读取的字符
* @param addr:数据存储地址
* @retval 读取结果.0:失败,1:成功
*/

extern uint8_t GB18030_24X24_get_address(uint16_t ch,struct _Font_Type *font_type,uint32_t *addr);

/**
* @brief 得到字体高度
* @param font:字体
* @retval 高度
*/

extern uint8_t GB18030_30X30_get_height(void);
	
/**
* @brief 得到地址
* @param font:字体
* @param ch:待读取的字符
* @param addr:数据存储地址
* @retval 读取结果.0:失败,1:成功
*/

extern uint8_t GB18030_30X30_get_address(uint16_t ch,struct _Font_Type *font_type,uint32_t *addr);

/**
* @brief 得到字体高度
* @param font:字体
* @retval 高度
*/

uint8_t GB18030_37X37B_get_height(void);

/**
* @brief 得到地址
* @param font:字体
* @param ch:待读取的字符
* @param addr:数据存储地址
* @retval 读取结果.0:失败,1:成功
*/

uint8_t GB18030_37X37B_get_address(uint16_t ch,struct _Font_Type *font_type,uint32_t *addr);

/**
* @brief 得到字体高度
* @param font:字体
* @retval 高度
*/

uint8_t GB18030_40X40B_get_height(void);

/**
* @brief 得到地址
* @param font:字体
* @param ch:待读取的字符
* @param addr:数据存储地址
* @retval 读取结果.0:失败,1:成功
*/

uint8_t GB18030_40X40B_get_address(uint16_t ch,struct _Font_Type *font_type,uint32_t *addr);

/**
* @brief 得到字体高度
* @param font:字体
* @retval 高度
*/

uint8_t GB18030_48X48_get_height(void);

/**
* @brief 得到地址
* @param font:字体
* @param ch:待读取的字符
* @param addr:数据存储地址
* @retval 读取结果.0:失败,1:成功
*/

uint8_t GB18030_48X48_get_address(uint16_t ch,struct _Font_Type *font_type,uint32_t *addr);

/*********************************************************************
*							静态变量
**********************************************************************/

///**
//* @brief 字体结构
//*/

//static struct _Font_Type Font_Type[FONT_NUM + 1];

///*********************************************************************
//*							静态函数
//**********************************************************************/

///**
//* @brief 初始化字体类型
//*/

//static void init_font_type(void);

/*********************************************************************
*							函数
**********************************************************************/

/**
* @brief 得到字体高度
* @param font:字体
* @retval 高度
*/

uint8_t font_get_height(uint8_t font)
{
	switch (font)
	{
		case GB18030_17X17:
		{
			return GB18030_17X17_get_height();
		}
		case GB18030_20X20:
		{
			return GB18030_20X20_get_height();
		}
		case GB18030_24X24:
		{
			return GB18030_24X24_get_height();
		}
		case GB18030_30X30:
		{
			return GB18030_30X30_get_height();
		}
		case GB18030_37X37B:
		{
			return GB18030_37X37B_get_height();
		}
		case GB18030_40X40B:
		{
			return GB18030_40X40B_get_height();
		}
		case GB18030_48X48:
		{
			return GB18030_48X48_get_height();
		}
		default:
		{
			return 0;
		}
	}
}

/**
* @brief 读取字库
* @param font:字体
* @param c:待读取的字符
* @param font_type:返回的字体信息
* @param addr:数据存储地址
* @retval 读取结果.0:失败,1:成功
*/

uint8_t font_read(uint8_t font,uint16_t c,struct _Font_Type *font_type,uint32_t *addr)
{	
	switch (font)
	{
		case GB18030_17X17:
		{
			if (GB18030_17X17_get_address(c,font_type,addr))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		case GB18030_20X20:
		{
			if (GB18030_20X20_get_address(c,font_type,addr))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		case GB18030_24X24:
		{
			if (GB18030_24X24_get_address(c,font_type,addr))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		case GB18030_30X30:
		{
			if (GB18030_30X30_get_address(c,font_type,addr))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		case GB18030_37X37B:
		{
			if (GB18030_37X37B_get_address(c,font_type,addr))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		case GB18030_40X40B:
		{
			if (GB18030_40X40B_get_address(c,font_type,addr))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		case GB18030_48X48:
		{
			if (GB18030_48X48_get_address(c,font_type,addr))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		default:
		{
			return 0;
		}
	}
}


