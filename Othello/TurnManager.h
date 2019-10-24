#pragma once

// ターンによって指定される色
enum ETurnColors
{
	WHITE = 0,      // 白
	BLACK = 1,      // 黒
};

// 色の名前文字数
const int colorNameCount = 5;

// nullポインタ領域
const int nullPtr = 1;

// ターンで指定される色の種類
const int turnColors = BLACK + 1;

class CTurnManager
{
public:
	// コンストラクタ
	CTurnManager();
	// ターンを表示
	void DispTurn();
	// ターン切り替え
	void ChangeTurn();
	// turnStrsのアクセサ
	void SetTurnStrs(int turnColor, const char* colorName) { turnStrs[turnColor] = colorName; };
	// turnのアクセサ
	int GetTurn()const { return turn; };
	void SerTurn(int turnNum) { turn = turnNum; };

private:
	// ターン表示
	const char* turnStrs[turnColors];
	// ターン
	int turn;

};