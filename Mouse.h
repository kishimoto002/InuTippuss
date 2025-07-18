#pragma once

#include "Singleton.h"

class Mouse : public Singleton<Mouse> {

	Mouse();
	friend Singleton<Mouse>;

public:
	bool Update();	//�X�V
	int GetPressingCount(int keyCode);//keyCode�̃L�[��������Ă���t���[�������擾
	int GetReleasingCount(int keyCode);//keyCode�̃L�[��������Ă���t���[�������擾
	int GetX();
	int GetY();
	const static int LEFT   = 0;
	const static int RIGHT  = 1;
	const static int MIDDLE = 2;

private:
	const static int BUTTON_NUM = 8;
	int mKeyPressingCount [BUTTON_NUM];//������J�E���^
	int mKeyReleasingCount[BUTTON_NUM];//������J�E���^
	int mX, mY;

	bool IsAvailableCode(int keyCode);//keyCode���L���ȃL�[�ԍ����₤
};
