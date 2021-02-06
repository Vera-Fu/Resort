//=================================================
// [アクションサンプル]
// main.cpp
// author:**** ****	
// Date:2021/**/**
//=================================================

#include "map.h"

#define CONIOEX
#include "conioex.h"

#define MAPWIDTH_MAX 100
#define MAPHEIGHT_MAX 40


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
	//游戏界面
	textattr(0xFF);	
	for (int i = 1; i < MAPWIDTH_MAX; i++){
		gotoxy(i, MAPHEIGHT_MAX);
		printf(" ");
	}	
	for (int i = 0; i < MAPHEIGHT_MAX; i++){
		gotoxy(MAPWIDTH_MAX, i);
		printf(" ");
	}

	//旅馆主体
	textattr(0x44);
	for (int i = 11; i < 17; i++){
		gotoxy(5, i);
		for (int j = 0; j < 7; j++) {
			printf(" ");
		}
	}
	//旅馆窗户
	textattr(0x33);
	gotoxy(6, 12);
	printf("  ");
	gotoxy(9, 12);
	printf("  ");
	gotoxy(6, 14);
	printf("  ");
	gotoxy(9, 14);
	printf("  ");

	//旅馆大门
	textattr(0xFF);
	gotoxy(7, 16);
	printf("   ");
	
	//沙滩
	
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
		//データ範囲外だったら空白を表示する

		
	/*for (int i = 80; i < 90; i++){
		for (int j = 5; j < 25; j++) {

			gotoxy(i, j);
			printf(" ");
		}
	}*/
	//海
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
