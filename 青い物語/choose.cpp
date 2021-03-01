//=================================================
// [�꥾�`�ȤΥ��]
// choose.cpp
// author:fuyizhi
// Date:2021/02/06
//=================================================

#include "choose.h"

#define CONIOEX
#include "conioex.h"

CHOOSE g_choose;

BUILDING* g_buliding = GetBuilding();

int choosebuttonSound;

void InitChoose(void)
{
	g_choose.pos.x = 0;
	g_choose.pos.y = 0;
	g_choose.oldpos.x = g_choose.pos.x;
	g_choose.oldpos.y = g_choose.pos.y;
	g_choose.index = 0;
	g_choose.isPush = false;
	g_choose.isStart = false;
	g_choose.isShow = false;

	SetChoose(g_buliding->pos.x + 2, g_buliding->pos.y - 2);

	choosebuttonSound = opensound((char*)"sound\\button02.mp3");
}

void UnInitChoose(void)
{
	closesound(choosebuttonSound);
}

void UpdateChoose(void)
{
	g_choose.oldpos.x = g_choose.pos.x;
	g_choose.oldpos.y = g_choose.pos.y;

	//cursor���ƄӤ��������
	if (inport(PK_RIGHT)) {
		if (!g_choose.isPush)
		{
			g_choose.isPush = true;
			if (g_choose.index < GetMaxIndex())
			{
				playsound(choosebuttonSound, 0);	
				g_choose.index++;
				SetChoose((g_buliding + g_choose.index)->pos.x + 2, (g_buliding + g_choose.index)->pos.y - 2);
			}
			if (g_choose.isStart)
			{
				clearMenu();
				g_choose.isShow = true;
			}
		}	
	} else if (inport(PK_LEFT)) {
		if (!g_choose.isPush)
		{
			g_choose.isPush = true;
			if (g_choose.index > 0){
				playsound(choosebuttonSound, 0);
				g_choose.index--;
				SetChoose((g_buliding + g_choose.index)->pos.x + 2, (g_buliding + g_choose.index)->pos.y - 2);
			}
			if (g_choose.isStart)
			{
				clearMenu();
				g_choose.isShow = true;
			}
		}		
	} 
	else {
		g_choose.isPush = false;
	}
}

void DrawChoose(void)
{
	textattr(0x0F);
	//gotoxy(g_choose.oldpos.x - 2, g_choose.oldpos.y - 1);
	//printf("      ");

	gotoxy(g_choose.oldpos.x, g_choose.oldpos.y);
	printf("  ");

	gotoxy(g_choose.pos.x, g_choose.pos.y);
	printf("��");
	
	//if (!(g_buliding + g_choose.index)->isRemoveable)
	//{
	//	gotoxy(g_choose.pos.x - 4, g_choose.pos.y - 1);
	//	printf("(���ɲ��)");
	//}

	for (int i = 0; i < MAX_BUILDING; i++) {
		
		switch ((g_buliding + i)->type)
		{	
		case BUILDING_TYPE_NULL:
			gotoxy((g_buliding + i)->pos.x - 2, (g_buliding + i)->pos.y - 1);
			printf("          ");
			break;
		case BUILDING_TYPE_SPA:
			gotoxy((g_buliding + i)->pos.x + 1, (g_buliding + i)->pos.y - 1);
			printf("��Ȫ");
			break;
		case BUILDING_TYPE_CONVENIENCE:
			gotoxy((g_buliding + i)->pos.x - 1, (g_buliding + i)->pos.y - 1);
			printf("����ӥ�");
			break;
		case BUILDING_TYPE_RESTAURANT:
			gotoxy((g_buliding + i)->pos.x - 2, (g_buliding + i)->pos.y - 1);
			printf("�쥹�ȥ��");
			break;
		case BUILDING_TYPE_MASSAGE:
			gotoxy((g_buliding + i)->pos.x - 2, (g_buliding + i)->pos.y - 1);
			printf("�ޥå��`��");
			break;
		case BUILDING_TYPE_SING:
			gotoxy((g_buliding + i)->pos.x - 1, (g_buliding + i)->pos.y - 1);
			printf("���饪��");
			break;
		case BUILDING_TYPE_POKER:
			gotoxy((g_buliding + i)->pos.x - 2, (g_buliding + i)->pos.y - 1);
			printf("���`���`��");
			break;
		case BUILDING_TYPE_STORE:
			gotoxy((g_buliding + i)->pos.x - 1, (g_buliding + i)->pos.y - 1);
			printf("���b����");
			break;
		default:
			break;
		}

	}

	//��٥륹���`�ȤΕr�����B�Υ��Ʃ`�������ʾ����
	if (g_choose.isStart && g_choose.isShow)
	{
		gotoxy(112, 3);
		switch ((g_buliding + g_choose.index)->type)
		{
		case BUILDING_TYPE_SPA:
			printf("���B��ǰ: ��Ȫ");
			gotoxy(112, 5);
			printf("�Ͻ�: ��%d", BUILDING_MONEY_SPA);
			gotoxy(112, 7);
			printf("����: ƣ����");
			gotoxy(118, 9);
			printf("����������");
			break;
		case BUILDING_TYPE_CONVENIENCE:
			printf("���B��ǰ: ����ӥ�");
			gotoxy(112, 5);
			printf("�Ͻ�: ��%d", BUILDING_MONEY_CONVENIENCE);
			gotoxy(112, 7);
			printf("����: ���f����");
			break;
		case BUILDING_TYPE_RESTAURANT:
			printf("���B��ǰ: �쥹�ȥ��");
			gotoxy(112, 5);
			printf("�Ͻ�: ��%d", BUILDING_MONEY_RESTAURANT);
			gotoxy(112, 7);
			printf("����: ����������");
			gotoxy(118, 9);
			printf("ԑ�ޤ�ʤ���");
			break;
		case BUILDING_TYPE_MASSAGE:
			printf("���B��ǰ: �ޥå��`��");
			gotoxy(112, 5);
			printf("�Ͻ�: ��%d", BUILDING_MONEY_MASSAGE);
			gotoxy(112, 7);
			printf("����: ƣ����");
			break;
		case BUILDING_TYPE_SING:
			printf("���B��ǰ: ���饪��");
			gotoxy(112, 5);
			printf("�Ͻ�: ��%d", BUILDING_MONEY_SING);
			gotoxy(112, 7);
			printf("����: ԑ�ޤ�ʤ��� ");
			gotoxy(118, 9);
			printf("���f����");
			break;
		case BUILDING_TYPE_POKER:
			printf("���B��ǰ: ���`���`��");
			gotoxy(112, 5);
			printf("�Ͻ�: ��%d", BUILDING_MONEY_POKER);
			gotoxy(112, 7);
			printf("����: ԑ�ޤ�ʤ���");
			break;
		case BUILDING_TYPE_STORE:
			printf("���B��ǰ: ���b����");
			gotoxy(112, 5);
			printf("�Ͻ�: ��%d", BUILDING_MONEY_STORE);
			gotoxy(112, 7);
			printf("����: �ʤ�");
			break;
		default:
			/*clearMenu();*/
			
			break;
		}
		g_choose.isShow = false;
	}
}

void SetChoose(int posx, int posy)
{
	g_choose.pos.x = posx;
	g_choose.pos.y = posy;
}

CHOOSE* GetChoose()
{
	return &g_choose;
}

void clearMenu(void)
{
	for (int i = 0; i <= 17; i++) {
		textattr(0x0F);
		gotoxy(112, 2 + i);
		printf("                       ");
	}
}
