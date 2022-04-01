#ifndef _GAMEMAP_H_
#define _GAMEMAP_H_


#include "delay.h"
#include "sys.h"

void Show_GameFrame(void);

void OLED_DrawTrap1(void);
void OLED_EraseTrap1(void);
void OLED_DrawTrap2(void);
void OLED_EraseTrap2(void);
void OLED_DrawTrap3(void);
void OLED_EraseTrap3(void);
void confirm(void);
void show_stage_left(void);
void show_stage_right(void);

typedef struct
{
 u8	transt_flag;
 u8 start_flag;
 u8 page;
}Game_state_t;



#endif
