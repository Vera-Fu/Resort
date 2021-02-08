#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "main.h"

void InitCustomer(void);
void UnInitCustomer(void);
void UpdateCustomer(void);
void DrawCustomer(void);

enum WAY {
	MOVEUP,
	MOVEDOWN,
	MOVELEFT,
	MOVERIGHT
};

typedef struct {
	FLOAT2 pos;
	FLOAT2 oldpos;


}CUSTOMER;

#endif // !CUSTOMER_H_

