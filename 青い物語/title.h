#ifndef TITLE_H_
#define TITLE_H_

#include "scene.h"

void InitTitle(void);
void UnInitTitle(void);
void UpdateTitle(void);
void DrawTitle(void);

enum TITLECHOOSE
{
	STARTGAME,
	ENDGAME
};

#endif // !#TITLE_H_

