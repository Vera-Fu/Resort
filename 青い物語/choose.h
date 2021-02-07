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

	bool isPush;	//用于控制按键，使其落下时只执行一次
	int index;		//保存目前所指的建筑索引
}CHOOSE;

CHOOSE GetChoose();

#endif // !CHOOSE_H_

