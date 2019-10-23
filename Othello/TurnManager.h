#pragma once

// ターンによって指定される色
enum ETurnColors
{
	BLACK,
	WHITE,
};

// 色の名前文字数
const int colorNameCount = 5;

// nullポインタ領域
const int nullPtr = 1;

// ターンで指定される色の種類
const int turnColors = WHITE + 1;

class CTurnManager
{
public:
	// コンストラクタ
	CTurnManager();


	// turnStrsのアクセサ
	//void SetTurnStrs(int turnColor, const char* colorName) { turnStrs[turnColor][colorNameCount + nullPtr] = colorName; };
	void SetTurnStrs(int turnColor, const char* colorName) { turnStrs[turnColor] = colorName; };

private:
	// ターン表示
	//const char* turnStrs[turnColors][colorNameCount + nullPtr];
	const char* turnStrs[turnColors];

	int turn;
};

