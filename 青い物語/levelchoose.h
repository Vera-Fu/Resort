#ifndef LEVELCHOOSE_H_
#define LEVELCHOOSE_H_

#include "scene.h"
#include "title.h"

#define MAX_LEVEL 9

void InitLevelChoose(void);
void UnInitLevelChoose(void);
void UpdateLevelChoose(void);
void DrawLevelChoose(void);

typedef struct {
	int index;
	int star;

	int x;
	int y;

	//bool isUse;
}LEVELCHOOSE;

void SetLevelChoose(int x, int y);
LEVELCHOOSE* GetLevelChoose(void);

int GetLevelIndex(void);

#endif // !LEVELCHOOSE_H_

