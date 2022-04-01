/**
* Copyright (c), 2015-2025
* @file FHZ17.c
* @brief 17ºÅºº×Ö×Ö¿â,×ÖÌåÎ¢ÈíÑÅºÚ
* @author jdh
* @date 2015/9/6
* @date 2015/9/7
* @date 2015/9/9
*/

/*********************************************************************
*							Í·ÎÄ¼ş
**********************************************************************/

#include "font.h"

/*********************************************************************
*							¾²Ì¬±äÁ¿
**********************************************************************/

unsigned char Hz17_0020[ 17] = { /* code 0020, SPACE */
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

unsigned char Hz17_002E[ 17] = { /* code 002E, FULL STOP */
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
  _XX_____,
  _XX_____,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_0030[ 17] = { /* code 0030, DIGIT ZERO */
  ________,
  ________,
  ________,
  ________,
  __XXX___,
  __X_XX__,
  _X___X__,
  _X___X__,
  _X___X__,
  _X___X__,
  _X___X__,
  _XX_X___,
  __XXX___,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_0031[ 17] = { /* code 0031, DIGIT ONE */
  ________,
  ________,
  ________,
  ________,
  __XX____,
  _XXX____,
  ___X____,
  ___X____,
  ___X____,
  ___X____,
  ___X____,
  ___X____,
  _XXXXX__,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_0032[ 17] = { /* code 0032, DIGIT TWO */
  ________,
  ________,
  ________,
  ________,
  __XXX___,
  _X___X__,
  _____X__,
  _____X__,
  ____X___,
  ___XX___,
  __XX____,
  __X_____,
  _XXXXX__,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_0033[ 17] = { /* code 0033, DIGIT THREE */
  ________,
  ________,
  ________,
  ________,
  __XXX___,
  _X___X__,
  _____X__,
  _____X__,
  __XXX___,
  _____X__,
  _____X__,
  _X___X__,
  __XXX___,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_0034[ 17] = { /* code 0034, DIGIT FOUR */
  ________,
  ________,
  ________,
  ________,
  ___XX___,
  ___XX___,
  __X_X___,
  __X_X___,
  _X__X___,
  X___X___,
  XXXXXX__,
  ____X___,
  ____X___,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_0035[ 17] = { /* code 0035, DIGIT FIVE */
  ________,
  ________,
  ________,
  ________,
  _XXXXX__,
  _X______,
  _X______,
  _XXXX___,
  ____XX__,
  _____X__,
  _____X__,
  _X__XX__,
  __XXX___,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_0036[ 17] = { /* code 0036, DIGIT SIX */
  ________,
  ________,
  ________,
  ________,
  __XXX___,
  __X_____,
  _X______,
  _XXXX___,
  _X___X__,
  _X___X__,
  _X___X__,
  _XX__X__,
  __XXX___,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_0037[ 17] = { /* code 0037, DIGIT SEVEN */
  ________,
  ________,
  ________,
  ________,
  _XXXXX__,
  _____X__,
  ____X___,
  ____X___,
  ____X___,
  ___X____,
  ___X____,
  ___X____,
  __X_____,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_0038[ 17] = { /* code 0038, DIGIT EIGHT */
  ________,
  ________,
  ________,
  ________,
  __XXX___,
  _X___X__,
  _X___X__,
  _XX_X___,
  __XXX___,
  _X___X__,
  _X___X__,
  _X___X__,
  __XXX___,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_0039[ 17] = { /* code 0039, DIGIT NINE */
  ________,
  ________,
  ________,
  ________,
  __XXX___,
  _X__XX__,
  _X___X__,
  _X___X__,
  _X___X__,
  __XXXX__,
  _____X__,
  ____X___,
  _XXX____,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_003A[ 17] = { /* code 003A, COLON */
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  ________,
  _XX_____,
  _XX_____,
  ________,
  ________,
  _XX_____,
  _XX_____,
  ________,
  ________,
  ________,
  ________};

unsigned char Hz17_CBD1[ 34] = { /* code 641C */
  ________,________,
  ________,________,
  ________,________,
  __X___XX,________,
  __X_XX_X,XXX_____,
  XXXXX__X,__X_____,
  __X_XXXX,_XX_____,
  __X_X__X,__X_____,
  __XXXXXX,XXX_____,
  XXX____X,________,
  __X_XXXX,XX______,
  __X__X__,XX______,
  __X___XX,X_______,
  XXX_XXX_,XXXX____,
  ________,________,
  ________,________,
  ________,________};

unsigned char Hz17_CBF7[ 34] = { /* code 7D22 */
  ________,________,
  ________,________,
  ________,________,
  ______X_,________,
  _XXXXXXX,XXXX____,
  ______X_,________,
  _XXXXXXX,XXXX____,
  _X___X_X,X__X____,
  ___XXXX_,________,
  ____X___,XX______,
  __XXXXXX,XXXX____,
  ______X_,________,
  ___X__X_,XX______,
  _XX_XXX_,__XX____,
  ________,________,
  ________,________,
  ________,________};

unsigned char Hz17_CDA3[ 34] = { /* code 505C */
  ________,________,
  ________,________,
  ________,________,
  ___X___X,X_______,
  __XXXXXX,XXXX____,
  __X__X__,__X_____,
  _XX__XXX,XXX_____,
  XXX_____,________,
  X_XXXXXX,XXXX____,
  __XX____,___X____,
  __X_XXXX,XXX_____,
  __X_____,X_______,
  __X_____,X_______,
  __X___XX,X_______,
  ________,________,
  ________,________,
  ________,________};

unsigned char Hz17_D6B9[ 34] = { /* code 6B62 */
  ________,________,
  ________,________,
  ________,________,
  ______X_,________,
  ______X_,________,
  __X___X_,________,
  __X___XX,XXX_____,
  __X___X_,________,
  __X___X_,________,
  __X___X_,________,
  __X___X_,________,
  __X___X_,________,
  __X___X_,________,
  XXXXXXXX,XXXX____,
  ________,________,
  ________,________,
  ________,________};

/**
* @brief ×Ö·û:Î§
*/
	
unsigned char Hz17_CEA7[ 34] = { /* code 56F4 */
  ________,________,
  ________,________,
  ________,________,
  _XXXXXXX,XXX_____,
  _X___X__,__X_____,
  _X_XXXXX,X_X_____,
  _X___X__,__X_____,
  _X_XXXXX,X_X_____,
  _X___X__,__X_____,
  _XXXXXXX,X_X_____,
  _X___X__,X_X_____,
  _X___X_X,X_X_____,
  _XXXXXXX,XXX_____,
  _X______,__X_____,
  ________,________,
  ________,________,
  ________,________};

/**
* @brief ×Ö·û:Î§
*/
  
unsigned char Hz17_C0B8[ 34] = { /* code 680F */
  ________,________,
  ________,________,
  ________,________,
  __X__XX_,__X_____,
  __X____X,_X______,
  XXXXXXXX,XXXX____,
  __X_____,________,
  _XXX____,________,
  _XX_X___,________,
  X_X_XXXX,XXX_____,
  X_X_____,________,
  __X_____,________,
  __X_____,________,
  __X_XXXX,XXXX____,
  ________,________,
  ________,________,
  ________,________};

/*********************************************************************
*							º¯Êı
**********************************************************************/

/**
* @brief µÃµ½×ÖÌå¸ß¶È
* @param font:×ÖÌå
* @retval ¸ß¶È
*/

uint8_t GB18030_17X17_get_height(void)
{
	return 17;
}

/**
* @brief µÃµ½µØÖ·
* @param font:×ÖÌå
* @param ch:´ı¶ÁÈ¡µÄ×Ö·û
* @param addr:Êı¾İ´æ´¢µØÖ·
* @retval ¶ÁÈ¡½á¹û.0:Ê§°Ü,1:³É¹¦
*/

uint8_t GB18030_17X17_get_address(uint16_t ch,struct _Font_Type *font_type,uint32_t *addr) 
{ 
	switch (ch)
	{
		//¿Õ¸ñ
		case 0x0020:
		{
			font_type->width = 4;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_0020;
			break;
		}
		//.
		case 0x002E:
		{
			font_type->width = 3;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_002E;
			break;
		}
		//0
		case 0x0030:
		{
			font_type->width = 7;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_0030;
			break;
		}
		//1
		case 0x0031:
		{
			font_type->width = 7;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_0031;
			break;
		}
		//2
		case 0x0032:
		{
			font_type->width = 7;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_0032;
			break;
		}
		//3
		case 0x0033:
		{
			font_type->width = 7;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_0033;
			break;
		}
		//4
		case 0x0034:
		{
			font_type->width = 7;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_0034;
			break;
		}
		//5
		case 0x0035:
		{
			font_type->width = 7;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_0035;
			break;
		}
		//6
		case 0x0036:
		{
			font_type->width = 7;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_0036;
			break;
		}
		//7
		case 0x0037:
		{
			font_type->width = 7;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_0037;
			break;
		}
		//8
		case 0x0038:
		{
			font_type->width = 7;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_0038;
			break;
		}
		//9
		case 0x0039:
		{
			font_type->width = 7;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_0039;
			break;
		}
		//9
		case 0x003A:
		{
			font_type->width = 3;
			font_type->height = 17;
			font_type->size = 17;
			*addr = (uint32_t)Hz17_003A;
			break;
		}
		//ËÑ
		case 0xCBD1:
		{
			font_type->width = 12;
			font_type->height = 17;
			font_type->size = 34;
			*addr = (uint32_t)Hz17_CBD1;
			break;
		}
		//Ë÷
		case 0xCBF7:
		{
			font_type->width = 12;
			font_type->height = 17;
			font_type->size = 34;
			*addr = (uint32_t)Hz17_CBF7;
			break;
		}
		//Í£
		case 0xCDA3:
		{
			font_type->width = 12;
			font_type->height = 17;
			font_type->size = 34;
			*addr = (uint32_t)Hz17_CDA3;
			break;
		}
		//Ö¹
		case 0xD6B9:
		{
			font_type->width = 12;
			font_type->height = 17;
			font_type->size = 34;
			*addr = (uint32_t)Hz17_D6B9;
			break;
		}
		//Î§
		case 0xCEA7:
		{
			font_type->width = 12;
			font_type->height = 17;
			font_type->size = 34;
			*addr = (uint32_t)Hz17_CEA7;
			break;
		}
		//À¸
		case 0xC0B8:
		{
			font_type->width = 12;
			font_type->height = 17;
			font_type->size = 34;
			*addr = (uint32_t)Hz17_C0B8;
			break;
		}
		default:
		{
			return 0;
		}
	}
	
	return 1;
}


