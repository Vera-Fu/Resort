//=================================================
// [�꥾�`�ȤΥ��]
// road.h
// author:fuyizhi
// Date:2021/02/04
//=================================================

#ifndef ROAD_H_
#define ROAD_H_

#include "main.h"
#include "map.h"

#define MAX_ROAD 10

void InitRoad(void);
void UnInitRoad(void);
void UpdateRoad(void);
void DrawRoad(void);
void SetRoad(int end, int way);		//��Ϊ�ڶ���·��startpos���ǹ̶��ģ�����ֻ��֪����·�ķ�����յ㼴�ɻ���·��

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

