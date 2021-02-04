//=================================================
// [アクションサンプル]
// main.cpp
// author:**** ****	Date:2021/**/**
//=================================================
#include "main.h"
#include "map.h"

#define CONIOEX
#include "conioex.h"


void Init(void);
void Uninit(void);
void Update(void);
void Draw(void);
void DispFPS(void);

int g_nCountFPS;				// FPSカウンタ



void main(void)
{
	setcursortype(NOCURSOR);;
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	DWORD dwCurrentTime;
	int nCountFrame;

	// 分解能を設定
	timeBeginPeriod(1);

	dwExecLastTime =
		dwFPSLastTime = timeGetTime();
	dwCurrentTime =
		nCountFrame = 0;

	//初期化関数
	Init();

	do
	{
		dwCurrentTime = timeGetTime();
		if ((dwCurrentTime - dwFPSLastTime) >= 500)	// 0.5秒ごとに実行
		{
			g_nCountFPS = nCountFrame * 1000 / (dwCurrentTime - dwFPSLastTime);
			dwFPSLastTime = dwCurrentTime;
			nCountFrame = 0;
		}

		if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
		{
			dwExecLastTime = dwCurrentTime;

			Update();

#ifdef _DEBUG
			DispFPS();
#endif // _DEBUG

			Draw();

			nCountFrame++;
		}
	} while (!inport(PK_ESC));

	Uninit();

	// 分解能を戻す
	timeEndPeriod(1);
}

void Init(void)
{

}

void Uninit(void)
{

}

void Update(void)
{

}

void Draw(void)
{
	DrawMap();
}

#ifdef _DEBUG

//デバッグ表示
void DispFPS(void) {

	// 色設定
	textcolor; LIGHTCYAN;
	textattr(0x0F);
	gotoxy(1, 1);	//表示位置設定
	printf("FPS:%d", g_nCountFPS);

	//　色設定もとに戻す
	textcolor; WHITE;
}
#endif // _DEBUG
