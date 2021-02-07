#ifndef MENU_H_
#define MENU_H_

#include"choose.h"

void InitMenu(void);
void UnInitMenu(void);
void UpdateMenu(void);
void DrawMenu(void);

void SetMenu(int posx, int posy);
int GetMenu();

typedef struct {
	INT2 pos;
	INT2 oldpos;

	bool isPush;	//用于控制按键，使其落下时只执行一次
	int index;		//保存目前所指的建筑索引
}MENU;

#endif // !MENU_H_

