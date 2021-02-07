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

	bool isPush;	//���ڿ��ư�����ʹ������ʱִֻ��һ��
	int index;		//����Ŀǰ��ָ�Ľ�������
}MENU;

#endif // !MENU_H_

