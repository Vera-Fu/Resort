//=================================================
// [リゾートのワナ]
// building.h
// author:fuyizhi
// Date:2021/02/08
//=================================================

#ifndef BUILDING_H_
#define BUILDING_H_

#include "main.h"
#include "choose.h"

#define MAX_BUILDING 10

#define BUILDING_MONEY_SPA 2000
#define BUILDING_MONEY_CONVENIENCE 500
#define BUILDING_MONEY_RESTAURANT 1000
#define BUILDING_MONEY_MASSAGE 1500
#define BUILDING_MONEY_SING 1500
#define BUILDING_MONEY_POKER 1500
#define BUILDING_MONEY_STORE 1000

void InitBuilding(void);
void UnInitBuilding(void);
void UpdateBuilding(void);
void DrawBuilding(void);

void SetBuilding(int posx, int posy, int type);

int GetMaxIndex(void);

typedef struct {
	INT2 pos;

	int type;		//建筑物的类型
	int index;		//建筑物的索引

	int buff;		//可以消去的玩家状态
	int debuff;		//玩家进入后出来的状态
	int money;		//需要的金钱

	bool isRemoveable;
}BUILDING;

BUILDING* GetBuilding(void);

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

enum STATUS
{
	NOTHING,
	HUNGRY,
	BORING,
	TIRED,
	THIRST
};

#endif // !BUILDING_H_

