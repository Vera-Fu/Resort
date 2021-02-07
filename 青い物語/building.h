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

enum Building
{
	BUILDING_TYPE_NONE,		//没有此建筑位
	BUILDING_TYPE_NULL,		//空地
	BUILDING_TYPE_SPA,
	BUILDING_TYPE_CONVENIENCE,
	BUILDING_TYPE_RESTAURANT,
	BUILDING_TYPE_MASSAGE,
	BUILDING_TYPE_SING,
	BUILDING_TYPE_POKER,
	BUILDING_TYPE_STORE,
	BACK
};

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

