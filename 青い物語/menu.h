//=================================================
// [�꥾�`�ȤΥ��]
// menu.h
// author:fuyizhi
// Date:2021/02/08
//=================================================

#ifndef MENU_H_
#define MENU_H_

#include "choose.h"
#include "customer.h"
#include "scene.h"

#define logx 118
#define logy 24

void InitMenu(void);
void UnInitMenu(void);
void UpdateMenu(void);
void DrawMenu(void);
void clearLog(void);
void clearMenu(void);


//int GetMenu();

typedef struct {
	INT2 pos;
	INT2 oldpos;

	bool isPush;	//���ڿ��ư�����ʹ������ʱִֻ��һ��
}MENU;


enum Menu0
{
	MENU1,
	MENU2,
	MENU3,
	CLEAR
};

enum Menu1
{
	BUILD,
	REMOVE,
	START,
	TITLE
};

enum Menu2
{
	YES,
	NO
};

#endif // !MENU_H_

