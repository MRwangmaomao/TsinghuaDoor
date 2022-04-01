#ifndef _GAMEMOVE_H_
#define _GAMEMOVE_H_
#include "sys.h"
void move2(int dir);

typedef struct 
{
	u8 x;
	u8 y;
	u8 state;
	u8 dead;
}Gamemove_t;

typedef struct 
{
	u8 x;
	u8 y;
}map_t;

void move_coordinate_update(void);
void Set_Start_Point(int x,int y);
void check_State(void);
#endif
