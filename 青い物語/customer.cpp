//=================================================
// [�꥾�`�ȤΥ��]
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
	
	//SetCustomer(2000, HUNGRY);
}

void UnInitCustomer(void)
{
}

void UpdateCustomer(void)
{
	//1�ե�`��ǰ��λ�ä򱣴�
	g_customer.oldpos.x = g_customer.pos.x;
	g_customer.oldpos.y = g_customer.pos.y;

	//λ�äθ���
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
		case NONE:
			break;
		default:
			break;
		}
	}	
	for (int i = 0; i < MAX_BUILDING; i++)
	{
		//������ײ���
		if ((int)g_customer.pos.x == (GetBuilding() + i)->pos.x + 3 && (int)g_customer.pos.y == (GetBuilding() + i)->pos.y + 3) {
			g_customer.speed = 0;
			for (int j = 0; j < MAX_STATUS; j++)
			{
				//�����жϸý����Ƿ����˿ͼ���׷���������е�״̬������ᣬ�򲻽���
				if (g_customer.status[i] == (GetBuilding() + i)->debuff && g_customer.status[i] != NOTHING)
				{
					g_customer.isGoInto = false;
					g_customer.speed = SPEED;
					break;
				}
				////�����жϸý����Ƿ��������˿��������е�״̬��������ᣬ�򲻽���
				//else if (g_customer.status[i] != (GetBuilding() + i)->buff) {
				//	g_customer.isGoInto = false;
				//}
				else {
					g_customer.isGoInto = true;
				}	
				if (j == MAX_STATUS - 1) {
					g_customer.speed = SPEED;
				}
			}
			//�ж��Ƿ����ý���
			if (g_customer.isGoInto && (GetBuilding() + i)->type != BUILDING_TYPE_NULL ) {
				g_customer.speed = 0;
				for (int j = 0; j < MAX_STATUS; j++)
				{
					//״̬�ͽ�Ǯ����
					if (g_customer.status[j] == (GetBuilding() + i)->buff && g_customer.money >= (GetBuilding() + i)->money) {
						msleep(1000);
						if ((GetRoad() + index)->way == MOVERIGHT) {
							g_customer.pos.x += 1;
						}
						if ((GetRoad() + index)->way == MOVELEFT) {
							g_customer.pos.x -= 1;
						}
						GoInto();
						msleep(2000);
						playsound(money, 0);
						g_customer.status[j] = (GetBuilding() + i)->debuff;
						g_customer.money -= (GetBuilding() + i)->money;	
						if ((GetBuilding() + i)->type == BUILDING_TYPE_STORE) {
							break;
						}
					}
				}
				g_customer.speed = SPEED;
			}
			
						
			gotoxy(118, 26);
			printf("index=%d", (GetBuilding() + i)->type);
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
	printf("��");

	gotoxy((int)g_customer.oldpos.x, (int)g_customer.oldpos.y + 2);
	printf("  ");
	gotoxy((int)g_customer.pos.x, (int)g_customer.pos.y + 2);
	printf("��");

	gotoxy((int)g_customer.oldpos.x, (int)g_customer.oldpos.y + 3);
	printf("  ");
	gotoxy((int)g_customer.pos.x, (int)g_customer.pos.y + 3);
	printf("��");
	textattr(0x0F);

	//----------------
	gotoxy(118, 27);
	printf("money=%d", g_customer.money);
	gotoxy(118, 28);
	printf("status0=%d", g_customer.status[0]);
	gotoxy(118, 29);
	printf("status1=%d", g_customer.status[1]);
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
}
