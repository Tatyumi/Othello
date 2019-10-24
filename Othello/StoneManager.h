#pragma once

class CBoardManager;
class CTurnManager;

// 方向
enum EDirection
{
	UP,
	UP_LEFT,
	LEFT,
	DOWN_LEFT,
	DOWN,
	DOWN_RIGHT,
	RIGHT,
	UP_RIGHT,
};

// 方向の種類の数
const int directionTypes = UP_RIGHT + 1;

// x方向
const int xDirection = 0;
// y方向
const int yDirection = 1;

class CStoneManager
{
private:
	CBoardManager* cBoard;
	CTurnManager* cTurn;

public:
	// コンストラクタ
	CStoneManager();
	// カーソル移動処理
	void MoveCursor(CBoardManager* cBoard, CTurnManager* cTurn);
	//void MoveCursor();
	// 石を置く処理
	void PutStone(CBoardManager* CBoard, CTurnManager* cTurn);
	// 石が置けるか判別
	bool CanPutStone(CBoardManager* CBoard, CTurnManager* cTurn);
	// cursorXアクセサ
	int GetCursorX() { return cursorX; };
	// cursorYアクセサ
	int GetCursorY() { return cursorY; };
private:
	// カーソルのx座標
	int cursorX;
	// カーソルのy座標
	int cursorY;
};