//=================================================
// [¥ê¥¾©`¥È¤Î¥ï¥Ê]
// map.h
// author:fuyizhi
// Date:2021/02/05
//=================================================

#ifndef MAP_H_
#define MAP_H_

#include "main.h"

#define MAPWIDTH_MAX 100
#define MAPHEIGHT_MAX 40

void InitMap(void);
void UnInitMap(void);
void UpdateMap(void);
void DrawMap(void);

typedef struct {
	INT2 pos;
}HOTEL;

void SetHotel(int x, int y);
HOTEL GetHotel(void);

#endif // !MAP_H_

