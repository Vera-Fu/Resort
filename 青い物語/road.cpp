//=================================================
// [¥ê¥¾©`¥È¤Î¥ï¥Ê]
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
	for (int i = 0; i < MAX_ROAD; i++) {
		g_road[i].start_pos.x = 0;
		g_road[i].start_pos.y = 0;
		g_road[i].end_pos.x = 0;
		g_road[i].end_pos.y = 0;
		g_road[i].way = 0;
		g_road[i].isUse = false;
	}
	SetRoad(ROAD_START0_X, ROAD_START0_Y, 80, 20, MOVERIGHT);
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
			if(g_road[i].way == MOVERIGHT || g_road[i].way == MOVEDOWN)
			for (int x = g_road[i].start_pos.x; x < g_road[i].end_pos.x; x++) {
				for (int y = g_road[i].start_pos.y; y < g_road[i].end_pos.y; y++) {					
					textattr(0xFF);
					gotoxy(x, y);
					printf(" ");
				}
			}
			if (g_road[i].way == MOVELEFT || g_road[i].way == MOVEUP)
				for (int x = g_road[i].start_pos.x; x > g_road[i].end_pos.x; x--) {
					for (int y = g_road[i].start_pos.y; y > g_road[i].end_pos.y; y--) {
						textattr(0xFF);
						gotoxy(x, y);
						printf(" ");
					}
				}
			g_road[i].isUse = false;
		}
	}

}

void SetRoad(int startposx, int startposy, int endposx, int endposy, int way)
{
	for (int i = 0; i < MAX_ROAD; i++) {
		if (!g_road->isUse) {
			g_road->start_pos.x = startposx;
			g_road->start_pos.y = startposy;
			g_road->end_pos.x = endposx;
			g_road->end_pos.y = endposy;
			g_road->way = way;
			g_road->isUse = true;
			break;
		}
	}
}
