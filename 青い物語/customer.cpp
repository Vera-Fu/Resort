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
int money = opensound((char*)"sound\\money.mp3");

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
	g_customer.speed = SPEED;

	g_customer.isGoInto = true;
	g_customer.isMoving = false;
	g_customer.isBuy = false;
	g_customer.isEnd = false;
	
	//SetCustomer(2000, HUNGRY);
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
	if (g_customer.isMoving) {
		switch ((GetRoad() + index)->way)
		{
		case MOVEUP:
			if (g_customer.pos.y > (GetRoad() + index)->end_pos.y + 1) {
				g_customer.pos.y -= g_customer.speed;
			}
			else {
				index++;
			}
			break;
		case MOVEDOWN:
			if (g_customer.pos.y < (GetRoad() + index)->end_pos.y - 4) {
				g_customer.pos.y += g_customer.speed;
			}
			else {
				index++;
			}
			break;
		case MOVELEFT:
			if (g_customer.pos.x > (GetRoad() + index)->end_pos.x + 2) {
				g_customer.pos.x -= g_customer.speed;
			}
			else {
				index++;
			}
			break;
		case MOVERIGHT:
			if (g_customer.pos.x < (GetRoad() + index)->end_pos.x - 2) {
				g_customer.pos.x += g_customer.speed;
			}
			else {
				index++;
			}
			break;
		/*case NONE:
			g_customer.isEnd = true;
			break;*/
		default:
			break;
		}
	}
	
	//判断顾客是否已经走到尽头
	if (g_customer.pos.x >= 80) {
		g_customer.isEnd = true;
	}

	textattr(0x0F);
	for (int i = 0; i < MAX_BUILDING; i++)
	{
		//用于碰撞检测
		if ((int)g_customer.pos.x == (GetBuilding() + i)->pos.x + 3 && (int)g_customer.pos.y == (GetBuilding() + i)->pos.y + 3) {
			g_customer.speed = 0;
			for (int j = 0; j < MAX_STATUS; j++)
			{
				//用于判断该建筑是否会给顾客继续追加身上已有的状态，如果会，则不进入
				if (g_customer.status[j] == (GetBuilding() + i)->debuff && g_customer.status[j] != NOTHING)
				{
					switch ((GetBuilding() + i)->debuff)
					{
					case HUNGRY:
						gotoxy(logx, logy);
						printf("肚子好饿.");
						msleep(750);
						printf(".");
						msleep(750);
						printf(".");
						msleep(500);
						clearLog();
						break;
					case BORING:
						gotoxy(logx, logy);
						printf("好无聊.");
						msleep(750);
						printf(".");
						msleep(750);
						printf(".");
						msleep(500);
						clearLog();
						break;
					case TIRED:
						gotoxy(logx, logy);
						printf("好累.");
						msleep(750);
						printf(".");
						msleep(750);
						printf(".");
						msleep(500);
						clearLog();
						break;
					case THIRST:
						gotoxy(logx, logy);
						printf("口好渴.");
						msleep(750);
						printf(".");
						msleep(750);
						printf(".");
						msleep(500);
						clearLog();
						break;
					default:
						break;
					}
					if ((GetRoad() + index)->way == MOVERIGHT) {
						g_customer.pos.x += 1;
					}
					if ((GetRoad() + index)->way == MOVELEFT) {
						g_customer.pos.x -= 1;
					}
					g_customer.isGoInto = false;
					g_customer.speed = SPEED;
					break;
				}
				////用于判断该建筑是否会给消除顾客身上已有的状态，如果不会，则不进入
				//else if (g_customer.status[i] != (GetBuilding() + i)->buff) {
				//	g_customer.isGoInto = false;
				//}
				else {
					g_customer.isGoInto = true;
				}	
				if (j == MAX_STATUS - 1) {
					if ((GetRoad() + index)->way == MOVERIGHT) {
						g_customer.pos.x += 1;
					}
					if ((GetRoad() + index)->way == MOVELEFT) {
						g_customer.pos.x -= 1;
					}
					g_customer.speed = SPEED;
				}
			}
			//判断是否进入该建筑
			if (g_customer.isGoInto && (GetBuilding() + i)->type != BUILDING_TYPE_NULL) {
				g_customer.speed = 0;
				for (int j = 0; j < MAX_STATUS; j++)
				{
					if ((GetBuilding() + i)->type == BUILDING_TYPE_STORE && g_customer.isBuy == true)
					{
						gotoxy(logx, logy);
						printf("已经买过了.");
						msleep(750);
						printf(".");
						msleep(750);
						printf(".");
						msleep(500);
						clearLog();
						if ((GetRoad() + index)->way == MOVERIGHT) {
							g_customer.pos.x += 1;
						}
						if ((GetRoad() + index)->way == MOVELEFT) {
							g_customer.pos.x -= 1;
						}
						break;
					}
					//状态和金钱处理
					if (g_customer.status[j] == (GetBuilding() + i)->buff && g_customer.money >= (GetBuilding() + i)->money) {
						msleep(500);
						if ((GetRoad() + index)->way == MOVERIGHT) {
							g_customer.pos.x += 1;
						}
						if ((GetRoad() + index)->way == MOVELEFT) {
							g_customer.pos.x -= 1;
						}
						GoInto();
						g_customer.status[j] = (GetBuilding() + i)->debuff;
						g_customer.money -= (GetBuilding() + i)->money;	
						if ((GetBuilding() + i)->type == BUILDING_TYPE_STORE) {
							g_customer.isBuy = true;
							break;
						}
					}
				}
				g_customer.speed = SPEED;
			}
			
		}
	}

}
//g_customer.pos.y += g_customer.speed;	


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

	//顾客状态的显示
	gotoxy(108, 33);
	printf("顾客");
	gotoxy(108, 35);
	printf("顾客所持有的金钱: ￥%d", g_customer.money);
	gotoxy(108, 37);
	printf("顾客状态: ");
	for (int i = 0; i < MAX_STATUS; i++)
	{
		switch (g_customer.status[i])
		{
		case HUNGRY:
			printf("饥饿 ");
			break;
		case BORING:
			printf("无聊 ");
			break;
		case TIRED:
			printf("疲劳 ");
			break;
		case THIRST:
			printf("口渴 ");
			break;
		default:
			break;
		}
	}

	//结算界面绘制
	/*if (g_customer.isEnd)
	{	
		
	}
	gotoxy(64, 17);
	printf("┏");
	for (int i = 0; i < 16; i++)
	{
		printf("━");
	}
	printf("┓");
	for (int i = 1; i < 6; i++) {
		gotoxy(64, 18 + i);
		printf("┃");
	}
	for (int i = 1; i < 8; i++) {
		gotoxy(80, 18 + i);
		printf("┃");
	}
	gotoxy(64, 23);
	printf("┗");
	for (int i = 0; i < 16; i++) {
		printf("━");
	}
	printf("┛");*/
}

void SetCustomer(int money, int status0, int status1, int status2, int status3)
{
	g_customer.money = money;
	g_customer.status[0] = status0;
	g_customer.status[1] = status1;
	g_customer.status[2] = status2;
	g_customer.status[3] = status3;
}

CUSTOMER* GetCustomer(void)
{
	return &g_customer;
}

void GoInto(void) 
{
	textattr(0xF0);

	gotoxy((int)g_customer.oldpos.x, (int)g_customer.oldpos.y + 1);
	printf("  ");

	gotoxy((int)g_customer.oldpos.x, (int)g_customer.oldpos.y + 2);
	printf("  ");

	gotoxy((int)g_customer.oldpos.x, (int)g_customer.oldpos.y + 3);
	printf("  ");

	textattr(0x0F);

	msleep(1500);
	playsound(money, 0);
	gotoxy(108, 35);
	printf("顾客所持有的金钱: ￥         ");
	gotoxy(108, 37);
	printf("顾客状态:                    ");
}
