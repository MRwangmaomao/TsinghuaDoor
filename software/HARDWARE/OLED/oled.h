#ifndef __OLED_H
#define __OLED_H

#include "sys.h"
#include "stdlib.h"	 
//const unsigned char Res_Battery0_Bmp[114UL + 1] = {
//  0x42, 0x4D, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0x80, 0xFF, 0x20, 0x00, 0x80, 0x04, 0xE0, 0x00, 0x80, 0x00, 0xE0, 0x00,
//  0x80, 0x00, 0xE0, 0x00, 0x80, 0x00, 0xE0, 0x00, 0x80, 0x00, 0xE0, 0x00, 0x80, 0x00, 0xE0, 0x00, 0x80, 0x00, 0x20, 0x00, 0x80, 0x00, 0x3F, 0xFF, 0x80, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//}; 

//-----------------OLED端口定义----------------  					   


#define OLED_RST_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_5)//RES
#define OLED_RST_Set() GPIO_SetBits(GPIOB,GPIO_Pin_5)

#define OLED_DC_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_8)//DC
#define OLED_DC_Set() GPIO_SetBits(GPIOB,GPIO_Pin_8)

#define OLED_D0_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_7)
#define OLED_D0_Set() GPIO_SetBits(GPIOB,GPIO_Pin_7)

#define OLED_D1_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_6)
#define OLED_D1_Set() GPIO_SetBits(GPIOB,GPIO_Pin_6)


#define XLevelL		0x00
#define XLevelH		0x10
#define XLevel		((XLevelH&0x0F)*16+XLevelL)
#define Max_Column	128
#define Max_Row		  64
#define	Brightness	0xCF 000000000000000000000000000000000000
#define X_WIDTH 128
#define Y_WIDTH 64

//#define GPIO_PIN_MASK      0x1Fu    //0x1f=31,限制位数为0--31有效
//#define GPIO_PIN(x)        (((1)<<(x & GPIO_PIN_MASK)))  //把当前位置1

extern void OLED_Init(void);
extern void OLED_CLS(void);
extern void OLED_DLY_ms(u16 ms);
extern void OLED_WrDat(u8 data);
extern void OLED_WrCmd(u8 cmd);
extern void OLED_Set_Pos(u8 x, u8 y);
extern void oled_set_pos(uint8_t x,uint8_t y);
extern void OLED_P6x8Str(u8 x,u8 y,u8 ch[]);
extern void OLED_P8x16Str(u8 x,u8 y,u8 ch[]);
extern void OLED_P14x16Str(u8 x,u8 y,u8 ch[]);
extern void OLED_P16x16Str(u8 x,u8 y,u8 ch[]);
extern void OLED_Print(u8 x, u8 y, u8 ch[]);
extern void OLED_PutPixel(u8 x,u8 y);
extern void Draw_BMP(u8 x0,u8 y0,u8 x1,u8 y1,u8 bmp[]); 
extern void OLED_Fill(u8 dat);
extern void OLED_P8x16Num(u8 _x,u8 _y,int _num);
extern void OLED_P6x8Num(u8 _x,u8 _y,int _num);
extern void OLED_P6x8Float(u8 _x,u8 _y,float _num);
extern void OLED_P8x16Float(u8 _x,u8 _y,float _num);
extern void OLED_OFF(void);
extern void OLED_ON(void);
extern void OLED_Draw_TsinghuaLogo(void);
extern void inf_lcd_draw_pixel(u8 x, u8 y, u8 show); 

// game
extern void Map_data_Init(void);
extern void OLED_Refresh_Gram(void);
extern void OLED_DrawPoint(u8 x,u8 y,u8 t,u8 flag);
extern void OLED_DawaLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot, u8 flag);
extern void OLED_DrawSquare(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot,u8 flag);
extern void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);
#endif



