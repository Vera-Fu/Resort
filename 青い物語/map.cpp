//=================================================
// [¥ê¥¾©`¥È¤Î¥ï¥Ê]
// map.cpp
// author:fuyizhi
// Date:2021/02/05
//=================================================

#include "map.h"

#define CONIOEX
#include "conioex.h"

HOTEL g_hotel;

static unsigned char g_sandmap_data[] = {
	0, 0 ,0, 0, 0, 1, 1, 1, 1, 1,
	0, 0 ,0, 0, 1, 1, 1, 1, 1, 1,
	0, 0 ,0, 0, 1, 1, 1, 1, 1, 1,
	0, 0 ,0, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,0, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,0, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	1, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 1 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,1, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,0, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,0, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,0, 1, 1, 1, 1, 1, 1, 1,
	0, 0 ,0, 0, 1, 1, 1, 1, 1, 1,
	0, 0 ,0, 0, 1, 1, 1, 1, 1, 1,
	0, 0 ,0, 0, 0, 1, 1, 1, 1, 1,
};

void InitMap(void)
{
	//¥²©`¥à¤Î¹ ‡ì
	textattr(0xFF);	
	for (int i = 1; i < MAPWIDTH_MAX; i++){
		gotoxy(i, MAPHEIGHT_MAX);
		printf(" ");
	}	
	for (int i = 0; i < MAPHEIGHT_MAX; i++){
		gotoxy(MAPWIDTH_MAX, i);
		printf(" ");
	}
	if (GetLevelIndex() < 8) {
		SetHotel(5, 11);
	}
	else {
		SetHotel(5, 17);
	}
	

	//ÂÃð^¤ÎÖ÷Ìå
	textattr(0x44);
	for (int i = g_hotel.pos.y; i < g_hotel.pos.y + 6; i++){
		gotoxy(g_hotel.pos.x, i);
		for (int j = 0; j < 7; j++) {
			printf(" ");
		}
	}
	//ÂÃ¹Ý¤Î·™
	textattr(0x33);
	gotoxy(g_hotel.pos.x + 1, g_hotel.pos.y + 1);
	printf("  ");
	gotoxy(g_hotel.pos.x + 4, g_hotel.pos.y + 1);
	printf("  ");
	gotoxy(g_hotel.pos.x + 1, g_hotel.pos.y + 3);
	printf("  ");
	gotoxy(g_hotel.pos.x + 4, g_hotel.pos.y + 3);
	printf("  ");

	//ÂÃ¹Ý¤Î¥²©`¥È
	textattr(0xFF);
	gotoxy(g_hotel.pos.x + 2, g_hotel.pos.y + 5);
	printf("   ");
	
	//É°äº	
	for (int i = 80; i < 90; i++) {
		for (int j = 1; j < MAPHEIGHT_MAX; j++) {
			gotoxy(i, j);
			switch (g_sandmap_data[(i - 80) + 10 * j])
			{
			case 0:
				textattr(0x00);
				printf(" ");
				break;
			case 1:
				textattr(0xEE);				
				printf(" ");
				break;
			}
		}
	}

	//º£
	textattr(0xBB);
	for (int i = 90; i < MAPWIDTH_MAX; i++) {
		for (int j = 1; j < MAPHEIGHT_MAX; j++) {
			gotoxy(i, j);
			printf(" ");
		}
	}
}

void UnInitMap(void)
{
}

void UpdateMap(void)
{
}

void DrawMap(void)
{
	
}

void SetHotel(int x, int y)
{
	g_hotel.pos.x = x;
	g_hotel.pos.y = y;
}

HOTEL GetHotel(void)
{
	return g_hotel;
}
