//=================================================
// [リゾートのワナ]
// menu.cpp
// author:fuyizhi
// Date:2021/02/08
// 注:在清除菜单的部分，不小心用了两种不同的实现方式来进行清除，一种是全局布尔变量，一种是函数(2021.2.16更新：已统一为使用函数)
//=================================================

#include "menu.h"

#define CONIOEX
#include "conioex.h"

int g_index0;	//メニュー一二三の判定インデックス
int g_index1;	//メニュー一のインデックス
int g_index2;	//メニュー二のインデックス
int g_index3;	//メニュー三のインデックス

bool isBuildingshow;

static int buildSound;
static int removeSound;
static int menubuttonSound;
static int buttonpushSound;

//bool clearMenu();

MENU g_menu;

void InitMenu(void)
{
	g_index0 = 0;
	g_index1 = 0;
	g_index2 = 0;
	g_index3 = 0;
	buildSound = opensound((char*)"sound\\build.mp3");
	removeSound = opensound((char*)"sound\\remove.mp3");
	menubuttonSound = opensound((char*)"sound\\button01.mp3");
	buttonpushSound = opensound((char*)"sound\\buttonpush.mp3");
	isBuildingshow = false;
	textattr(0x0F);
	//メニューの範囲
	gotoxy(110, 1);
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

	//建築ステータスの範囲
	gotoxy(105, 22);
	printf("┏");
	for (int i = 0; i < 35; i++) {
		printf("━");
	}
	gotoxy(140, 22);
	printf("┓");
	for (int i = 1; i < 8; i++) {
		gotoxy(105, 22 + i);
		printf("┃");
	}
	for (int i = 1; i < 8; i++) {
		gotoxy(140, 22 + i);
		printf("┃");
	}
	gotoxy(105, 30);
	printf("┗");
	for (int i = 0; i < 35; i++) {
		printf("━");
	}
	gotoxy(140, 30);
	printf("┛");

	//カスタマーの範囲
	gotoxy(105, 31);
	printf("┏");
	for (int i = 0; i < 35; i++) {
		printf("━");
	}
	gotoxy(140, 31);
	printf("┓");
	for (int i = 1; i < 8; i++) {
		gotoxy(105, 31 + i);
		printf("┃");
	}
	for (int i = 1; i < 8; i++) {
		gotoxy(140, 31 + i);
		printf("┃");
	}
	gotoxy(105, 39);
	printf("┗");
	for (int i = 0; i < 35; i++) {
		printf("━");
	}
	gotoxy(140, 39);
	printf("┛");

	g_menu.pos.x = 113;
	g_menu.pos.y = 3;
	g_menu.oldpos.x = 113;
	g_menu.oldpos.y = 3;
	g_menu.isPush = false;
}

void UnInitMenu(void)
{
	ClearScene();
}

