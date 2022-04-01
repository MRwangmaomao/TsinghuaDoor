#include "WS2812B.h"
/* Buffer that holds one complete DMA transmission
 * 
 * Ensure that this buffer is big enough to hold
 * all data bytes that need to be sent
 * 
 * The buffer size can be calculated as follows:
 * number of LEDs * 24 bytes + 42 bytes
 * 
 * This leaves us with a maximum string length of
 * (2^16 bytes per DMA stream - 42 bytes)/24 bytes per LED = 2728 LEDs
 */
//#define TIM3_CCR3_Address 0x4000043c 	// physical memory address of Timer 3 CCR1 register
//#define TIM3_CCR1_Address 0x40000434	// physical memory address of Timer 3 CCR1 register
 
#define TIM1_CCR1_Address 0x40012C34	
#define TIMING_ONE  50
#define TIMING_ZERO 25
 uint16_t LED_BYTE_Buffer[300];
 uint8_t ten_color_table[10]; // 10个灯的状态表 
 
 
// 颜色表参考 https://jingyan.baidu.com/article/b7001fe14abba34f7382dd55.html
 
uint8_t Brown[][3] = {0xA5,0x2A,0x2A};
uint8_t DarkSlateBlue[][3] = {0x48,0x3D,0x8B};
uint8_t Blue[][3] = {0,0,0xF1};
uint8_t AntiqueWhite[][3] = {0xFA,0xEB,0xD7};
uint8_t Azure[][3] = {0,255,0};
uint8_t Aqua[][3] = {0x00,0xFF,0xFF};
uint8_t Amethyst[][3] = {0x99,0x66,0xCC};
uint8_t DarkOrange[][3] = {0xFF,0x8C,0x00};
uint8_t Chartreuse[][3] = {0x7F,0xFF,0x00};
uint8_t CadetBlue[][3] = {0x5F,0x9E,0xA0};
uint8_t Black[][3] = {0x00,0x00,0x00};


////			                       Black            Brown            DarkSlateBlue      Blue        AntiqueWhite     Azure
//uint8_t AllColor[11][3] = { {0x00,0x00,0x00}, {0xA5,0x2A,0x2A}, {0x48,0x3D,0x8B}, {0,0,0xF1},{0xFA,0xEB,0xD7},{0,255,0},
////      Aqua               Amethyst        DarkOrange      Chartreuse         CadetBlue       
//	{0x00,0xFF,0xFF}, {0x99,0x66,0xCC}, {0xFF,0x8C,0x00}, {0x7F,0xFF,0x00}, {0x5F,0x9E,0xA0}};

//			                       Black            Brown            DarkSlateBlue      Blue        AntiqueWhite     Azure
uint8_t AllColor[11][3] = { {0,0,0}, {0,0,1}, {0,1,0}, {0,1,1},{1,0,0},{1,0,1},
//      Aqua               Amethyst        DarkOrange      Chartreuse         CadetBlue       
	{1,1,0}, {1,1,1}, {2,1,0}, {1,2,0}, {1,2,1}};

	
uint8_t ten_color[10][3]; // 10个led灯的状态

//---------------------------------------------------------------//

void Timer1_init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  DMA_InitTypeDef DMA_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	/* GPIOA Configuration: TIM1 Channel 1 as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	/* Compute the prescaler value */
	//PrescalerValue = (uint16_t) (SystemCoreClock / 24000000) - 1;
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = 90-1; // 800kHz 
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

	/* PWM1 Mode configuration: Channel1 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
		
	/* configure DMA */
	/* DMA clock enable */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	/* DMA1 Channel6 Config */
	DMA_DeInit(DMA1_Channel2);

	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)TIM1_CCR1_Address;	// physical address of Timer 3 CCR1
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)LED_BYTE_Buffer;		// this is the buffer memory 
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;						// data shifted from memory to peripheral
	DMA_InitStructure.DMA_BufferSize = 42;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;					// automatically increase buffer index
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;							// stop DMA feed after buffer size is reached
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	
	DMA_Init(DMA1_Channel2, &DMA_InitStructure);

		/* TIM1 CC1 DMA Request enable */
	TIM_DMACmd(TIM1, TIM_DMA_Update, ENABLE);
}

/* This function sends data bytes out to a string of WS2812s
 * The first argument is a pointer to the first RGB triplet to be sent
 * The seconds argument is the number of LEDs in the chain
 * 
 * This will result in the RGB triplet passed by argument 1 being sent to 
 * the LED that is the furthest away from the controller (the point where
 * data is injected into the chain)
 */
