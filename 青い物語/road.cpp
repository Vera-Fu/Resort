//=================================================
// [リゾートのワナ]
// road.cpp
// author:fuyizhi
// Date:2021/02/09
//=================================================

#include "road.h"

#define CONIOEX
#include "conioex.h"

ROAD g_road[MAX_ROAD];



void InitRoad(void)
{
	int g_startRoadX = GetHotel().pos.x;
	int g_startRoadY = GetHotel().pos.y + 6;
	for (int i = 0; i < MAX_ROAD; i++) {
		g_road[i].start_pos.x = 0;
		g_road[i].start_pos.y = 0;
		g_road[i].end_pos.x = 0;
		g_road[i].end_pos.y = 0;
		g_road[i].way = NONE;
		g_road[i].isUse = false;
	}

	/*SetRoad(80, MOVERIGHT);
	SetRoad(25, MOVEDOWN);
	
	SetRoad(50, MOVELEFT);*/
	
}

void UnInitRoad(void)
{
}

void UpdateRoad(void)
{
}

void DrawRoad(void)
{
	for (int i = 0; i < MAX_ROAD; i++) {
		if (g_road[i].isUse == true) {
			textattr(0xFF);
			switch (g_road[i].way)
			{
			case MOVEUP:
				for (int x = g_road[i].start_pos.x; x < g_road[i].end_pos.x; x++) {
					for (int y = g_road[i].start_pos.y; y > g_road[i].end_pos.y; y--) {						
						gotoxy(x, y);
						printf(" ");
					}
				}
				break;
			case MOVEDOWN:
				for (int x = g_road[i].start_pos.x; x < g_road[i].end_pos.x; x++) {
					for (int y = g_road[i].start_pos.y; y < g_road[i].end_pos.y; y++) {
						gotoxy(x, y);
						printf(" ");
					}
				}
				break;
			case MOVELEFT:
				for (int x = g_road[i].start_pos.x; x > g_road[i].end_pos.x; x--) {
					for (int y = g_road[i].start_pos.y; y < g_road[i].end_pos.y; y++) {
						gotoxy(x, y);
						printf(" ");
					}
				}
				break;
			case MOVERIGHT:
				for (int x = g_road[i].start_pos.x; x < g_road[i].end_pos.x; x++) {
					for (int y = g_road[i].start_pos.y; y < g_road[i].end_pos.y; y++) {
						gotoxy(x, y);
						printf(" ");
					}
				}
				break;
			default:
				break;
			}				
			g_road[i].isUse = false;
		}
	}

}


//先の道の最後から、次の道を描く
void SetRoad(int end,  int way)
{
	int g_startRoadX = GetHotel().pos.x;
	int g_startRoadY = GetHotel().pos.y + 6;
	for (int i = 0; i < MAX_ROAD; i++) {
		if ((g_road + i)->way == NONE) {
			(g_road + i)->way = way;
			(g_road + i)->isUse = true;
			if (i == 0) {
				(g_road + i)->start_pos.x = g_startRoadX;
				(g_road + i)->start_pos.y = g_startRoadY;
				(g_road + i)->end_pos.x = end;
				(g_road + i)->end_pos.y = g_startRoadY + 3;
			}
			else {
				switch ((g_road + i)->way)
				{
				case MOVEUP:
					if ((g_road + i - 1)->way == MOVERIGHT) {
						(g_road + i)->start_pos.x = (g_road + i - 1)->end_pos.x - 3;
						(g_road + i)->end_pos.x = (g_road + i - 1)->end_pos.x;
												
					}
					if ((g_road + i - 1)->way == MOVELEFT) {
						(g_road + i)->start_pos.x = (g_road + i - 1)->end_pos.x + 1;
						(g_road + i)->end_pos.x = (g_road + i - 1)->end_pos.x + 4;
					}
					(g_road + i)->start_pos.y = (g_road + i - 1)->end_pos.y - 4;
					(g_road + i)->end_pos.y = end;
					break;
				case MOVEDOWN:
					if ((g_road + i - 1)->way == MOVERIGHT) {
						(g_road + i)->start_pos.x = (g_road + i - 1)->end_pos.x - 3;
						(g_road + i)->end_pos.x = (g_road + i - 1)->end_pos.x;

					}
					if ((g_road + i - 1)->way == MOVELEFT) {
						(g_road + i)->start_pos.x = (g_road + i - 1)->end_pos.x + 1;
						(g_road + i)->end_pos.x = (g_road + i - 1)->end_pos.x + 4;
					}
					(g_road + i)->start_pos.y = (g_road + i - 1)->end_pos.y;
					(g_road + i)->end_pos.y = end;
					break;
				case MOVELEFT:
					if ((g_road + i - 1)->way == MOVEUP) {
						(g_road + i)->start_pos.y = (g_road + i - 1)->end_pos.y + 1;
						(g_road + i)->end_pos.y = (g_road + i - 1)->end_pos.y + 4;
					}
					if ((g_road + i - 1)->way == MOVEDOWN) {
						(g_road + i)->start_pos.y = (g_road + i - 1)->end_pos.y - 3;
						(g_road + i)->end_pos.y = (g_road + i - 1)->end_pos.y;
					}
					(g_road + i)->start_pos.x = (g_road + i - 1)->end_pos.x - 4;
					(g_road + i)->end_pos.x = end;
					break;
				case MOVERIGHT:
					if ((g_road + i - 1)->way == MOVEUP) {
						(g_road + i)->start_pos.y = (g_road + i - 1)->end_pos.y + 1;
						(g_road + i)->end_pos.y = (g_road + i - 1)->end_pos.y + 4;
					}
					if ((g_road + i - 1)->way == MOVEDOWN) {
						(g_road + i)->start_pos.y = (g_road + i - 1)->end_pos.y - 3;
						(g_road + i)->end_pos.y = (g_road + i - 1)->end_pos.y;
					}
					(g_road + i)->start_pos.x = (g_road + i - 1)->end_pos.x;
					(g_road + i)->end_pos.x = end;
					break;
				default:
					break;
				}				
			}		
			break;
		}
	}
}

ROAD* GetRoad(void)
{
	return g_road;
}