void UpdateMenu(void)
{
	g_menu.oldpos.y = g_menu.pos.y;
	//メニュー一の処理
	if (g_index0 == MENU1)
	{
		if (inport(PK_UP)) {
			if (!g_menu.isPush) {
				clearLog();
				playsound(menubuttonSound, 0);
				g_menu.isPush = true;
				g_index1--;
				g_menu.pos.y -= 5;
				if (g_index1 < BUILD) {
					g_menu.pos.y = 18;
					g_index1 = TITLE;
				}
			}
		}
		else if (inport(PK_DOWN)) {
			if (!g_menu.isPush) {
				clearLog();
				playsound(menubuttonSound, 0);
				g_menu.isPush = true;
				g_index1++;
				g_menu.pos.y += 5;
				if (g_index1 > TITLE) {
					g_menu.pos.y = 3;
					g_index1 = BUILD;
				}
			}
		}
		else if (inport(PK_ENTER)) {
			if (!g_menu.isPush) {
				clearLog();
				playsound(buttonpushSound, 0);
				g_menu.isPush = true;
				switch (g_index1)
				{
				case BUILD:
					clearMenu();
					g_menu.pos.y = 3;
					g_index3 = BUILDING_TYPE_SPA;
					g_index0 = MENU3;
					isBuildingshow = true;
					break;
				case REMOVE:
					clearMenu();
					g_menu.pos.y = 10;
					g_index2 = YES;
					g_index0 = MENU2;
					break;
				case START:
					clearMenu();
					g_menu.pos.y = 10;
					g_index2 = YES;
					g_index0 = MENU2;
					break;
				case TITLE:
					clearMenu();
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

	//メニュー二の処理
	if (g_index0 == MENU2)
	{
		if (inport(PK_UP)) {
			if (!g_menu.isPush) {
				clearLog();
				playsound(menubuttonSound, 0);
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
				clearLog();
				playsound(menubuttonSound, 0);
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
				clearLog();
				playsound(buttonpushSound, 0);
				g_menu.isPush = true;
				if (g_index2 == YES) {
					switch (g_index1)
					{
					case REMOVE:
						if ((GetBuilding() + GetChoose()->index)->type == BUILDING_TYPE_NULL) {
							gotoxy(logx, logy);
							printf("空地です！");
						}
						else if (!(GetBuilding() + GetChoose()->index)->isRemoveable) {
							gotoxy(logx - 2, logy);
							printf("撤去できない！");
						}

						else {
							(GetBuilding() + GetChoose()->index)->type = BUILDING_TYPE_NULL;
							playsound(removeSound, 0);
							gotoxy(logx, logy);
							printf("撤去成功！");
						}
						break;
					case START:
						GetCustomer()->isMoving = true;
						gotoxy(g_menu.oldpos.x, g_menu.oldpos.y);
						printf("  ");
						g_index0 = CLEAR;
						clearMenu();
						GetChoose()->isStart = true;
						GetChoose()->isShow = true;
						break;
					case TITLE:
						closesound(menubuttonSound);
						closesound(buttonpushSound);
						closesound(removeSound);
						closesound(buildSound);
						SetScene(TITLESCENE);
						break;
					default:
						break;
					}
				}
				if (g_index0 != CLEAR)
				{
					clearMenu();
					g_menu.pos.y = 3;
					g_index1 = BUILD;
					g_index0 = MENU1;
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
				clearLog();
				playsound(menubuttonSound, 0);
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
				isBuildingshow = true;
			}
		}
		else if (inport(PK_DOWN)) {
			if (!g_menu.isPush) {
				clearLog();
				playsound(menubuttonSound, 0);
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
				isBuildingshow = true;
			}
		}
		else if (inport(PK_ENTER)) {
			if (!g_menu.isPush) {
				clearLog();
				playsound(buttonpushSound, 0);
				g_menu.isPush = true;
				if ((GetBuilding() + GetChoose()->index)->type != BUILDING_TYPE_NULL) {
					gotoxy(logx, logy);
					printf("建築あり！");
				}
				else {
					switch (g_index3) {
					case BUILDING_TYPE_SPA:
						(GetBuilding() + GetChoose()->index)->type = BUILDING_TYPE_SPA;
						break;						
					case BUILDING_TYPE_CONVENIENCE:	
						(GetBuilding() + GetChoose()->index)->type = BUILDING_TYPE_CONVENIENCE;
						break;						
					case BUILDING_TYPE_RESTAURANT:	
						(GetBuilding() + GetChoose()->index)->type = BUILDING_TYPE_RESTAURANT;
						break;
					case BUILDING_TYPE_MASSAGE:
						(GetBuilding() + GetChoose()->index)->type = BUILDING_TYPE_MASSAGE;
						break;
					case BUILDING_TYPE_SING:
						(GetBuilding() + GetChoose()->index)->type = BUILDING_TYPE_SING;
						break;
					case BUILDING_TYPE_POKER:
						(GetBuilding() + GetChoose()->index)->type = BUILDING_TYPE_POKER;
						break;
					case BUILDING_TYPE_STORE:
						(GetBuilding() + GetChoose()->index)->type = BUILDING_TYPE_STORE;
						break;
					case BACK:
						break;
					default:
						break;
					}
					if (g_index3 != BACK) {
						playsound(buildSound, 0);
					}
				}				
				clearMenu();
				g_menu.pos.y = 3;
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
	/*if (clear = true) {
		for (int i = 0; i <= 17; i++) {
			textattr(0x0F);
			gotoxy(115, 2 + i);
			printf("                    ");
		}
		clear = false;
	}*/
	
	switch (g_index0)
	{
	case MENU1:
		textattr(0x0F);
		gotoxy(120, 3);
		printf("ビルド");
		gotoxy(121, 8);
		printf("撤去");
		gotoxy(116, 13);
		printf("レベルスタート");
		gotoxy(116, 18);
		printf("タイトルに戻る");
		break;
	case MENU2:
		textattr(0x0F);
		gotoxy(119, 5);
		printf("いいか？");
		gotoxy(121, 10);
		printf("はい");
		gotoxy(120, 15);
		printf("いいえ");
		break;
	case MENU3:
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
		break;
	default:
		break;
	}

	if (g_index0 != CLEAR)
	{
		gotoxy(g_menu.oldpos.x, g_menu.oldpos.y);
		printf("  ");
		gotoxy(g_menu.pos.x, g_menu.pos.y);
		printf("◆");
	}
	

	//建築のステータスを表示する
	if (g_index0 == MENU3)
	{
		if (isBuildingshow)
		{
			textattr(0x0F);
			gotoxy(108, 24);
			switch (g_index3)
			{
			case BUILDING_TYPE_SPA:
				printf("建筑名称: 温泉");
				gotoxy(108, 26);
				printf("建筑收费: ￥%d", BUILDING_MONEY_SPA);
				gotoxy(108, 28);
				printf("建筑描述: 疲劳↓ 饥饿↑");
				break;
			case BUILDING_TYPE_CONVENIENCE:
				printf("建筑名称: 便利店");
				gotoxy(108, 26);
				printf("建筑收费: ￥%d", BUILDING_MONEY_CONVENIENCE);
				gotoxy(108, 28);
				printf("建筑描述: 口渴↓");
				break;
			case BUILDING_TYPE_RESTAURANT:
				printf("建筑名称: 餐馆");
				gotoxy(108, 26);
				printf("建筑收费: ￥%d", BUILDING_MONEY_RESTAURANT);
				gotoxy(108, 28);
				printf("建筑描述: 饥饿↓无聊↑");
				break;
			case BUILDING_TYPE_MASSAGE:
				printf("建筑名称: 按摩店");
				gotoxy(108, 26);
				printf("建筑收费: ￥%d", BUILDING_MONEY_MASSAGE);
				gotoxy(108, 28);
				printf("建筑描述: 疲劳↓");
				break;
			case BUILDING_TYPE_SING:
				printf("建筑名称: 卡拉OK");
				gotoxy(108, 26);
				printf("建筑收费: ￥%d", BUILDING_MONEY_SING);
				gotoxy(108, 28);
				printf("建筑描述: 无聊↓ 口渴↑");
				break;
			case BUILDING_TYPE_POKER:
				printf("建筑名称: 棋牌室");
				gotoxy(108, 26);
				printf("建筑收费: ￥%d", BUILDING_MONEY_POKER);
				gotoxy(108, 28);
				printf("建筑描述: 无聊↓");
				break;
			case BUILDING_TYPE_STORE:
				printf("建筑名称: 特产店");
				gotoxy(108, 26);
				printf("建筑收费: ￥%d", BUILDING_MONEY_STORE);
				gotoxy(108, 28);
				printf("建筑描述: 瞧一瞧看一看！");
				break;
			default:
				break;
			}
			isBuildingshow = false;
		}		
	}
}

void clearLog(void)
{
	textattr(0x00);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			gotoxy(106 + j, 23 + i);
			printf(" ");
		}
	}
}

