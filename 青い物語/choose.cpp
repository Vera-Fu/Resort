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
}

void SetChoose(int posx, int posy)
{
	g_choose.pos.x = posx;
	g_choose.pos.y = posy;
}

CHOOSE GetChoose()
{
	return g_choose;
}

void clearMenu(void)
{
	for (int i = 0; i <= 17; i++) {
		textattr(0x0F);
		gotoxy(115, 2 + i);
		printf("                    ");
	}
}
