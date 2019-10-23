#pragma once
#include "StoneManager.h"

// �c��
const int BOARD_HEIGHT = 8;
// ����
const int BOARD_WEIGHT = 8;

// �{�[�h�̏��
enum EBoadState
{
	NONE		= -1,		// �����Ȃ�
	BLACK_STONE =  0,       // ����΂��u���Ă���
	WHITE_STONE =  1,       // ����΂��u���Ă���
};

class CBoardManager
{
public:
	// �R���X�g���N�^
	CBoardManager();
	//������
	void Initialize();
	// �{�[�h�̕\��
	void DispBoard(CStoneManager* cStone);
	//board�̃A�N�Z�T
	void SetBoard(int vecY, int vecX, int state) { board[vecY][vecX] = state; };

private:
	// �{�[�h
	int board[BOARD_HEIGHT][BOARD_WEIGHT];
};
