#include<conio.h>
#include "StoneManager.h"

// コンストラクタ
CStoneManager::CStoneManager()
{
	cursorX = 0;
	cursorY = 0;
}

// カーソル移動
void CStoneManager::MoveCursor()
{
	// キー入力受付
	switch (_getch())
	{

		case'a':
			// 左に移動
			cursorX--;
			break;

		case'd':
			// 右に移動
			cursorX++;
			break;

		case'w':
			// 上に移動
			cursorY--;
			break;

		case's':
			// 下に移動
			cursorY++;
			break;
	}
}