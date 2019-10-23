#pragma once

class CStoneManager
{
public:
	// コンストラクタ
	CStoneManager();
	// カーソル移動処理
	void MoveCursor();
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


