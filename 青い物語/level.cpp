//=================================================
// [�꥾�`�ȤΥ��]
// level.cpp
// author:fuyizhi
// Date:2021/02/09
//=================================================

#include "level.h"

void InitLevel(void)
{
	//=================================================
	// �ؿ�����˳��
	// SetHotel() 
	// SetRoad();	��ͷ�ض���moveright��moveright��moveleft�Ժ�ؽ�һ��moveup��movedown
	// SetBuilding();
	// SetCustomer();
	//=================================================

	//SetHotel(5, 11);
	SetRoad(82, MOVERIGHT);
	SetBuilding(25, 13, BUILDING_TYPE_NULL);
	SetBuilding(35, 13, BUILDING_TYPE_NULL);
	SetBuilding(45, 13, BUILDING_TYPE_NULL);
	SetBuilding(55, 13, BUILDING_TYPE_NULL);
	SetCustomer(1500, THIRST);
}

void UnInitLevel(void)
{
}

void UpdateLevel(void)
{
}

void DrawLevel(void)
{
}
