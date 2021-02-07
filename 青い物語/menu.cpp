#include "menu.h"

#define CONIOEX
#include "conioex.h"

int g_index0 = 0;	//值等于1时，绘制第一个菜单；值等于2时，绘制第二个菜单,值等于3时，绘制第三个菜单
int g_index1 = 0;	//控制第一个菜单的绘制
int g_index2 = 0;
int g_index3 = 0;
bool g_isPush = false;

enum Menu0
{
	MENU1,
	MENU2,
	MENU3
};

enum Menu1
{
	BUILD,
	REMOVE,
	TITLE
};

enum Menu2
{
	YES,
	NO
};

void InitMenu(void)
{
	textattr(0x0F);
	gotoxy(110, 1);
	//highvideo();
	printf("┏");
	for (int i = 0; i < 25; i++) {
		printf("━");
	}
	gotoxy(135, 1);
	printf("┓");	
	for (int i = 1; i < 20; i++) {
		gotoxy(110, 1 + i);
		printf("┃");
	}
	for (int i = 1; i < 20; i++) {
		gotoxy(135, 1 + i);
		printf("┃");
	}
	gotoxy(110, 21);
	printf("┗");
	for (int i = 0; i < 25; i++) {
		printf("━");
	}
	gotoxy(135, 21);
	printf("┛");
}

void UnInitMenu(void)
{
}

void UpdateMenu(void)
{
	//菜单1的处理
	if (g_index0 == MENU1)
	{
		if (inport(PK_UP)) {
			if (!g_isPush)
			{
				g_isPush = true;
				g_index1--;
				if (g_index1 < BUILD) {
					g_index1 = TITLE;
				}
			}
		}
		else if (inport(PK_DOWN)) {
			if (!g_isPush)
			{
				g_isPush = true;
				g_index1++;
				if (g_index1 > TITLE) {
					g_index1 = BUILD;
				}
			}
		}
		else if (inport(PK_ENTER)) {
			if (!g_isPush)
			{
				g_isPush = true;
				if (g_index0 == MENU1)
				{
					g_index0 = MENU2;
				}
			}

		}
		else {
			g_isPush = false;
		}
	}

	//菜单2的处理
	if (g_index0 == MENU2)
	{
		if (inport(PK_UP)) {
			if (!g_isPush)
			{
				g_isPush = true;
				g_index2--;
				if (g_index2 < YES) {
					g_index2 = NO;
				}
			}
		}
		else if (inport(PK_DOWN)) {
			if (!g_isPush)
			{
				g_isPush = true;
				g_index2++;
				if (g_index2 > NO) {
					g_index2 = YES;
				}
			}
		}
		else if (inport(PK_ENTER)) {
			if (!g_isPush)
			{
				g_isPush = true;
				if (g_index0 == MENU2 && g_index2 == NO)
				{
					g_index0 = MENU1;
				}
			}

		}
		else {
			g_isPush = false;
		}
	}
	
}

void DrawMenu(void)
{
	if (g_index0 == MENU1)
	{
		switch (g_index1)
		{
		case BUILD:
			gotoxy(119, 5);
			printf("        ");
			textattr(0x70);
			gotoxy(121, 5);
			printf("建造");
			textattr(0x0F);
			gotoxy(121, 10);
			printf("拆除");
			gotoxy(119, 15);
			printf("回到标题");
			break;
		case REMOVE:
			gotoxy(119, 5);
			printf("        ");
			textattr(0x0F);
			gotoxy(121, 5);
			printf("建造");			
			textattr(0x70);
			gotoxy(121, 10);
			printf("拆除");
			textattr(0x0F);
			gotoxy(119, 15);
			printf("回到标题");
			break;
		case TITLE:
			gotoxy(119, 5);
			printf("        ");
			textattr(0x0F);
			gotoxy(121, 5);
			printf("建造");
			gotoxy(121, 10);
			printf("拆除");
			textattr(0x70);
			gotoxy(119, 15);
			printf("回到标题");
			textattr(0x0F);
			break;
		default:
			break;
		}
	}
	if (g_index0 == MENU2)
	{
		switch (g_index2)
		{
		case YES:
			gotoxy(119, 15);
			printf("        ");
			textattr(0x0F);
			gotoxy(119, 5);			
			printf("确定吗？");			
			textattr(0x70);
			gotoxy(121, 10);
			printf("确定");
			textattr(0x0F);
			gotoxy(121, 15);
			printf("取消");
			break;
		case NO:
			gotoxy(119, 15);
			printf("        ");
			textattr(0x0F);			
			gotoxy(119, 5);
			printf("确定吗？");			
			gotoxy(121, 10);
			printf("确定");
			textattr(0x70);
			gotoxy(121, 15);
			printf("取消");
			textattr(0x0F);
			break;
		default:
			break;
		}
	}

}

void SetMenu(int posx, int posy)
{
}

int GetMenu()
{
	return 0;
}
