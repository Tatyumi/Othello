#include <stdio.h>
#include "BoardManager.h"
#include "StoneManager.h"

// コンストラクタ
CBoardManager::CBoardManager()
{
	// 初期化
	Initialize();
}

//ボードの表示
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
				// 示す座標の場合

				// カーソルを代入
				state = "◎";
			}
			else
			{
				// それ以外の座標の場合

				// ボードの状態を判別
				switch (GetBoard(y, x))
				{
					case NONE:
						state = "・";
						break;
					case WHITE_STONE:
						state = "●";
						break;
					case BLACK_STONE:
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

	// ボードの縦、横それぞれの半分の長さを取得
	int heightCenter = BOARD_HEIGHT / 2;
	int weightCenter = BOARD_WEIGHT / 2;

	// 中央に石を置く
	SetBoard(heightCenter - 1, weightCenter - 1, WHITE_STONE);
	SetBoard(heightCenter - 1, weightCenter, BLACK_STONE);
	SetBoard(heightCenter, weightCenter, WHITE_STONE);
	SetBoard(heightCenter, weightCenter - 1, BLACK_STONE);
}