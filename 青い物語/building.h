//=================================================
// [�꥾�`�ȤΥ��]
// building.h
// author:fuyizhi
// Date:2021/02/08
//=================================================

#ifndef BUILDING_H_
#define BUILDING_H_

#include "main.h"
#include "choose.h"

#define MAX_BUILDING 10

#define BUILDING_MONEY_SPA 1000
#define BUILDING_MONEY_CONVENIENCE 500
#define BUILDING_MONEY_RESTAURANT 1000
#define BUILDING_MONEY_MASSAGE 1000
#define BUILDING_MONEY_SING 500
#define BUILDING_MONEY_POKER 500
#define BUILDING_MONEY_STORE 500

void InitBuilding(void);
void UnInitBuilding(void);
void UpdateBuilding(void);
void DrawBuilding(void);

void SetBuilding(int posx, int posy, int type);

int GetMaxIndex(void);

typedef struct {
	INT2 pos;

	int type;		//�����������
	int index;		//�����������

	int buff;		//������ȥ�����״̬
	int debuff;		//��ҽ���������״̬
	int money;		//��Ҫ�Ľ�Ǯ

	bool isRemoveable;
}BUILDING;

BUILDING* GetBuilding(void);

enum Building
{
	BUILDING_TYPE_NONE,		//û�д˽���λ
	BUILDING_TYPE_NULL,		//�յ�
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

