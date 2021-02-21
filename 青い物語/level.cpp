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

	switch (GetLevelIndex())
	{
	case 1:
		SetCustomer(1500, THIRST);
		SetRoad(82, MOVERIGHT);
		SetBuilding(25, 13, BUILDING_TYPE_NULL);
		SetBuilding(55, 13, BUILDING_TYPE_NULL);
		break;
	case 2:
		SetCustomer(2000, BORING);
		SetRoad(40, MOVERIGHT);
		SetRoad(10, MOVEUP);
		SetRoad(55, MOVERIGHT);
		SetRoad(22, MOVEDOWN);
		SetRoad(82, MOVERIGHT);
		SetBuilding(25, 13, BUILDING_TYPE_NULL);
		SetBuilding(65, 15, BUILDING_TYPE_NULL);
		break;
	case 3:
		SetCustomer(5000, TIRED, THIRST);
		SetRoad(40, MOVERIGHT);
		SetRoad(10, MOVEUP);
		SetRoad(55, MOVERIGHT);
		SetRoad(22, MOVEDOWN);
		SetRoad(82, MOVERIGHT);
		SetBuilding(20, 13, BUILDING_TYPE_NULL);
		SetBuilding(42, 7, BUILDING_TYPE_NULL);
		SetBuilding(60, 15, BUILDING_TYPE_NULL);
		SetBuilding(70, 15, BUILDING_TYPE_NULL);
		break;
	case 4:
		SetCustomer(4000, THIRST, BORING, TIRED);
		SetRoad(40, MOVERIGHT);
		SetRoad(10, MOVEUP);
		SetRoad(55, MOVERIGHT);
		SetRoad(22, MOVEDOWN);
		SetRoad(82, MOVERIGHT);
		SetBuilding(20, 13, BUILDING_TYPE_NULL);
		SetBuilding(45, 7, BUILDING_TYPE_NULL);
		SetBuilding(60, 15, BUILDING_TYPE_NULL);
		SetBuilding(70, 15, BUILDING_TYPE_NULL);
		break;
	case 5:
		SetCustomer(5500, BORING, HUNGRY);
		SetRoad(30, MOVERIGHT);
		break;
	case 6:
		SetCustomer(7000, TIRED, BORING, HUNGRY);
		break;
	case 7:
		SetCustomer(8500, TIRED, HUNGRY);
		break;
	case 8:
		SetCustomer(9500, THIRST, BORING, TIRED, HUNGRY);
		break;
	case 9:
		SetCustomer(11000, THIRST, BORING, TIRED, HUNGRY);
		break;
	default:
		
		break;
	}
	
	
	
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
