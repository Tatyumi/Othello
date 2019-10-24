#pragma once

// 縦幅
const int BOARD_HEIGHT = 8;
// 横幅
const int BOARD_WEIGHT = 8;

// ボードの状態
enum EBoadState
{
	NONE = -1,   // 何もない
	WHITE_STONE = 0,       // 白碁石が置いてある
	BLACK_STONE = 1,       // 黒碁石が置いてある
};

class CStoneManager;

class CBoardManager
{
private:
	// ボード
	int board[BOARD_HEIGHT][BOARD_WEIGHT];

	CStoneManager* cStone;
public:
	// コンストラクタ
	CBoardManager();
	//初期化
	void Initialize();
	// ボードの表示
	void DispBoard(CStoneManager* cStone);

	//boardのアクセサ
	void SetBoard(int vecY, int vecX, int state) { board[vecY][vecX] = state; };
	int GetBoard(int vecY, int vecX) { return board[vecY][vecX]; };

};
