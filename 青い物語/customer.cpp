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
	
	//カスタマーは道の最後まで到着するかの判定
	if (g_customer.pos.x >= 80) {
		g_customer.isEnd = true;
	}

	textattr(0x0F);
	for (int i = 0; i < MAX_BUILDING; i++)
	{
		//当たり判定
		if ((int)g_customer.pos.x == (GetBuilding() + i)->pos.x + 3 && (int)g_customer.pos.y == (GetBuilding() + i)->pos.y + 3) {
			g_customer.speed = 0;
			for (int j = 0; j < MAX_STATUS; j++)
			{
				//この建築はカスタマーにデバフを追加するかの判定
				if (g_customer.status[j] == (GetBuilding() + i)->debuff && g_customer.status[j] != NOTHING)
				{
					switch ((GetBuilding() + i)->debuff)
					{
					case HUNGRY:
						gotoxy(logx, logy);
						printf("おなか減った.");
						msleep(750);
						printf(".");
						msleep(750);
						printf(".");
						msleep(500);
						clearLog();
						break;
					case BORING:
						gotoxy(logx, logy);
						printf("詰まらない.");
						msleep(750);
						printf(".");
						msleep(750);
						printf(".");
						msleep(500);
						clearLog();
						break;
					case TIRED:
						gotoxy(logx, logy);
						printf("疲れた.");
						msleep(750);
						printf(".");
						msleep(750);
						printf(".");
						msleep(500);
						clearLog();
						break;
					case THIRST:
						gotoxy(logx, logy);
						printf("喉が渇く.");
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
			//この建築に入るかの判定
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
					//ステータスとお金の処理
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

	//カスタマーのステータス
	gotoxy(108, 33);
	printf("カスタマー");
	gotoxy(108, 35);
	printf("持っているお金: ￥%d", g_customer.money);
	gotoxy(108, 37);
	printf("ステータス: ");
	for (int i = 0; i < MAX_STATUS; i++)
	{
		switch (g_customer.status[i])
		{
		case HUNGRY:
			printf("お腹すく ");
			break;
		case BORING:
			printf("詰まらない ");
			break;
		case TIRED:
			printf("疲労 ");
			break;
		case THIRST:
			printf("喉が渇く ");
			break;
		default:
			break;
		}
	}

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
	printf("持っているお金:            ");
	gotoxy(108, 37);
	printf("ステータス:                ");
}
