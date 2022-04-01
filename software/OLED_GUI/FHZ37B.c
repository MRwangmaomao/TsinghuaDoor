/**
* Copyright (c), 2015-2025
* @file FHz37B.c
* @brief 37号汉字字库,字体微软雅黑粗体
* @author jdh
* @date 2015/11/9
*/

/*********************************************************************
*							头文件
**********************************************************************/

#include "font.h"

/*********************************************************************
*							静态变量
**********************************************************************/

unsigned char Hz37B_0020[ 37] = { /* code 0020, SPACE */
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz37B_002E[ 37] = { /* code 002E, FULL STOP */
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  __XXX___,
  _XXXXX__,
  _XXXXX__,
  _XXXXX__,
  __XXX___,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz37B_0030[111] = { /* code 0030, DIGIT ZERO */
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ______XX,XXXX____,________,
  ____XXXX,XXXXX___,________,
  ___XXXXX,XXXXXX__,________,
  ___XXXX_,__XXXXX_,________,
  __XXXX__,___XXXX_,________,
  __XXXX__,___XXXX_,________,
  _XXXX___,____XXXX,________,
  _XXXX___,____XXXX,________,
  _XXXX___,____XXXX,________,
  _XXXX___,____XXXX,________,
  _XXXX___,____XXXX,________,
  _XXXX___,____XXXX,________,
  _XXXX___,____XXXX,________,
  _XXXX___,____XXXX,________,
  _XXXX___,____XXXX,________,
  __XXXX__,___XXXX_,________,
  __XXXX__,___XXXX_,________,
  __XXXXX_,__XXXX__,________,
  ___XXXXX,XXXXXX__,________,
  ____XXXX,XXXXX___,________,
  _____XXX,XXX_____,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________};

unsigned char Hz37B_0031[111] = { /* code 0031, DIGIT ONE */
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,XXX_____,________,
  ______XX,XXX_____,________,
  ____XXXX,XXX_____,________,
  __XXXXXX,XXX_____,________,
  __XXXXXX,XXX_____,________,
  __XXXX_X,XXX_____,________,
  __XX___X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  _______X,XXX_____,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________};

unsigned char Hz37B_0032[111] = { /* code 0032, DIGIT TWO */
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ____XXXX,XXX_____,________,
  __XXXXXX,XXXX____,________,
  __XXXXXX,XXXXX___,________,
  __XXX___,_XXXXX__,________,
  __X_____,__XXXX__,________,
  ________,__XXXX__,________,
  ________,__XXXX__,________,
  ________,__XXXX__,________,
  ________,_XXXXX__,________,
  ________,XXXXX___,________,
  _______X,XXXXX___,________,
  ______XX,XXXX____,________,
  _____XXX,XXX_____,________,
  ____XXXX,XX______,________,
  ___XXXXX,________,________,
  __XXXXX_,________,________,
  __XXXXX_,________,________,
  _XXXXX__,________,________,
  _XXXXXXX,XXXXXX__,________,
  _XXXXXXX,XXXXXX__,________,
  _XXXXXXX,XXXXXX__,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________};

unsigned char Hz37B_0033[111] = { /* code 0033, DIGIT THREE */
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ____XXXX,XXX_____,________,
  ___XXXXX,XXXX____,________,
  ___XXXXX,XXXXX___,________,
  ___X____,_XXXXX__,________,
  ________,__XXXX__,________,
  ________,__XXXX__,________,
  ________,__XXXX__,________,
  ________,__XXXX__,________,
  ________,XXXXX___,________,
  ____XXXX,XXXX____,________,
  ____XXXX,XXX_____,________,
  ____XXXX,XXXXX___,________,
  ________,_XXXXX__,________,
  ________,___XXXX_,________,
  ________,___XXXX_,________,
  ________,___XXXX_,________,
  __X_____,___XXXX_,________,
  __XX____,_XXXXX__,________,
  __XXXXXX,XXXXXX__,________,
  __XXXXXX,XXXXX___,________,
  ___XXXXX,XXX_____,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________};

unsigned char Hz37B_0034[111] = { /* code 0034, DIGIT FOUR */
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,__XXXX__,________,
  ________,_XXXXX__,________,
  ________,XXXXXX__,________,
  ________,XXXXXX__,________,
  _______X,XXXXXX__,________,
  ______XX,XXXXXX__,________,
  ______XX,X_XXXX__,________,
  _____XXX,X_XXXX__,________,
  ____XXXX,__XXXX__,________,
  ___XXXX_,__XXXX__,________,
  __XXXX__,__XXXX__,________,
  _XXXX___,__XXXX__,________,
  XXXX____,__XXXX__,________,
  XXXXXXXX,XXXXXXXX,X_______,
  XXXXXXXX,XXXXXXXX,X_______,
  XXXXXXXX,XXXXXXXX,X_______,
  ________,__XXXX__,________,
  ________,__XXXX__,________,
  ________,__XXXX__,________,
  ________,__XXXX__,________,
  ________,__XXXX__,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________};

unsigned char Hz37B_0035[111] = { /* code 0035, DIGIT FIVE */
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ____XXXX,XXXXXX__,________,
  ____XXXX,XXXXXX__,________,
  ____XXXX,XXXXXX__,________,
  ____XXX_,________,________,
  ___XXXX_,________,________,
  ___XXXX_,________,________,
  ___XXXX_,________,________,
  ___XXXX_,________,________,
  ___XXXXX,XXXX____,________,
  ___XXXXX,XXXXX___,________,
  ___XXXXX,XXXXXX__,________,
  ________,_XXXXXX_,________,
  ________,___XXXX_,________,
  ________,___XXXX_,________,
  ________,___XXXX_,________,
  ________,___XXXX_,________,
  ________,__XXXXX_,________,
  ___XX___,_XXXXX__,________,
  ___XXXXX,XXXXXX__,________,
  ___XXXXX,XXXXX___,________,
  ____XXXX,XXX_____,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________};

unsigned char Hz37B_0036[111] = { /* code 0036, DIGIT SIX */
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,XXXXXXX_,________,
  ______XX,XXXXXXX_,________,
  _____XXX,XXXXXXX_,________,
  ____XXXX,X_____X_,________,
  ____XXXX,________,________,
  ___XXXX_,________,________,
  ___XXX__,________,________,
  __XXXX__,________,________,
  __XXXX__,XXXXX___,________,
  __XXXXXX,XXXXXX__,________,
  __XXXXXX,XXXXXXX_,________,
  __XXXXX_,___XXXXX,________,
  __XXXX__,____XXXX,________,
  __XXXX__,____XXXX,________,
  __XXXX__,____XXXX,________,
  __XXXX__,____XXXX,________,
  ___XXXX_,____XXXX,________,
  ___XXXX_,___XXXX_,________,
  ____XXXX,XXXXXXX_,________,
  _____XXX,XXXXXX__,________,
  ______XX,XXXX____,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________};

unsigned char Hz37B_0037[111] = { /* code 0037, DIGIT SEVEN */
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  _XXXXXXX,XXXXXXXX,________,
  _XXXXXXX,XXXXXXXX,________,
  _XXXXXXX,XXXXXXXX,________,
  ________,___XXXX_,________,
  ________,__XXXXX_,________,
  ________,__XXXX__,________,
  ________,_XXXXX__,________,
  ________,_XXXX___,________,
  ________,XXXXX___,________,
  ________,XXXX____,________,
  _______X,XXXX____,________,
  _______X,XXX_____,________,
  ______XX,XXX_____,________,
  ______XX,XXX_____,________,
  _____XXX,XX______,________,
  _____XXX,XX______,________,
  _____XXX,XX______,________,
  _____XXX,X_______,________,
  ____XXXX,X_______,________,
  ____XXXX,X_______,________,
  ____XXXX,X_______,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________};

unsigned char Hz37B_0038[111] = { /* code 0038, DIGIT EIGHT */
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ______XX,XXX_____,________,
  ____XXXX,XXXXX___,________,
  ___XXXXX,XXXXXX__,________,
  __XXXXX_,__XXXXX_,________,
  __XXXX__,___XXXX_,________,
  __XXXX__,___XXXX_,________,
  __XXXX__,___XXXX_,________,
  __XXXXX_,__XXXX__,________,
  ___XXXXX,_XXXXX__,________,
  ____XXXX,XXXX____,________,
  ____XXXX,XXXXX___,________,
  ___XXXXX,XXXXXX__,________,
  __XXXX__,___XXXX_,________,
  _XXXX___,____XXXX,________,
  _XXXX___,____XXXX,________,
  _XXXX___,____XXXX,________,
  _XXXX___,____XXXX,________,
  __XXXX__,___XXXX_,________,
  __XXXXXX,XXXXXXX_,________,
  ___XXXXX,XXXXXX__,________,
  _____XXX,XXXX____,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________};

unsigned char Hz37B_0039[111] = { /* code 0039, DIGIT NINE */
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  _____XXX,XXX_____,________,
  ___XXXXX,XXXX____,________,
  __XXXXXX,XXXXX___,________,
  __XXXX__,__XXXX__,________,
  _XXXX___,__XXXX__,________,
  _XXXX___,___XXXX_,________,
  _XXXX___,___XXXX_,________,
  _XXXX___,___XXXX_,________,
  _XXXX___,___XXXX_,________,
  _XXXXX__,__XXXXX_,________,
  __XXXXXX,XXXXXXX_,________,
  ___XXXXX,XXXXXXX_,________,
  ____XXXX,XX_XXXX_,________,
  ________,___XXXX_,________,
  ________,___XXX__,________,
  ________,__XXXX__,________,
  ________,__XXXX__,________,
  __X_____,XXXXX___,________,
  __XXXXXX,XXXX____,________,
  __XXXXXX,XXX_____,________,
  ___XXXXX,X_______,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________,
  ________,________,________};

unsigned char Hz37B_006D[148] = { /* code 006D, LATIN SMALL LETTER M */
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  __XXXX__,_XXXXX__,__XXXXX_,________,
  __XXXX_X,XXXXXXX_,_XXXXXXX,X_______,
  __XXXXXX,XXXXXXXX,XXXXXXXX,X_______,
  __XXXXX_,___XXXXX,X____XXX,XX______,
  __XXXXX_,____XXXX,X_____XX,XX______,
  __XXXX__,____XXXX,______XX,XX______,
  __XXXX__,____XXXX,______XX,XX______,
  __XXXX__,____XXXX,______XX,XX______,
  __XXXX__,____XXXX,______XX,XX______,
  __XXXX__,____XXXX,______XX,XX______,
  __XXXX__,____XXXX,______XX,XX______,
  __XXXX__,____XXXX,______XX,XX______,
  __XXXX__,____XXXX,______XX,XX______,
  __XXXX__,____XXXX,______XX,XX______,
  __XXXX__,____XXXX,______XX,XX______,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________,
  ________,________,________,________};

/*********************************************************************
*							函数
**********************************************************************/

/**
* @brief 得到字体高度
* @param font:字体
* @retval 高度
*/

uint8_t GB18030_37X37B_get_height(void)
{
	return 40;
}

/**
* @brief 得到地址
* @param font:字体
* @param ch:待读取的字符
* @param addr:数据存储地址
* @retval 读取结果.0:失败,1:成功
*/

uint8_t GB18030_37X37B_get_address(uint16_t ch,struct _Font_Type *font_type,uint32_t *addr) 
{ 
	switch (ch)
	{
		//空格
		case 0x0020:
		{
			font_type->width = 8;
			font_type->height = 37;
			font_type->size = 37;
			*addr = (uint32_t)Hz37B_0020;
			break;
		}
		//.
		case 0x002E:
		{
			font_type->width = 8;
			font_type->height = 37;
			font_type->size = 37;
			*addr = (uint32_t)Hz37B_002E;
			break;
		}
		//0
		case 0x0030:
		{
			font_type->width = 19;
			font_type->height = 37;
			font_type->size = 111;
			*addr = (uint32_t)Hz37B_0030;
			break;
		}
		//1
		case 0x0031:
		{
			font_type->width = 19;
			font_type->height = 37;
			font_type->size = 111;
			*addr = (uint32_t)Hz37B_0031;
			break;
		}
		//2
		case 0x0032:
		{
			font_type->width = 19;
			font_type->height = 37;
			font_type->size = 111;
			*addr = (uint32_t)Hz37B_0032;
			break;
		}
		//3
		case 0x0033:
		{
			font_type->width = 19;
			font_type->height = 37;
			font_type->size = 111;
			*addr = (uint32_t)Hz37B_0033;
			break;
		}
		//4
		case 0x0034:
		{
			font_type->width = 19;
			font_type->height = 37;
			font_type->size = 111;
			*addr = (uint32_t)Hz37B_0034;
			break;
		}
		//5
		case 0x0035:
		{
			font_type->width = 19;
			font_type->height = 37;
			font_type->size = 111;
			*addr = (uint32_t)Hz37B_0035;
			break;
		}
		//6
		case 0x0036:
		{
			font_type->width = 19;
			font_type->height = 37;
			font_type->size = 111;
			*addr = (uint32_t)Hz37B_0036;
			break;
		}
		//7
		case 0x0037:
		{
			font_type->width = 19;
			font_type->height = 37;
			font_type->size = 111;
			*addr = (uint32_t)Hz37B_0037;
			break;
		}
		//8
		case 0x0038:
		{
			font_type->width = 19;
			font_type->height = 37;
			font_type->size = 111;
			*addr = (uint32_t)Hz37B_0038;
			break;
		}
		//9
		case 0x0039:
		{
			font_type->width = 19;
			font_type->height = 37;
			font_type->size = 111;
			*addr = (uint32_t)Hz37B_0039;
			break;
		}
		//m
		case 0x006D:
		{
			font_type->width = 28;
			font_type->height = 37;
			font_type->size = 148;
			*addr = (uint32_t)Hz37B_006D;
			break;
		}
		default:
		{
			return 0;
		}
	}
	
	return 1;
}


