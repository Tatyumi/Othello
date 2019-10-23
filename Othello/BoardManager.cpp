#include <stdio.h>
#include "BoardManager.h"

// �R���X�g���N�^
CBoardManager::CBoardManager()
{
	Initialize();
}

// �{�[�h�̕\��
void CBoardManager::DispBoard(CStoneManager* cStone) 
{
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WEIGHT; x++)
		{
			const char* state = "";
			if ((cStone->GetCursorY() == y) && (cStone->GetCursorX() == x))
			{
				state = "��";
			}
			else
			{

				switch (board[y][x])
				{
					case NONE:
						state = "�E";
						break;
					case BLACK_STONE:
						state = "��";
						break;
					case WHITE_STONE:
						state = "�Z";
						break;
				}
			}

			printf(state);
		}
		printf("\n");
	}
}

// ������
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