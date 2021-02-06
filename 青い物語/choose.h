#ifndef CHOOSE_H_
#define CHOOSE_H_

#include "building.h"
#include "main.h"

void InitChoose(void);
void UnInitChoose(void);
void UpdateChoose(void);
void DrawChoose(void);

void SetChoose(int posx, int posy);
int GetChoose();

typedef struct {
	INT2 pos;
	INT2 oldpos;

	bool isPush;	//���ڿ��ư�����ʹ������ʱִֻ��һ��
	int index;		//����Ŀǰ��ָ�Ľ�������
}CHOOSE;

#endif // !CHOOSE_H_