void WS2812_send(uint8_t (*color)[3], uint16_t len)
{
	uint8_t i;
	uint16_t memaddr;
	uint16_t buffersize;
	buffersize = (len*24)+43;	// number of bytes needed is #LEDs * 24 bytes + 42 trailing bytes
	memaddr = 0;				// reset buffer memory index

	while (len)
	{	
			for(i=0; i<8; i++) // GREEN data
			{
					LED_BYTE_Buffer[memaddr] = ((color[0][1]<<i) & 0x0080) ? TIMING_ONE:TIMING_ZERO;
					memaddr++;
			}
			for(i=0; i<8; i++) // RED
			{
					LED_BYTE_Buffer[memaddr] = ((color[0][0]<<i) & 0x0080) ? TIMING_ONE:TIMING_ZERO;
					memaddr++;
			}
			for(i=0; i<8; i++) // BLUE
			{
					LED_BYTE_Buffer[memaddr] = ((color[0][2]<<i) & 0x0080) ? TIMING_ONE:TIMING_ZERO;
					memaddr++;
			}
			
		  len--;
	}
//===================================================================//	
//bug：最后一个周期波形不知道为什么全是高电平，故增加一个波形
  	LED_BYTE_Buffer[memaddr] = ((color[0][2]<<8) & 0x0080) ? TIMING_ONE:TIMING_ZERO;
//===================================================================//	
	  memaddr++;	
		while(memaddr < buffersize)
		{
			LED_BYTE_Buffer[memaddr] = 0;
			memaddr++;
		}

		DMA_SetCurrDataCounter(DMA1_Channel2, buffersize); 	// load number of bytes to be transferred
		DMA_Cmd(DMA1_Channel2, ENABLE); 			// enable DMA channel 6
		TIM_Cmd(TIM1, ENABLE); 						// enable Timer 3
		while(!DMA_GetFlagStatus(DMA1_FLAG_TC2)) ; 	// wait until transfer complete
		TIM_Cmd(TIM1, DISABLE); 	// disable Timer 3
		DMA_Cmd(DMA1_Channel2, DISABLE); 			// disable DMA channel 6
		DMA_ClearFlag(DMA1_FLAG_TC2); 				// clear DMA1 Channel 6 transfer complete flag
}


/* This function sends data bytes out to a string of WS2812s
 * The first argument is a pointer to the first RGB triplet to be sent
 * The seconds argument is the number of LEDs in the chain
 * 
 * This will result in the RGB triplet passed by argument 1 being sent to 
 * the LED that is the furthest away from the controller (the point where
 * data is injected into the chain)
 */
void WS2812_send_10_led(uint8_t color_table[10])
{
	uint8_t i;
	uint8_t j;
	uint8_t led_timer;
	uint16_t memaddr;
	uint16_t buffersize;
	uint16_t len = 10;
	buffersize = (len*24)+43;	// number of bytes needed is #LEDs * 24 bytes + 42 trailing bytes
	memaddr = 0;				// reset buffer memory index
	led_timer = 0;
	
	// 更新10个灯的颜色表
	for(j = 0; j < 10; j++){ 
		for(i = 0; i < 3; i++){
		 ten_color[j][i] = AllColor[color_table[j]][i];
		}
	}
	
	while (led_timer < len)
	{	
			for(i=0; i<8; i++) // GREEN data
			{
					LED_BYTE_Buffer[memaddr] = ((ten_color[led_timer][1]<<i) & 0x0080) ? TIMING_ONE:TIMING_ZERO;
					memaddr++;
			}
			for(i=0; i<8; i++) // RED
			{
					LED_BYTE_Buffer[memaddr] = ((ten_color[led_timer][0]<<i) & 0x0080) ? TIMING_ONE:TIMING_ZERO;
					memaddr++;
			}
			for(i=0; i<8; i++) // BLUE
			{
					LED_BYTE_Buffer[memaddr] = ((ten_color[led_timer][2]<<i) & 0x0080) ? TIMING_ONE:TIMING_ZERO;
					memaddr++;
			}
			
		  led_timer++;
	}
//===================================================================//	
//bug：最后一个周期波形不知道为什么全是高电平，故增加一个波形
  	LED_BYTE_Buffer[memaddr] = ((ten_color[9][2]<<8) & 0x0080) ? TIMING_ONE:TIMING_ZERO;
//===================================================================//	
	  memaddr++;	
		while(memaddr < buffersize)
		{
			LED_BYTE_Buffer[memaddr] = 0;
			memaddr++;
		}

		DMA_SetCurrDataCounter(DMA1_Channel2, buffersize); 	// load number of bytes to be transferred
		DMA_Cmd(DMA1_Channel2, ENABLE); 			// enable DMA channel 6
		TIM_Cmd(TIM1, ENABLE); 						// enable Timer 3
		while(!DMA_GetFlagStatus(DMA1_FLAG_TC2)) ; 	// wait until transfer complete
		TIM_Cmd(TIM1, DISABLE); 	// disable Timer 3
		DMA_Cmd(DMA1_Channel2, DISABLE); 			// disable DMA channel 6
		DMA_ClearFlag(DMA1_FLAG_TC2); 				// clear DMA1 Channel 6 transfer complete flag
}
 
void Water_Lamp()
{
	uint8_t i,j; 
	 uint8_t ten_color_table_temp[10]; 
	for(i = 0; i < 10; i++){
		ten_color_table[i] = i + 1;
	}
	WS2812_send_10_led(ten_color_table);
	delay_ms(100);
	while(1)
	{
		for(i = 0; i < 10; i++){
			for(j = 0; j < 10; j++){
				ten_color_table_temp[j] = ten_color_table[j];
			} 
			 
		  ten_color_table[0] = ten_color_table_temp[5];
			ten_color_table[1] = ten_color_table_temp[0];
			ten_color_table[2] = ten_color_table_temp[1]; 
			ten_color_table[3] = ten_color_table_temp[2]; 
			ten_color_table[4] = ten_color_table_temp[3]; 
			ten_color_table[9] = ten_color_table_temp[4]; 
			ten_color_table[8] = ten_color_table_temp[9]; 
			ten_color_table[7] = ten_color_table_temp[8]; 
			ten_color_table[6] = ten_color_table_temp[7]; 
			ten_color_table[5] = ten_color_table_temp[6];  
			WS2812_send_10_led(ten_color_table);
			delay_ms(300);
		}
	}
}
