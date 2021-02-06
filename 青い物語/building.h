/*-------------------------------------------------
* building.cpp
*
*
*
*								Author:	yizhi Fu
*								Date:	2021/1/28
--------------------------------------------------*/

#ifndef BUILDING_H_
#define BUILDING_H_

#include "main.h"
#include "choose.h"

#define MAX_BUILDING 10

void InitBuilding(void);
void UnInitBuilding(void);
void UpdateBuilding(void);
void DrawBuilding(void);

void SetBuilding(int posx, int posy);

int GetMaxIndex(void);

typedef struct {
	INT2 pos;

	int type;		//建筑物的类型
	int index;		//建筑物的索引
}BUILDING;

BUILDING* GetBuilding(void);

#endif // !BUILDING_H_

