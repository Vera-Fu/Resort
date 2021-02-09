//=================================================
// [¥ê¥¾©`¥È¤Î¥ï¥Ê]
// road.h
// author:fuyizhi
// Date:2021/02/04
//=================================================

#ifndef ROAD_H_
#define ROAD_H_

#include "main.h"

#define MAX_ROAD 10

#define ROAD_START0_X 5
#define ROAD_START0_Y 17

void InitRoad(void);
void UnInitRoad(void);
void UpdateRoad(void);
void DrawRoad(void);
void SetRoad(int startposx, int startposy, int endposx, int endposy, int way);

typedef struct {
	INT2 start_pos;
	INT2 end_pos;

	int way;
	bool isUse;
}ROAD;

enum WAY {
	MOVEUP,
	MOVEDOWN,
	MOVELEFT,
	MOVERIGHT
};

#endif // !ROAD_H_

