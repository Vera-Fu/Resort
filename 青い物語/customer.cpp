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
}
