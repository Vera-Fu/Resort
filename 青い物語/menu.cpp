#include "menu.h"

#define CONIOEX
#include "conioex.h"

int g_index0 = 0;	//值等于1时，绘制第一个菜单；值等于2时，绘制第二个菜单,值等于3时，绘制第三个菜单
int g_index1 = 0;	//控制第一个菜单的绘制
int g_index2 = 0;
int g_index3 = 0;

int buildSound = opensound((char*)"sound\\build.mp3");
int removeSound = opensound((char*)"sound\\remove.mp3");

bool clear = true;

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

MENU g_menu;

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

	g_menu.pos.x = 115;
	g_menu.pos.y = 5;
	g_menu.oldpos.x = 115;
	g_menu.oldpos.y = 5;
	g_menu.isPush = false;
}

void UnInitMenu(void)
{
}

void UpdateMenu(void)
{
	g_menu.oldpos.y = g_menu.pos.y;
	//菜单1的处理
	if (g_index0 == MENU1)
	{
		if (inport(PK_UP)) {
			if (!g_menu.isPush)
			{
				g_menu.isPush = true;
				g_index1--;
				g_menu.pos.y -= 5;
				if (g_index1 < BUILD) {
					g_menu.pos.y = 15;
					g_index1 = TITLE;
				}
			}
		}
		else if (inport(PK_DOWN)) {
			if (!g_menu.isPush) {
				g_menu.isPush = true;
				g_index1++;
				g_menu.pos.y += 5;
				if (g_index1 > TITLE) {
					g_menu.pos.y = 5;
					g_index1 = BUILD;
				}
			}
		}
		else if (inport(PK_ENTER)) {
			if (!g_menu.isPush) {
				g_menu.isPush = true;
				switch (g_index1)
				{
				case BUILD:
					if ((GetBuilding() + GetChoose().index)->type != BUILDING_TYPE_NULL) {
						gotoxy(118, 23);
						printf("已有建筑！");
					}
					else {
						clear = true;
						g_menu.pos.y = 3;
						g_index3 = BUILDING_TYPE_SPA;
						g_index0 = MENU3;
					}
					break;
				case REMOVE:
					if ((GetBuilding() + GetChoose().index)->type == BUILDING_TYPE_NULL) {
						gotoxy(118, 23);
						printf("这是空地！");
					}
					else {
						clear = true;
						g_menu.pos.y = 10;
						g_index2 = YES;
						g_index0 = MENU2;
					}						
					break;
				case TITLE:
					clear = true;
					g_menu.pos.y = 10;
					g_index2 = YES;
					g_index0 = MENU2;
					break;
				default:
					break;
				}
			}

		}
		else {
			g_menu.isPush = false;
		}
	}

	//菜单2的处理
	if (g_index0 == MENU2)
	{
		if (inport(PK_UP)) {
			if (!g_menu.isPush) {
				g_menu.isPush = true;
				g_index2--;
				g_menu.pos.y -= 5;
				if (g_index2 < YES) {
					g_menu.pos.y = 15;
					g_index2 = NO;
				}
			}
		}
		else if (inport(PK_DOWN)) {
			if (!g_menu.isPush) {
				g_menu.isPush = true;
				g_index2++;
				g_menu.pos.y += 5;
				if (g_index2 > NO) {
					g_menu.pos.y = 10;
					g_index2 = YES;
				}
			}
		}
		else if (inport(PK_ENTER)) {
			if (!g_menu.isPush) {
				g_menu.isPush = true;
				switch (g_index1)
				{
				case REMOVE:
					if (g_index2 == YES)
					{
						(GetBuilding() + GetChoose().index)->type = BUILDING_TYPE_NULL;
						playsound(removeSound, 0);
						gotoxy(118, 23);
						printf("拆除成功！");
					}
					clear = true;
					g_menu.pos.y = 5;
					g_index1 = BUILD;
					g_index0 = MENU1;
					break;
				case TITLE:
					break;
				default:
					break;
				}
			}
		}
		else {
			g_menu.isPush = false;
		}
	}
	
	//菜单3的处理
	if (g_index0 == MENU3)
	{
		if (inport(PK_UP)) {
			if (!g_menu.isPush) {
				g_menu.isPush = true;
				g_index3--;
				g_menu.pos.y -= 2;							
				if (g_index3 == BACK - 1) {
					g_menu.pos.y = 15;
				}
				if (g_index3 < BUILDING_TYPE_SPA) {
					g_menu.pos.y = 19;
					g_index3 = BACK;
				}
			}
		}
		else if (inport(PK_DOWN)) {
			if (!g_menu.isPush) {
				g_menu.isPush = true;
				g_index3++;
				g_menu.pos.y += 2;
				if (g_index3 == BACK) {
					g_menu.pos.y = 19;
				}
				if (g_index3 > BACK) {
					g_menu.pos.y = 3;
					g_index3 = BUILDING_TYPE_SPA;
				}
			}
		}
		else if (inport(PK_ENTER)) {
			if (!g_menu.isPush) {
				g_menu.isPush = true;
				switch (g_index3) {
				case BUILDING_TYPE_SPA:
					(GetBuilding() + GetChoose().index)->type = BUILDING_TYPE_SPA;
					break;
				case BUILDING_TYPE_CONVENIENCE:
					(GetBuilding() + GetChoose().index)->type = BUILDING_TYPE_CONVENIENCE;
					break;
				case BUILDING_TYPE_RESTAURANT:
					(GetBuilding() + GetChoose().index)->type = BUILDING_TYPE_RESTAURANT;
					break;
				case BUILDING_TYPE_MASSAGE:
					(GetBuilding() + GetChoose().index)->type = BUILDING_TYPE_MASSAGE;
					break;
				case BUILDING_TYPE_SING:
					(GetBuilding() + GetChoose().index)->type = BUILDING_TYPE_SING;
					break;
				case BUILDING_TYPE_POKER:
					(GetBuilding() + GetChoose().index)->type = BUILDING_TYPE_POKER;
					break;
				case BUILDING_TYPE_STORE:
					(GetBuilding() + GetChoose().index)->type = BUILDING_TYPE_STORE;
					break;
				case BACK:
					break;
				default:
					break;
				}
				if (g_index3 != BACK) {
					playsound(buildSound, 0);
				}
				clear = true;
				g_menu.pos.y = 5;
				g_index1 = BUILD;
				g_index0 = MENU1;
				
			}
		}
		else {
			g_menu.isPush = false;
		}
	}
}

