//=================================================
// [リゾートのワナ]
// choose.h
// author:fuyizhi
// Date:2021/02/08
//=================================================

#ifndef CHOOSE_H_
#define CHOOSE_H_

#include "main.h"
#include "building.h"

void InitChoose(void);
void UnInitChoose(void);
void UpdateChoose(void);
void DrawChoose(void);
void clearMenu(void);

void SetChoose(int posx, int posy);


typedef struct {
	INT2 pos;
	INT2 oldpos;

	bool isPush;	//キーを操作する
	bool isStart;	//レベルスタートかの判定
	bool isShow;	//一回描く
	int index;		//建築のインデックス
	

}CHOOSE;

CHOOSE* GetChoose();

#endif // !CHOOSE_H_

