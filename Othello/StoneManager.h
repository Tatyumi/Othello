#pragma once

class CStoneManager
{
public:
	// �R���X�g���N�^
	CStoneManager();
	// �J�[�\���ړ�����
	void MoveCursor();
	// cursorX�A�N�Z�T
	int GetCursorX() { return cursorX; };
	// cursorY�A�N�Z�T
	int GetCursorY() { return cursorY; };
private:
	// �J�[�\����x���W
	int cursorX;
	// �J�[�\����y���W
	int cursorY;

};