void DrawMenu(void)
{
	if (clear == true) {
		for (int i = 0; i <= 17; i++) {
			textattr(0x0F);
			gotoxy(115, 2 + i);
			printf("                    ");
		}
		clear = false;
	}
	
	if (g_index0 == MENU1) {
		textattr(0x0F);
		/*gotoxy(115, 15);
		printf("  ");
		gotoxy(119, 5);
		printf("        ");*/
		gotoxy(121, 5);
		printf("建造");		
		gotoxy(121, 10);
		printf("拆除");
		gotoxy(119, 15);
		printf("回到标题");
	}
	if (g_index0 == MENU2) {
		/*gotoxy(119, 15);
		printf("        ");*/
		textattr(0x0F);
		gotoxy(119, 5);
		printf("确定吗？");
		gotoxy(121, 10);
		printf("确定");
		gotoxy(121, 15);
		printf("取消");	
	}
	if (g_index0 == MENU3) {
		textattr(0x0F);
		gotoxy(121, 3);
		printf("温泉");
		gotoxy(120, 5);
		printf("便利店");
		gotoxy(121, 7);
		printf("饭店");
		gotoxy(120, 9);
		printf("按摩店");
		gotoxy(120, 11);
		printf("卡拉OK");
		gotoxy(120, 13);
		printf("棋牌室");
		gotoxy(120, 15);
		printf("特产店");
		gotoxy(121, 19);
		printf("返回");

	}
	gotoxy(g_menu.oldpos.x, g_menu.oldpos.y);
	printf("  ");
	gotoxy(g_menu.pos.x, g_menu.pos.y);
	printf("◆");
}

int GetMenu()
{
	return 0;
}

