//=================================================
// [¥ê¥¾©`¥È¤Î¥ï¥Ê]
// building.cpp
// author:fuyizhi
// Date:2021/02/08
//=================================================

#include "building.h"

#define CONIOEX
#include "conioex.h"

BUILDING g_building[MAX_BUILDING];

static int MAX_INDEX;

void InitBuilding(void)
{
	for (int i = 0; i < MAX_BUILDING; i++) {
		g_building[i].pos.x = 0;
		g_building[i].pos.y = 0;
		g_building[i].type = BUILDING_TYPE_NONE;
		g_building[i].isRemoveable = true;

		g_building[i].buff = NOTHING;
		g_building[i].debuff = NOTHING;
		g_building[i].money = 0;
	}
}

void UnInitBuilding(void)
{
}

void UpdateBuilding(void)
{
	for (int i = 0; i < MAX_BUILDING; i++)
	{
		switch (g_building[i].type) {
		case BUILDING_TYPE_NULL:
			g_building[i].debuff = NOTHING;
			g_building[i].buff = NOTHING;
			g_building[i].money = 0;
			break;
		case BUILDING_TYPE_SPA:
			g_building[i].debuff = HUNGRY;
			g_building[i].buff = TIRED;
			g_building[i].money = BUILDING_MONEY_SPA;
			break;
		case BUILDING_TYPE_CONVENIENCE:
			g_building[i].debuff = NOTHING;
			g_building[i].buff = THIRST;
			g_building[i].money = BUILDING_MONEY_CONVENIENCE;
			break;
		case BUILDING_TYPE_RESTAURANT:
			g_building[i].debuff = BORING;
			g_building[i].buff = HUNGRY;
			g_building[i].money = BUILDING_MONEY_RESTAURANT;
			break;
		case BUILDING_TYPE_MASSAGE:
			g_building[i].debuff = NOTHING;
			g_building[i].buff = TIRED;
			g_building[i].money = BUILDING_MONEY_MASSAGE;
			break;
		case BUILDING_TYPE_SING:
			g_building[i].debuff = THIRST;
			g_building[i].buff = BORING;
			g_building[i].money = BUILDING_MONEY_SING;
			break;
		case BUILDING_TYPE_POKER:
			g_building[i].debuff = NOTHING;
			g_building[i].buff = BORING;
			g_building[i].money = BUILDING_MONEY_POKER;
			break;
		case BUILDING_TYPE_STORE:
			g_building[i].debuff = NOTHING;
			g_building[i].buff = NOTHING;
			g_building[i].money = BUILDING_MONEY_STORE;
			break;
		case BACK:
			break;
		default:
			break;
		}
	}
	
}

void DrawBuilding(void)
{
	for (int i = 0; i < MAX_BUILDING; i++) {
		if (g_building[i].type != BUILDING_TYPE_NONE)
		{
			gotoxy(g_building[i].pos.x, g_building[i].pos.y);
			switch (g_building[i].type)
			{
			case BUILDING_TYPE_NULL:
				textattr(0x08);
				printf("¨¡ö¨Ž");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 1);
				textattr(0x88);
				printf("      ");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 2);
				printf("      ");
				gotoxy(g_building[i].pos.x + 2, g_building[i].pos.y + 2);
				textattr(0x77);
				printf("  ");
				break;
			case BUILDING_TYPE_SPA:
				textattr(0x0C);
				printf("¨¡ö¨Ž");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 1);
				textattr(0x44);
				printf("      ");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 2);
				printf("      ");
				gotoxy(g_building[i].pos.x + 2, g_building[i].pos.y + 2);
				textattr(0xFF);
				printf("  ");
				break;
			case BUILDING_TYPE_CONVENIENCE:
				textattr(0x0F);
				printf("¨¡ö¨Ž");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 1);
				textattr(0x77);
				printf("      ");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 2);
				printf("      ");
				gotoxy(g_building[i].pos.x + 2, g_building[i].pos.y + 2);
				textattr(0xFF);
				printf("  ");
				break;
			case BUILDING_TYPE_RESTAURANT:
				textattr(0x0F);
				printf("¨¡ö¨Ž");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 1);
				textattr(0xEE);
				printf("      ");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 2);
				printf("      ");
				gotoxy(g_building[i].pos.x + 2, g_building[i].pos.y + 2);
				textattr(0xFF);
				printf("  ");
				break;
			case BUILDING_TYPE_MASSAGE:
				textattr(0x0C);
				printf("¨¡ö¨Ž");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 1);
				textattr(0x66);
				printf("      ");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 2);
				printf("      ");
				gotoxy(g_building[i].pos.x + 2, g_building[i].pos.y + 2);
				textattr(0xFF);
				printf("  ");
				break;
			case BUILDING_TYPE_SING:
				textattr(0x0C);
				printf("¨¡ö¨Ž");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 1);
				textattr(0xDD);
				printf("      ");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 2);
				printf("      ");
				gotoxy(g_building[i].pos.x + 2, g_building[i].pos.y + 2);
				textattr(0xFF);
				printf("  ");
				break;
			case BUILDING_TYPE_POKER:
				textattr(0x04);
				printf("¨¡ö¨Ž");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 1);
				textattr(0x55);
				printf("      ");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 2);
				printf("      ");
				gotoxy(g_building[i].pos.x + 2, g_building[i].pos.y + 2);
				textattr(0xFF);
				printf("  ");
				break;
			case BUILDING_TYPE_STORE:
				textattr(0x07);
				printf("¨¡ö¨Ž");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 1);
				textattr(0x22);
				printf("      ");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 2);
				printf("      ");
				gotoxy(g_building[i].pos.x + 2, g_building[i].pos.y + 2);
				textattr(0xFF);
				printf("  ");
				break;
			default:
				break;
			}
			//¥²©`¥È¤òÃè¤¯
			textattr(0xFF);
			gotoxy(g_building[i].pos.x + 1, g_building[i].pos.y + 3);
			printf("    ");
		}		
	}



}

void SetBuilding(int posx, int posy, int type)
{
	int index = 0;
	for (int i = 0; i < MAX_BUILDING; i++) {
		if (g_building[i].type == BUILDING_TYPE_NONE)
		{
			g_building[i].pos.x = posx;
			g_building[i].pos.y = posy;
			g_building[i].type = type;
			g_building[i].index = index;

			if (g_building[i].type == BUILDING_TYPE_NULL) {
				g_building[i].isRemoveable = true;
			}
			else
			{
				g_building[i].isRemoveable = false;
			}
			
			MAX_INDEX = index;
			break;
		}
		index++;
	}
}

BUILDING* GetBuilding(void) 
{
	return g_building;
}

int GetMaxIndex(void) 
{
	return MAX_INDEX;
}
