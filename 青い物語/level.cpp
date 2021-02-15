//=================================================
// [リゾートのワナ]
// level.cpp
// author:fuyizhi
// Date:2021/02/09
//=================================================

#include "level.h"

void InitLevel(void)
{
	//=================================================
	// 关卡绘制顺序
	// SetHotel() 
	// SetRoad();	开头必定是moveright，moveright或moveleft以后必接一个moveup或movedown
	// SetBuilding();
	// SetCustomer();
	//=================================================

	//SetHotel(5, 11);
	SetRoad(80, MOVERIGHT);
	SetBuilding(25, 13, BUILDING_TYPE_NULL);
	SetBuilding(35, 13, BUILDING_TYPE_NULL);
	SetBuilding(45, 13, BUILDING_TYPE_SPA);
	SetBuilding(55, 13, BUILDING_TYPE_NULL);
	SetCustomer(2000, HUNGRY, BORING);
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
