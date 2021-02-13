//=================================================
// [¥ê¥¾©`¥È¤Î¥ï¥Ê]
// customer.h
// author:fuyizhi
// Date:2021/02/09
//=================================================

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "main.h"
#include "road.h"
#include "building.h"
#include "map.h"

#define SPEED 0.1
#define MAX_STATUS 4

void InitCustomer(void);
void UnInitCustomer(void);
void UpdateCustomer(void);
void DrawCustomer(void);
void SetCustomer(int money, int status0 = NOTHING,int status1 = NOTHING, int status2 = NOTHING, int status3 = NOTHING);

typedef struct {
	FLOAT2 pos;
	FLOAT2 oldpos;

	int money;
	int status[MAX_STATUS];

	bool isGoInto;
}CUSTOMER;

#endif // !CUSTOMER_H_

