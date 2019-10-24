#include <stdlib.h>
#include "BoardManager.h"
#include "StoneManager.h"
#include "TurnManager.h"

int main()
{
	CBoardManager cBoard;
	CStoneManager cStone;
	CTurnManager  cTurn;

	while (1)
	{

		// 画面クリア
		system("cls");

		// ボード表示
		cBoard.DispBoard(&cStone);
		// ターン表示
		cTurn.DispTurn();

		// カーソル移動
		cStone.MoveCursor(&cBoard, &cTurn);
	}

	return 0;
}