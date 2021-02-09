#include "customer.h"

#define CONIOEX
#include "conioex.h"

CUSTOMER g_customer;

void InitCustomer(void)
{
	g_customer.pos.x = ROAD_START0_X + 2;
	g_customer.pos.y = ROAD_START0_Y - 1;
	g_customer.oldpos.x = g_customer.pos.x;
	g_customer.oldpos.y = g_customer.pos.y;
}

void UnInitCustomer(void)
{
}

void UpdateCustomer(void)
{
}

void DrawCustomer(void)
{
	textattr(0xF0);
	gotoxy((int)g_customer.oldpos.x, (int)g_customer.oldpos.y + 1);
	printf("  ");
	gotoxy((int)g_customer.pos.x, (int)g_customer.pos.y + 1);
	printf("¡ñ");

	gotoxy((int)g_customer.oldpos.x, (int)g_customer.oldpos.y + 2);
	printf("  ");
	gotoxy((int)g_customer.pos.x, (int)g_customer.pos.y + 2);
	printf("¡ö");

	gotoxy((int)g_customer.oldpos.x, (int)g_customer.oldpos.y + 3);
	printf("  ");
	gotoxy((int)g_customer.pos.x, (int)g_customer.pos.y + 3);
	printf("¨‹");
	textattr(0x0F);
}
