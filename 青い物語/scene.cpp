#include "scene.h"

#define CONIOEX
#include "conioex.h"

int g_scene = TITLESCENE;

int GetScene(void)
{
	return g_scene;
}

void SetScene(int scene)
{
	g_scene = scene;
}

void ClearScene(void)
{
	textattr(0x0F);
	gotoxy(1, 1);
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 143; j++)
		{
			printf("-");
		}
		printf("\n");
		msleep(20);
	}
	//gotoxy(1, 1);
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 143; j++)
		{
			printf(" ");
		}
		printf("\n");
		msleep(20);
	}
	clrscr();
}
