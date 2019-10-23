#pragma once
#include "StoneManager.h"

// 縦幅
const int BOARD_HEIGHT = 8;
// 横幅
const int BOARD_WEIGHT = 8;

// ボードの状態
enum EBoadState
{
	NONE		= -1,		// 何もない
	BLACK_STONE =  0,       // 黒碁石が置いてある
	WHITE_STONE =  1,       // 白碁石が置いてある
};

class CBoardManager
{
public:
	// コンストラクタ
	CBoardManager();
	//初期化
	void Initialize();
	// ボードの表示
	void DispBoard(CStoneManager* cStone);
	//boardのアクセサ
	void SetBoard(int vecY, int vecX, int state) { board[vecY][vecX] = state; };

private:
	// ボード
	int board[BOARD_HEIGHT][BOARD_WEIGHT];
};
