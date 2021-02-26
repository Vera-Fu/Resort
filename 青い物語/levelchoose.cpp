#include "levelchoose.h"

#define CONIOEX
#include "conioex.h"

LEVELCHOOSE g_levelchoose[MAX_LEVEL];

static int g_index;

static bool isPush;
static bool isClear;

static int levelchoosebutton;
static int buttonpushSound;

void InitLevelChoose(void)
{
	g_index = 0;
	isPush = false;
	isClear = true;
	levelchoosebutton = opensound((char*)"sound\\button02.mp3");
	buttonpushSound = opensound((char*)"sound\\buttonpush.mp3");
	for (int i = 0; i < MAX_LEVEL; i++)
	{
		g_levelchoose[i].star = 0;
		g_levelchoose[i].index = 0;
	}
	
	unsigned char level_count = MAX_LEVEL;
	FILE* fp = fopen("level.bin", "rb");
	if (fp == NULL)
	{
		SetLevelChoose(25, 10);
		SetLevelChoose(55, 10);
		SetLevelChoose(85, 10);
		SetLevelChoose(115, 10);
		SetLevelChoose(25, 20);
		SetLevelChoose(55, 20);
		SetLevelChoose(85, 20);
		SetLevelChoose(115, 20);
		SetLevelChoose(70, 30);
	}
	else
	{
		fread(&level_count, sizeof(level_count), 1, fp);
		fread(g_levelchoose, sizeof(*g_levelchoose), level_count, fp);
		fclose(fp);
	}
	
	textattr(0x0F);
	gotoxy(67, 5);
	for (int i = 0; i < MAX_LEVEL; i++) {
		if (g_levelchoose[i].star != 3)
		{
			isClear = false;
		}
	}
	if (isClear)
	{
		textattr(0x0A);
		printf("さ");
		textattr(0x0B);
		printf("す");
		textattr(0x0C);
		printf("が");
		textattr(0x0D);
		printf("だ");
		textattr(0x0E);
		printf("ね");
	}
	else
	{
		textattr(0x0F);
		printf("レベル選択");
	}
	
	
	for (int i = 0; i < MAX_LEVEL; i++)
	{
		textattr(0x0F);
		gotoxy(g_levelchoose[i].x, g_levelchoose[i].y);
		printf("%d", g_levelchoose[i].index);

		textattr(0x0E);
		gotoxy(g_levelchoose[i].x - 2, g_levelchoose[i].y + 2);		
		switch (g_levelchoose[i].star)
		{
		case 0:
			printf("☆ ☆ ☆");
			break;
		case 1:
			printf("★ ☆ ☆");
			break;
		case 2:
			printf("★ ★ ☆");
			break;
		case 3:
			printf("★ ★ ★");
			break;
		default:
			break;
		}
		textattr(0x0F);
	}
	gotoxy(g_levelchoose[0].x - 3, g_levelchoose[0].y);
	printf("【");
	gotoxy(g_levelchoose[0].x + 2, g_levelchoose[0].y);
	printf("】");
}

void UnInitLevelChoose(void)
{
	closesound(levelchoosebutton);
	closesound(buttonpushSound);
}

void UpdateLevelChoose(void)
{
	if (inport(PK_RIGHT)) {
		if (!isPush)
		{
			isPush = true;
			playsound(levelchoosebutton, 0);
			gotoxy(g_levelchoose[g_index].x - 3, g_levelchoose[g_index].y);
			printf("  ");
			gotoxy(g_levelchoose[g_index].x + 2, g_levelchoose[g_index].y);
			printf("  ");
			gotoxy(70, 35);
			printf("                     ");
			g_index += 1;
			if (g_index > MAX_LEVEL - 1) {
				g_index = 0;
			}
			gotoxy(g_levelchoose[g_index].x - 3, g_levelchoose[g_index].y);
			printf("【");
			gotoxy(g_levelchoose[g_index].x + 2, g_levelchoose[g_index].y);
			printf("】");
		}
		
	}
	else if (inport(PK_LEFT)) {
		if (!isPush) {
			isPush = true;
			playsound(levelchoosebutton, 0);
			gotoxy(g_levelchoose[g_index].x - 3, g_levelchoose[g_index].y);
			printf("  ");
			gotoxy(g_levelchoose[g_index].x + 2, g_levelchoose[g_index].y);
			printf("  ");
			gotoxy(62, 35);
			printf("                     ");
			g_index -= 1;
			if (g_index < 0) {
				g_index = MAX_LEVEL - 1;
			}
			gotoxy(g_levelchoose[g_index].x - 3, g_levelchoose[g_index].y);
			printf("【");
			gotoxy(g_levelchoose[g_index].x + 2, g_levelchoose[g_index].y);
			printf("】");
		}
		
	}
	else if (inport(PK_ENTER)) {
		if (!isPush) {
			isPush = true;
			if (g_index != 0)
			{
				if (g_levelchoose[g_index - 1].star == 0) {
					playsound(buttonpushSound, 0);
					textattr(0x0E);
					gotoxy(55, 35);
					printf("この前のレベルを完成してください！");
				}
				else {
					playsound(buttonpushSound, 0);
					ClearScene();
					SetScene(GAMESCENE);
				}
			}
			else {
				playsound(buttonpushSound, 0);
				ClearScene();
				SetScene(GAMESCENE);
			}
			
		}
	}
	else {
		isPush = false;
	}
}

void DrawLevelChoose(void)
{
}

void SetLevelChoose(int x, int y)
{
	for (int i = 0; i < MAX_LEVEL; i++)
	{
		if (g_levelchoose[i].index == 0) {
			g_levelchoose[i].index = i + 1;
			g_levelchoose[i].x = x;
			g_levelchoose[i].y = y;
			break;
		}
	}
}

LEVELCHOOSE* GetLevelChoose(void)
{
	return g_levelchoose;
}

int GetLevelIndex(void)
{
	return g_index + 1;
}
