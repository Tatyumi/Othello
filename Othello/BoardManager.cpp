#include <stdio.h>
#include "BoardManager.h"

// コンストラクタ
CBoardManager::CBoardManager()
{
	// 初期化
	Initialize();
}

// ボードの表示
void CBoardManager::DispBoard(CStoneManager* cStone) 
{
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WEIGHT; x++)
		{
			const char* state = "";

			// カーソルが示す座標か判別
			if ((cStone->GetCursorY() == y) && (cStone->GetCursorX() == x))
			{
				// 示す座標である場合

				// カーソルを代入
				state = "◎";
			}
			else
			{
				// ボードの状態を判別
				switch (board[y][x])
				{
					case NONE:
						state = "・";
						break;
					case BLACK_STONE:
						state = "●";
						break;
					case WHITE_STONE:
						state = "〇";
						break;
				}
			}

			printf(state);
		}
		printf("\n");
	}
}

// 初期化
void CBoardManager::Initialize()
{
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WEIGHT; x++)
		{
			// ボード全体をNONEの状態にする
			SetBoard(y, x, NONE);
		}
	}
}