#include<conio.h>
#include "StoneManager.h"

// �R���X�g���N�^
CStoneManager::CStoneManager()
{
	cursorX = 0;
	cursorY = 0;
}

// �J�[�\���ړ�
void CStoneManager::MoveCursor()
{
	// �L�[���͎�t
	switch (_getch())
	{

		case'a':
			// ���Ɉړ�
			cursorX--;
			break;

		case'd':
			// �E�Ɉړ�
			cursorX++;
			break;

		case'w':
			// ��Ɉړ�
			cursorY--;
			break;

		case's':
			// ���Ɉړ�
			cursorY++;
			break;
	}
}