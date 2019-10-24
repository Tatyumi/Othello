#include<conio.h>
#include "StoneManager.h"
#include "BoardManager.h"
#include "TurnManager.h"

// 方向の種類
int directions[][2] = {
		{ 0,  -1 },     //UP,
		{ -1, -1 },     //UP_LEFT,
		{ -1,  0 },     //LEFT,
		{ -1,  1 },     //DOWN_LEFT,
		{ 0,   1 },     //DOWN,
		{ 1,   1 },     //DOWN_RIGHT,
		{ 1,   0 },     //RIGHT,
		{ 1,  -1 },     //UP_RIGHT,
};

// コンストラクタ
CStoneManager::CStoneManager()
{
	cursorX = 0;
	cursorY = 0;
}

// カーソル移動
void CStoneManager::MoveCursor(CBoardManager* cBoard, CTurnManager* cTurn)
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

		case'\r':

			// 石が置けるか判別
			if (CanPutStone(cBoard, cTurn))
			{
				// ターン切り替え
				cTurn->ChangeTurn();
			}
			break;
	}
}

// ボードに石を置く
//void CStoneManager::PutStone()
void CStoneManager::PutStone(CBoardManager* cBoard, CTurnManager* cTurn)
{
	// ボードに現在のターンの色を格納する
	cBoard->SetBoard(cursorY, cursorX, cTurn->GetTurn());

	// 石チェック？

	cTurn->ChangeTurn();
}

// BoardManagerに定義しているものとうまく合わせる
bool CStoneManager::CanPutStone(CBoardManager* CBoard, CTurnManager* cTurn)
{
	//カーソルの箇所に石があるか判別
	if (CBoard->GetBoard(cursorY, cursorX) != NONE)
	{
		// 置かれている場合

		return false;
	}

	bool isPut = false;

	for (int i = 0; i < directionTypes; i++)
	{
		int x = cursorX;
		int y = cursorY;

		// 隣接する座標を取得
		x += directions[i][xDirection];
		y += directions[i][yDirection];

		// 隣のボードに同じ色の石が置いてあるか判別
		if (CBoard->GetBoard(y, x) != (cTurn->GetTurn() ^ 1))
		{
			// 置いてある場合

			continue;
		}

		while (1)
		{
			// 隣接する座標を取得
			x += directions[i][xDirection];
			y += directions[i][yDirection];

			// 確認する座標が画面外か判別
			if ((x < 0) || (x > BOARD_WEIGHT) || (y < 0) || (y >= BOARD_HEIGHT))
			{
				break;
			}

			// 石が置いてあるか判別
			if (CBoard->GetBoard(y, x) == NONE)
			{
				// 置いていない場合

				break;
			}
			
			// 現在のターンで指定されている色と同じ色か判別
			if (CBoard->GetBoard(y, x) == cTurn->GetTurn())
			{
				// ひっくり返し開始地点
				int turnPosX = cursorX;
				int turnPosY = cursorY;

				while (1)
				{
					// 現在のターンの色の石を置く
					CBoard->SetBoard(turnPosY, turnPosX, cTurn->GetTurn());

					// 次の座標を算出
					turnPosX += directions[i][xDirection];
					turnPosY += directions[i][yDirection];

					// ひっくり返し終点か判別
					if ((turnPosX == x) && (turnPosY == y))
					{
						// 終点の場合

						// フラグ更新
						isPut = true;
						break;
					}
				}
			}
			break;
		}
	}
	return isPut;
}