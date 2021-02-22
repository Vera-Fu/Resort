//=================================================
// [¥ê¥¾©`¥È¤Î¥ï¥Ê]
// score.cpp
// author:fuyizhi
// Date:2021/02/17
//=================================================

#include "score.h"

#define CONIOEX
#include "conioex.h"

int star;
bool isStarShow;
bool isClear;

int starSound;
int winSound;
int failSound;

static unsigned char g_star_data[] = {
	0,0,1,1,0,0,
	1,1,1,1,1,1,
	0,1,1,1,1,0,
	1,1,0,0,1,1,
};

void InitScore(void)
{
	starSound = opensound((char*)"sound\\star.mp3");
	winSound = opensound((char*)"sound\\win.mp3");
	failSound = opensound((char*)"sound\\fail.mp3");
	isStarShow = false;
}

void UnInitScore(void)
{
	closesound(starSound);
	closesound(winSound);
	closesound(failSound);
	ClearScene();
}

void UpdateScore(void)
{
	if (GetCustomer()->isEnd)
	{
		for (int i = 0; i < MAX_STATUS; i++)
		{
			if (GetCustomer()->status[i] != NOTHING)
			{
				isClear = false;
				break;
			}
			else {
				if (i == MAX_STATUS - 1) {
					isClear = true;
				}
			}
		}
		if (!isClear && GetCustomer()->money > 0)
		{
			star = 0;
		}
		if (!isClear && GetCustomer()->money == 0)
		{
			star = 1;
		}
		if (isClear && GetCustomer()->money > 0)
		{
			star = 2;
		}
		if (isClear && GetCustomer()->money == 0)
		{
			star = 3;
		}
		if ((GetLevelChoose() + GetLevelIndex() - 1)->star < star)
		{
			(GetLevelChoose() + GetLevelIndex() - 1)->star = star;
			unsigned char level_count = MAX_LEVEL;
			FILE* fp = fopen("level.bin", "wb");
			fwrite(&level_count, sizeof(level_count), 1, fp);
			fwrite(GetLevelChoose(), sizeof(*GetLevelChoose()), level_count, fp);
			fclose(fp);
		}	
		isStarShow = true;
	}
}

void DrawScore(void)
{
	if (isStarShow) {
		switch (star)
		{
		case 0:
			GetChoose()->isShow = false;
			clearMenu();
			msleep(500);
			playsound(failSound, 0);
			msleep(3500);
			isStarShow = false;
			break;
		case 1:
			GetChoose()->isShow = false;
			clearMenu();
			PrintStar(120, 3);
			break;
		case 2:
			GetChoose()->isShow = false;
			clearMenu();
			PrintStar(120, 3);
			PrintStar(120, 8);
			break;
		case 3:
			GetChoose()->isShow = false;
			clearMenu();
			PrintStar(120, 3);
			PrintStar(120, 8);
			PrintStar(120, 13);
			msleep(200);
			playsound(winSound, 0);
			msleep(3000);
			break;
		default:
			break;
		}
		SetScene(LEVELCHOOSESCENE);
	}
	
}

void PrintStar(int x, int y)
{
	msleep(500);
	playsound(starSound, 0);
	for (int i = x; i < x + 6; i++) {
		for (int j = y; j < y + 4; j++) {
			gotoxy(i, j);
			switch (g_star_data[(i - x) + 6 * (j - y)])
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
	msleep(500);
	isStarShow = false;
}
