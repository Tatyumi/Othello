#include <stdio.h>
#include "TurnManager.h"

// コンストラクタ
CTurnManager::CTurnManager()
{
	SetTurnStrs(WHITE, "White");
	SetTurnStrs(BLACK, "Black");
	SerTurn(WHITE);
}

// ターンを表示
void CTurnManager::DispTurn()
{
	printf("%s ターン", turnStrs[turn]);
}

// ターン切り替え
void CTurnManager::ChangeTurn()
{
	// 値を切り替える
	turn ^= 1;
}