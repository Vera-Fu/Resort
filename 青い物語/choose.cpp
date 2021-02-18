//=================================================
// [リゾートのワナ]
// choose.cpp
// author:fuyizhi
// Date:2021/02/06
//=================================================

#include "choose.h"

#define CONIOEX
#include "conioex.h"

CHOOSE g_choose;

BUILDING* g_buliding = GetBuilding();

int choosebuttonSound = opensound((char*)"sound\\button02.mp3");

void InitChoose(void)
{
	g_choose.pos.x = 0;
	g_choose.pos.y = 0;
	g_choose.oldpos.x = g_choose.pos.x;
	g_choose.oldpos.y = g_choose.pos.y;
	g_choose.index = 0;
	g_choose.isPush = false;
	g_choose.isStart = false;
	g_choose.isShow = false;

	SetChoose(g_buliding->pos.x + 2, g_buliding->pos.y - 1);
}

void UnInitChoose(void)
{

}

void UpdateChoose(void)
{
	g_choose.oldpos.x = g_choose.pos.x;
	g_choose.oldpos.y = g_choose.pos.y;

	//控制光标的移动
	if (inport(PK_RIGHT)) {
		if (!g_choose.isPush)
		{
			g_choose.isPush = true;
			if (g_choose.index < GetMaxIndex())
			{
				playsound(choosebuttonSound, 0);	
				g_choose.index++;
				SetChoose((g_buliding + g_choose.index)->pos.x + 2, (g_buliding + g_choose.index)->pos.y - 1);
			}
			if (g_choose.isStart)
			{
				clearMenu();
				g_choose.isShow = true;
			}
		}	
	} else if (inport(PK_LEFT)) {
		if (!g_choose.isPush)
		{
			g_choose.isPush = true;
			if (g_choose.index > 0){
				playsound(choosebuttonSound, 0);
				g_choose.index--;
				SetChoose((g_buliding + g_choose.index)->pos.x + 2, (g_buliding + g_choose.index)->pos.y - 1);
			}
			if (g_choose.isStart)
			{
				clearMenu();
				g_choose.isShow = true;
			}
		}		
	} 
	else {
		g_choose.isPush = false;
	}
}

void DrawChoose(void)
{
	textattr(0x0F);
	gotoxy(g_choose.oldpos.x - 4, g_choose.oldpos.y - 1);
	printf("           ");

	gotoxy(g_choose.oldpos.x, g_choose.oldpos.y);
	printf("  ");

	gotoxy(g_choose.pos.x, g_choose.pos.y);
	printf("▼");
	
	if (!(g_buliding + g_choose.index)->isRemoveable)
	{
		gotoxy(g_choose.pos.x - 4, g_choose.pos.y - 1);
		printf("(不可拆除)");
	}

	//当开始关卡后，显示光标所指的建筑的信息
	if (g_choose.isStart && g_choose.isShow)
	{
		gotoxy(112, 3);
		switch ((g_buliding + g_choose.index)->type)
		{
		case BUILDING_TYPE_SPA:
			printf("建筑名称: 温泉");
			gotoxy(112, 5);
			printf("建筑收费: ￥%d", BUILDING_MONEY_SPA);
			gotoxy(112, 7);
			printf("建筑描述: 疲劳↓ 饥饿↑");
			break;
		case BUILDING_TYPE_CONVENIENCE:
			printf("建筑名称: 便利店");
			gotoxy(112, 5);
			printf("建筑收费: ￥%d", BUILDING_MONEY_CONVENIENCE);
			gotoxy(112, 7);
			printf("建筑描述: 口渴↓");
			break;
		case BUILDING_TYPE_RESTAURANT:
			printf("建筑名称: 餐馆");
			gotoxy(112, 5);
			printf("建筑收费: ￥%d", BUILDING_MONEY_RESTAURANT);
			gotoxy(112, 7);
			printf("建筑描述: 饥饿↓");
			break;
		case BUILDING_TYPE_MASSAGE:
			printf("建筑名称: 按摩店");
			gotoxy(112, 5);
			printf("建筑收费: ￥%d", BUILDING_MONEY_MASSAGE);
			gotoxy(112, 7);
			printf("建筑描述: 疲劳↓");
			break;
		case BUILDING_TYPE_SING:
			printf("建筑名称: 卡拉OK");
			gotoxy(112, 5);
			printf("建筑收费: ￥%d", BUILDING_MONEY_SING);
			gotoxy(112, 7);
			printf("建筑描述: 无聊↓ 口渴↑");
			break;
		case BUILDING_TYPE_POKER:
			printf("建筑名称: 棋牌室");
			gotoxy(112, 5);
			printf("建筑收费: ￥%d", BUILDING_MONEY_POKER);
			gotoxy(112, 7);
			printf("建筑描述: 无聊↓");
			break;
		case BUILDING_TYPE_STORE:
			printf("建筑名称: 特产店");
			gotoxy(112, 5);
			printf("建筑收费: ￥%d", BUILDING_MONEY_STORE);
			gotoxy(112, 7);
			printf("建筑描述: 瞧一瞧看一看！");
			break;
		default:
			/*clearMenu();*/
			
			break;
		}
		g_choose.isShow = false;
	}
}

void SetChoose(int posx, int posy)
{
	g_choose.pos.x = posx;
	g_choose.pos.y = posy;
}

CHOOSE* GetChoose()
{
	return &g_choose;
}

void clearMenu(void)
{
	for (int i = 0; i <= 17; i++) {
		textattr(0x0F);
		gotoxy(112, 2 + i);
		printf("                       ");
	}
}
