#include "title.h"

#define CONIOEX
#include "conioex.h"

static unsigned char g_title_data[] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	1,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,
	1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
	0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,
	0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
	0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,
	0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
};

static int g_index = STARTGAME;
static bool isPush;

static int menubuttonSound;
static int buttonpushSound;
static int bgm1;

void InitTitle(void)
{
	menubuttonSound = opensound((char*)"sound\\button01.mp3");
	buttonpushSound = opensound((char*)"sound\\buttonpush.mp3");
	bgm1 = opensound((char*)"sound\\bgm1.mp3");

	playsound(bgm1, 1);
	setvolume(bgm1, 15);
	
	isPush = false;
	//游戏标题绘制
	for (int i = 23; i < 123; i++) {
		for (int j = 5; j < 16; j++) {
			gotoxy(i, j);
			switch (g_title_data[(i - 23) + 100 * (j - 5)])
			{
			case 0:
				textattr(0x00);
				printf(" ");
				break;
			case 1:
				textattr(0xBB);
				printf(" ");
				break;
			}
		}
	}

	textattr(0x0F);
	gotoxy(55, 25);
	printf("┏");
	for (int i = 0; i < 35; i++) {
		printf("━");
	}
	gotoxy(90, 25);
	printf("┓");
	for (int i = 1; i < 8; i++) {
		gotoxy(55, 25 + i);
		printf("┃");
	}
	for (int i = 1; i < 8; i++) {
		gotoxy(90, 25 + i);
		printf("┃");
	}
	gotoxy(55, 33);
	printf("┗");
	for (int i = 0; i < 35; i++) {
		printf("━");
	}
	gotoxy(90, 33);
	printf("┛");

	//ゲームスタートとゲーム終了
	gotoxy(68, 27);
	printf("ゲーム開始");
	gotoxy(68, 31);
	printf("ゲーム終了");

	gotoxy(15, 21);
	textattr(0x08);
	printf("■■■");
	gotoxy(15, 22);
	textattr(0x88);
	printf("      ");
	gotoxy(15, 23);
	printf("      ");
	gotoxy(17, 23);
	textattr(0x77);
	printf("  ");

	gotoxy(30, 35);
	textattr(0x0C);
	printf("■■■");
	gotoxy(30, 36);
	textattr(0x44);
	printf("      ");
	gotoxy(30, 37);
	printf("      ");
	gotoxy(32, 37);
	textattr(0xFF);
	printf("  ");

	gotoxy(45, 21);
	textattr(0x0F);
	printf("■■■");
	gotoxy(45, 22);
	textattr(0xEE);
	printf("      ");
	gotoxy(45, 23);
	printf("      ");
	gotoxy(47, 23);
	textattr(0xFF);
	printf("  ");

	gotoxy(60, 35);
	textattr(0x0C);
	printf("■■■");
	gotoxy(60, 36);
	textattr(0xDD);
	printf("      ");
	gotoxy(60, 37);
	printf("      ");
	gotoxy(62, 37);
	textattr(0xFF);
	printf("  ");

	gotoxy(75, 21);
	textattr(0x04);
	printf("■■■");
	gotoxy(75, 22);
	textattr(0x55);
	printf("      ");
	gotoxy(75, 23);
	printf("      ");
	gotoxy(77, 23);
	textattr(0xFF);
	printf("  ");

	gotoxy(90, 35);
	textattr(0x07);
	printf("■■■");
	gotoxy(90, 36);
	textattr(0x23);
	printf("      ");
	gotoxy(90, 37);
	printf("      ");
	gotoxy(92, 37);
	textattr(0xFF);
	printf("  ");

	gotoxy(105, 21);
	textattr(0x0C);
	printf("■■■");
	gotoxy(105, 22);
	textattr(0x66);
	printf("      ");
	gotoxy(105, 23);
	printf("      ");
	gotoxy(107, 23);
	textattr(0xFF);
	printf("  ");

	gotoxy(121, 35);
	textattr(0x0F);
	printf("■■■");
	gotoxy(121, 36);
	textattr(0x77);
	printf("      ");
	gotoxy(121, 37);
	printf("      ");
	gotoxy(123, 37);
	textattr(0xFF);
	printf("  ");
}

void UnInitTitle(void)
{
	closesound(menubuttonSound);
	closesound(buttonpushSound);
	ClearScene();
}

void UpdateTitle(void)
{
	if (inport(PK_UP) || inport(PK_DOWN)) {
		if (!isPush)
		{
			playsound(menubuttonSound, 0);
			isPush = true;		
			if (g_index == STARTGAME) {
				g_index = ENDGAME;
			}
			else {
				g_index = STARTGAME;
			}
		}
	}
	else {
		isPush = false;
	}
	if (inport(PK_ENTER)) {
		playsound(buttonpushSound, 0);
		msleep(500);
		switch (g_index)
		{
		case STARTGAME:
			SetScene(LEVELCHOOSESCENE);
			break;
		case ENDGAME:
			SetScene(ENDSCENE);
			break;
		default:
			break;
		}
	}
}

void DrawTitle(void)
{
	textattr(0x0F);
	switch (g_index)
	{
	case STARTGAME:
		gotoxy(66, 27);
		printf("◆");
		gotoxy(78, 27);
		printf("◆");
		gotoxy(66, 31);
		printf("  ");
		gotoxy(78, 31);
		printf("  ");	
		break;
	case ENDGAME:
		gotoxy(66, 31);
		printf("◆");
		gotoxy(78, 31);
		printf("◆");
		gotoxy(66, 27);
		printf("  ");
		gotoxy(78, 27);
		printf("  ");
		
		break;
	default:
		break;
	}
	

}

int GetBgm(void)
{
	return bgm1;
}
