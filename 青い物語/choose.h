//=================================================
// [�꥾�`�ȤΥ��]
// choose.h
// author:fuyizhi
// Date:2021/02/08
//=================================================

#ifndef CHOOSE_H_
#define CHOOSE_H_

#include "building.h"
#include "main.h"

void InitChoose(void);
void UnInitChoose(void);
void UpdateChoose(void);
void DrawChoose(void);

void SetChoose(int posx, int posy);


typedef struct {
	INT2 pos;
	INT2 oldpos;

	bool isPush;	//���ڿ��ư�����ʹ������ʱִֻ��һ��
	int index;		//����Ŀǰ��ָ�Ľ�������
}CHOOSE;

CHOOSE GetChoose();

#endif // !CHOOSE_H_

