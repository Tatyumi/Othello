#include <stdlib.h>
#include "BoardManager.h"
#include "StoneManager.h"

int main()
{
	CBoardManager cBoard;
	CStoneManager cStone;

	while (1)
	{

		// 画面クリア
		system("cls");

		// ボード初期化
		cBoard.Initialize();

		// ボード表示
		cBoard.DispBoard(&cStone);

		// カーソル移動
		cStone.MoveCursor();
	}
	return 0;
}