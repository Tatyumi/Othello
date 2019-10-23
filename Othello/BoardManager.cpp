#include <stdio.h>
#include "BoardManager.h"

// コンストラクタ
CBoardManager::CBoardManager()
{
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
			if ((cStone->GetCursorY() == y) && (cStone->GetCursorX() == x))
			{
				state = "◎";
			}
			else
			{

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
			SetBoard(y, x, NONE);
		}
	}
}