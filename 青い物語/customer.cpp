//=================================================
// [リゾートのワナ]
// customer.cpp
// author:fuyizhi
// Date:2021/02/09
//=================================================

#include "customer.h"

#define CONIOEX
#include "conioex.h"

CUSTOMER g_customer;

int index = 0;

void InitCustomer(void)
{
	float g_startCustomerX = GetHotel().pos.x + 2;
	float g_startCustomerY = GetHotel().pos.y + 5;
	g_customer.pos.x = g_startCustomerX;
	g_customer.pos.y = g_startCustomerY;
	g_customer.oldpos.x = g_customer.pos.x;
	g_customer.oldpos.y = g_customer.pos.y;
	
	g_customer.money = 2000;
	for (int i = 0; i < MAX_STATUS; i++) {
		g_customer.status[i] = NOTHING;
	}

	g_customer.isGoInto = true;
}

void UnInitCustomer(void)
{
}

void UpdateCustomer(void)
{
	//1フレーム前の位置を保存
	g_customer.oldpos.x = g_customer.pos.x;
	g_customer.oldpos.y = g_customer.pos.y;

	//位置の更新
	switch ((GetRoad() + index)->way)
	{
	case MOVEUP:
		if (g_customer.pos.y > (GetRoad() + index)->end_pos.y + 1) {
			g_customer.pos.y -= SPEED;
		}
		else {
			index++;
		}
		break;
	case MOVEDOWN:
		if (g_customer.pos.y < (GetRoad() + index)->end_pos.y - 4) {
			g_customer.pos.y += SPEED;
		}
		else {
			index++;
		}
		break;
	case MOVELEFT:
		if (g_customer.pos.x > (GetRoad() + index)->end_pos.x + 2) {
			g_customer.pos.x -= SPEED;
		}
		else {
			index++;
		}
		break;
	case MOVERIGHT:
		if (g_customer.pos.x < (GetRoad() + index)->end_pos.x - 2) {
			g_customer.pos.x += SPEED;
		}
		else {
			index++;
		}
		break;
	case NONE:
		break;
	default:
		break;
	}

	for (int i = 0; i < MAX_BUILDING; i++)
	{
		//用于碰撞检测
		if ((int)g_customer.pos.x == (GetBuilding() + i)->pos.x + 2 && (int)g_customer.pos.y == (GetBuilding() + i)->pos.y + 3) {
			//用于判断该建筑是否会给顾客继续追加身上已有的状态，如果会，则不进入
			for (int j = 0; j < MAX_STATUS; j++)
			{
				if (g_customer.status[i] == (GetBuilding() + i)->debuff)
				{
					g_customer.isGoInto = false;
					break;
				}
				else {
					g_customer.isGoInto = true;
				}
				
			}
			//判断是否进入该建筑
			if (g_customer.isGoInto) {
				for (int j = 0; j < MAX_STATUS; j++)
				{
					//状态和金钱处理
					if (g_customer.status[j] == (GetBuilding() + i)->buff && g_customer.money >= (GetBuilding() + i)->money) {
						g_customer.status[j] = (GetBuilding() + i)->debuff;
						g_customer.money -= (GetBuilding() + i)->money;
					}
				}
			}
			
						
			gotoxy(118, 26);
			printf("index=%d", (GetBuilding() + i)->type);
		}
	}

}
//g_customer.pos.y += SPEED;	


void DrawCustomer(void)
{
	textattr(0xF0);
	gotoxy((int)g_customer.oldpos.x, (int)g_customer.oldpos.y + 1);
	printf("  ");
	gotoxy((int)g_customer.pos.x, (int)g_customer.pos.y + 1);
	printf("●");

	gotoxy((int)g_customer.oldpos.x, (int)g_customer.oldpos.y + 2);
	printf("  ");
	gotoxy((int)g_customer.pos.x, (int)g_customer.pos.y + 2);
	printf("■");

	gotoxy((int)g_customer.oldpos.x, (int)g_customer.oldpos.y + 3);
	printf("  ");
	gotoxy((int)g_customer.pos.x, (int)g_customer.pos.y + 3);
	printf("▼");
	textattr(0x0F);

	//----------------
	gotoxy(118, 27);
	printf("money=%d", g_customer.money);
	gotoxy(118, 28);
	printf("status0=%d", g_customer.status[0]);
	gotoxy(118, 29);
	printf("status1=%d", g_customer.status[1]);
}

void SetCustomer(int money, int status0 = NOTHING, int status1 = NOTHING, int status2 = NOTHING, int status3 = NOTHING)
{
	g_customer.money = money;
	g_customer.status[0] = status0;
	g_customer.status[1] = status1;
	g_customer.status[2] = status2;
	g_customer.status[3] = status3;
}
