#ifndef __WS2812B_H
#define	__WS2812B_H

#include "stm32f10x.h"
#include "delay.h"	

//#define WS2812_IN_PIN	PA0

void Timer1_init(void);
void WS2812_send(uint8_t (*color)[3], uint16_t len);
void WS2812_send_weight(uint8_t (*color)[3], uint16_t len, double weight);
void WS2812_send_2_LED(uint8_t (*color1)[3], uint8_t (*color2)[3]);
void WS2812_send_10_led(uint8_t color_table[10]);
void Water_Lamp(void);
	
#endif /* __LED_H */
