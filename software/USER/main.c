#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "ws2812b.h"
#include "oled.h"
#include "key.h"  
#include "Game_turtle.h"
#include "gui_widget_image.h"
#include "gui_widget_progbar.h"
#include "gui_2d_lib.h" 
#include "gui.h"
#include "beep.h"

const unsigned char Res_Battery0_Bmp[114UL + 1] = {
  0x42, 0x4D, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0x80, 0xFF, 0x20, 0x00, 0x80, 0x04, 0xE0, 0x00, 0x80, 0x00, 0xE0, 0x00,
  0x80, 0x00, 0xE0, 0x00, 0x80, 0x00, 0xE0, 0x00, 0x80, 0x00, 0xE0, 0x00, 0x80, 0x00, 0xE0, 0x00, 0x80, 0x00, 0x20, 0x00, 0x80, 0x00, 0x3F, 0xFF, 0x80, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}; 

int main(void)
{  
	static Widget_Image_Handle Widget_Image_Battery;
	static Widget_Progbar_Handle Widget_Progbar;
	int i;
	u8 F14x16_Idx1[] = {"清华大学录取通知书"};
	u8 F14x16_Idx2[] = {"在等你"};
	u8 F14x16_Idx3[] = {"录取通知书生成中"};
	u8 F14x16_Idx4[] = {"高考加油"}; 
	
	delay_init();	    //延时函数初始化	  
	BEEP_Init();
	LED_Init();		  	//初始化与LED连接的硬件接口
	Timer1_init();
	OLED_Init();
	KEY_Init();
	turtle_evil();
	 
	LED0 = 0;
	
	/********************************通知书生成*************************************/
  OLED_CLS();
	OLED_P14x16Str(35,0,F14x16_Idx4); 
	Widget_Progbar = gui_widget_progbar_create(9,20,111,8); 
	for(i = 0; i <= 100; i++){
		gui_widget_progbar_set_value(Widget_Progbar,i);
		delay_ms(30);		
	}
	delay_ms(300);
	OLED_CLS();
	OLED_P14x16Str(0,0,F14x16_Idx1); 
	OLED_P14x16Str(36,3,F14x16_Idx2);
	while(1);
	/*******************************************************************************/
	 
	/********************************通知书生成*************************************/
  OLED_CLS();
	OLED_P14x16Str(100,0,F14x16_Idx4); 
	Widget_Progbar = gui_widget_progbar_create(9,20,111,8); 
	for(i = 0; i <= 100; i++){
		gui_widget_progbar_set_value(Widget_Progbar,i);
		delay_ms(30);		
	}
	delay_ms(300);
	OLED_CLS();
	OLED_P14x16Str(0,0,F14x16_Idx1); 
	OLED_P14x16Str(36,3,F14x16_Idx2);
	/*******************************************************************************/

	Water_Lamp(); 
}



