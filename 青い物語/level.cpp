//=================================================
// [•Í•æ©`•»§Œ•Ô• ]
// level.cpp
// author:fuyizhi
// Date:2021/02/09
//=================================================

#include "level.h"

void InitLevel(void)
{
	//=================================================
	// •Ï•Ÿ•Î√Ë§Ø ÷Ìò
	// SetHotel() 
	// SetRoad();	moveright•π•ø©`•»£¨moveright§ﬁ§ø§œmoveleft··§œ±ÿ§∫moveup§ﬁ§ø§œmovedown
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
		SetRoad(32, MOVEDOWN);
		SetRoad(55, MOVERIGHT);
		SetRoad(15, MOVEUP);
		SetRoad(82, MOVERIGHT);
		SetBuilding(20, 13, BUILDING_TYPE_NULL);
		SetBuilding(35, 25, BUILDING_TYPE_NULL);
		SetBuilding(44, 25, BUILDING_TYPE_NULL);
		SetBuilding(55, 12, BUILDING_TYPE_NULL);
		SetBuilding(65, 12, BUILDING_TYPE_NULL); 
		break;
	case 6:
		SetCustomer(7000, TIRED, BORING, HUNGRY);
		SetRoad(30, MOVERIGHT);
		SetRoad(6, MOVEUP);
		SetRoad(60, MOVERIGHT);
		SetRoad(28, MOVEDOWN);
		SetRoad(38, MOVELEFT);
		SetRoad(38, MOVEDOWN);
		SetRoad(67, MOVERIGHT);
		SetRoad(15, MOVEUP);
		SetRoad(82, MOVERIGHT);
		SetBuilding(18, 13, BUILDING_TYPE_NULL);
		SetBuilding(40, 3, BUILDING_TYPE_NULL);
		SetBuilding(45, 21, BUILDING_TYPE_NULL);
		SetBuilding(45, 31, BUILDING_TYPE_NULL);
		SetBuilding(55, 31, BUILDING_TYPE_NULL);
		SetBuilding(70, 12, BUILDING_TYPE_NULL);
		break;
	case 7:
		SetCustomer(8500, TIRED, HUNGRY);
		SetRoad(30, MOVERIGHT);
		SetRoad(6, MOVEUP);
		SetRoad(60, MOVERIGHT);
		SetRoad(28, MOVEDOWN);
		SetRoad(38, MOVELEFT);
		SetRoad(38, MOVEDOWN);
		SetRoad(67, MOVERIGHT);
		SetRoad(15, MOVEUP);
		SetRoad(82, MOVERIGHT);
		SetBuilding(18, 13, BUILDING_TYPE_NULL);
		SetBuilding(32, 3, BUILDING_TYPE_NULL);
		SetBuilding(48, 3, BUILDING_TYPE_NULL);
		SetBuilding(45, 21, BUILDING_TYPE_NULL);
		SetBuilding(45, 31, BUILDING_TYPE_NULL);
		SetBuilding(55, 31, BUILDING_TYPE_NULL);
		SetBuilding(70, 12, BUILDING_TYPE_NULL);
		break;
	case 8:
		SetCustomer(9500, THIRST, BORING, TIRED, HUNGRY);
		SetRoad(20, MOVERIGHT);
		SetRoad(38, MOVEDOWN);
		SetRoad(50, MOVERIGHT);
		SetRoad(15, MOVEUP);
		SetRoad(15, MOVELEFT);
		SetRoad(6, MOVEUP);
		SetRoad(65, MOVERIGHT);
		SetRoad(18, MOVEDOWN);
		SetRoad(82, MOVERIGHT);
		SetBuilding(25, 31, BUILDING_TYPE_NULL);
		SetBuilding(35, 31, BUILDING_TYPE_NULL);
		SetBuilding(40, 12, BUILDING_TYPE_NULL);
		SetBuilding(25, 12, BUILDING_TYPE_NULL);
		SetBuilding(25, 3, BUILDING_TYPE_NULL);
		SetBuilding(40, 3, BUILDING_TYPE_NULL);
		SetBuilding(55, 3, BUILDING_TYPE_NULL);
		SetBuilding(70, 11, BUILDING_TYPE_NULL);
		break;
	case 9:	
		SetCustomer(11000, THIRST, BORING, TIRED, HUNGRY);
		SetRoad(20, MOVERIGHT);
		SetRoad(38, MOVEDOWN);
		SetRoad(50, MOVERIGHT);
		SetRoad(15, MOVEUP);
		SetRoad(15, MOVELEFT);
		SetRoad(6, MOVEUP);
		SetRoad(70, MOVERIGHT);
		SetRoad(19, MOVEDOWN);
		SetRoad(55, MOVELEFT);
		SetRoad(30, MOVEDOWN);
		SetRoad(75, MOVERIGHT);
		SetRoad(15, MOVEUP);
		SetRoad(82, MOVERIGHT);
		SetBuilding(25, 31, BUILDING_TYPE_NULL);
		SetBuilding(35, 31, BUILDING_TYPE_NULL);
		SetBuilding(40, 12, BUILDING_TYPE_NULL);
		SetBuilding(25, 12, BUILDING_TYPE_NULL);
		SetBuilding(18, 3, BUILDING_TYPE_NULL);
		SetBuilding(33, 3, BUILDING_TYPE_NULL);
		SetBuilding(48, 3, BUILDING_TYPE_NULL);
		SetBuilding(63, 3, BUILDING_TYPE_NULL);
		SetBuilding(58, 12, BUILDING_TYPE_NULL);
		SetBuilding(62, 23, BUILDING_TYPE_NULL);
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
