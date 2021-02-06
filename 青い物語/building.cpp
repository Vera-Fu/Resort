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
		g_building[i].type = 0;
	}
	SetBuilding(25, 15);
	SetBuilding(35, 15);
	SetBuilding(35, 20);
	SetBuilding(50, 20);
}

void UnInitBuilding(void)
{
}

void UpdateBuilding(void)
{

}

void DrawBuilding(void)
{
	for (int i = 0; i < MAX_BUILDING; i++) {
		if (g_building[i].type != 0)
		{
			gotoxy(g_building[i].pos.x, g_building[i].pos.y);
			switch (g_building[i].type)
			{
			case 1:
				textattr(0x0C);
				printf("¨¡ö¨Ž");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 1);
				textattr(0x77);
				printf("      ");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 2);
				printf("      ");
				gotoxy(g_building[i].pos.x + 2, g_building[i].pos.y + 2);
				textattr(0xFF);
				printf("  ");

				/*textattr(0x0C);
				printf("¨¨Ž");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 1);
				textattr(0x77);
				printf("    ");
				gotoxy(g_building[i].pos.x, g_building[i].pos.y + 2);
				printf("    ");
				gotoxy(g_building[i].pos.x + 1, g_building[i].pos.y + 2);
				textattr(0xFF);
				printf("  ");*/
			default:
				break;
			}
		}		
	}
}

void SetBuilding(int posx, int posy)
{
	int index = 0;
	for (int i = 0; i < MAX_BUILDING; i++) {
		if (g_building[i].type == 0)
		{
			g_building[i].pos.x = posx;
			g_building[i].pos.y = posy;
			g_building[i].type = 1;
			g_building[i].index = index;
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
