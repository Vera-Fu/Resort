//=================================================
// [リゾートのワナ]
// road.h
// author:fuyizhi
// Date:2021/02/04
//=================================================

#ifndef ROAD_H_
#define ROAD_H_

#include "main.h"
#include "map.h"

#define MAX_ROAD 20

void InitRoad(void);
void UnInitRoad(void);
void UpdateRoad(void);
void DrawRoad(void);
void SetRoad(int end, int way);		//因为第二条路的startpos总是固定的，所以只需知晓道路的方向和终点即可绘制路线

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
	MOVERIGHT,
	NONE
};

ROAD* GetRoad(void);

#endif // !ROAD_H_

