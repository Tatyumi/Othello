#include <stdio.h>
#include "TurnManager.h"

// コンストラクタ
CTurnManager::CTurnManager()
{
	SetTurnStrs(BLACK, "Black");
	SetTurnStrs(WHITE, "White");
}

// ターンを表示
void CTurnManager::DispTurn()
{
	printf("%s TURN",turnStrs[GetTurn()]);
}

// ターン終了
void CTurnManager::EndTurn()
{
	// 値を切り替える
	turn ^= 1;
}