#pragma once
#include "DxLib.h"
#include "OnClickListener.h"
#include "Button.h"
#include "Mouse.h"

#include <iostream>
#include <string>

enum TitleMenu {
	���߂���, ��������, �ݒ�, �I��,
};

enum MatiChange {
	�҂��󂯉摜��ύX����, �҂��󂯉摜��ύX���Ȃ�
};

enum GameSeen {
	�^�C�g��, �^�C�g�����j���[, �^�C�g�����j���[��,
	���O����, ���O���͊m��, ���O���͖��m��,
	�����L������I��,
	���j���[�p�[�e�B�ݒ�,
	���j���[�����ꗗ,
	���j���[�Z�[�u, �Z�[�u��,
	���j���[�L�����ꗗ,
	���j���[�K�`��, �K�`���ڍ�,
	���j���[�N�G�X�g, �N�G�X�g�I��,
	���j���[�\�t�g���,
	�҂��󂯉��, �Z���t�g,
	����, �L����, �Q�[���I�[�o�[, �G���f�B���O, �I�[�v�j���O,
	�퓬, �키, �키�^�Q, ���@, ���@�ڍ�, ���@�^�Q, ���Z, ���Z�ڍ�, ���Z�^�Q, ������, �����鎸�s,
	�{�X�퓬
};

class Player {
private:
	FILE* file = 0;
	errno_t err = -1;
	char txt_name[20];
	char txt_name1[20];
	char kara[256] = "�e�X�g�v���C���[";
public:
	int mapX, mapY;
	char* Name;
	GameSeen MapName;
	int Num_PT; // �P�`�S�l�@�����߂͒N���ق��Ă��Ȃ��̂ŁA0�l
	Player()
	{
		Name = kara;
		MapName = �҂��󂯉��;
		mapX = 320, mapY = 200;
		Num_PT = 0;
	}

	int write(Player Data, const char* fileName);
	int lord(Player& Data, const char* fileName);
};

int Player::write(Player Data, const char* fileName)
{
	err = fopen_s(&file, fileName, "w");//�o�C�i���t�@�C�����J��
	if (err != 0) {
		return -1;
	}
	fprintf(file,"%d\n", Data.mapX);
	fprintf(file, "%d\n", Data.mapY);
	fprintf(file, "%s\n", Data.Name);
	fprintf(file, "%d\n", Data.MapName);
	fprintf(file, "%d\n", Data.Num_PT);

	fclose(file);//�t�@�C�������
	return 0;
}

int Player::lord(Player& Data, const char* fileName)
{
	int AnswerHandle = FileRead_open(fileName);
	if (AnswerHandle == -1)
	{
		return -1;
	}
	FileRead_gets(txt_name, 256, AnswerHandle);
	Data.mapX = std::stoi(txt_name);
	FileRead_gets(txt_name, 256, AnswerHandle);
	Data.mapY = std::stoi(txt_name);
	FileRead_gets(txt_name1, 256, AnswerHandle);
	Data.Name = txt_name1;
	FileRead_gets(txt_name, 256, AnswerHandle);
	Data.MapName = (GameSeen)std::stoi(txt_name);
	FileRead_gets(txt_name, 256, AnswerHandle);
	Data.Num_PT = std::stoi(txt_name);

	//FileRead_close(AnswerHandle);

	return 0;
}

class PTMenber {
private:
	FILE* file = 0;
	errno_t err = -1;
	char txt_name[20];
	char txt_name1[20];
	char txt_name2[20];
	char txt_name3[20];
	char txt_name4[20];
public:
	char* name;
	char kara[256] = "��f�[�^";
	int level;
	int str, maso, def, mdef, hp;
	int imgNum;
	char* zokusei;
	char* zukan;

	PTMenber()
	{
		name = kara;
		level = 1;
		str = 1, maso = 1, def = 1, mdef = 1,hp = 10;
		imgNum = -1;
		zokusei = kara;
		zukan = kara;
	}

	int write(PTMenber Data, const char* fileName);
	int lord(PTMenber& Data, const char* fileName);
};

int PTMenber::write(PTMenber Data, const char* fileName)
{
    err = fopen_s(&file, fileName, "w");//�o�C�i���t�@�C�����J��
	if (err != 0) {
		return -1;
	}
	fprintf(file, "%s\n", Data.name);
	fprintf(file, "%d\n", Data.level);
	fprintf(file, "%d\n", Data.str);
	fprintf(file, "%d\n", Data.def);
	fprintf(file, "%d\n", Data.maso);
	fprintf(file, "%d\n", Data.mdef);
	fprintf(file, "%d\n", Data.hp);
	fprintf(file, "%s\n", Data.zokusei);
	fprintf(file, "%d\n", Data.imgNum);
	fprintf(file, "%s\n", Data.zukan);
	fclose(file);//�t�@�C�������
	return 0;
}

int PTMenber::lord(PTMenber& Data, const char* fileName)
{
	int AnswerHandle = FileRead_open(fileName);
	if (AnswerHandle == -1)
	{
		return -1;
	}

	FileRead_gets(txt_name1, 256, AnswerHandle);
	Data.name = txt_name1;
	FileRead_gets(txt_name, 256, AnswerHandle);
	Data.level = std::stoi(txt_name);
	FileRead_gets(txt_name, 256, AnswerHandle);
	Data.str = std::stoi(txt_name);
	FileRead_gets(txt_name, 256, AnswerHandle);
	Data.def = std::stoi(txt_name);
	FileRead_gets(txt_name, 256, AnswerHandle);
	Data.maso = std::stoi(txt_name);
	FileRead_gets(txt_name, 256, AnswerHandle);
	Data.mdef = std::stoi(txt_name);
	FileRead_gets(txt_name, 256, AnswerHandle);
	Data.hp = std::stoi(txt_name);
	FileRead_gets(txt_name2, 256, AnswerHandle);
	Data.zokusei = txt_name2;
	FileRead_gets(txt_name3, 256, AnswerHandle);
	Data.imgNum = std::stoi(txt_name);
	FileRead_gets(txt_name4, 256, AnswerHandle);
	Data.zukan = txt_name4;

	//FileRead_close(AnswerHandle);

	return 0;
}

Player mPlayer;
PTMenber mPt[2];   // TODO:�摜�t�@�C���̃p�X�ǂݍ��݁@�G�l�~�[�͋�f�[�^���g��
PTMenber mMon[10]; // TODO:�K�`���Ńh���b�v���������X�^�[��ǂݏ�������i��������
PTMenber mEnemy[10];

const int mFont_RetryLoad = CreateFontToHandle("���C���I", 50, 9, DX_FONTTYPE_NORMAL);
GameSeen mAllSeen = �^�C�g��;
MatiChange mMatiFlg = �҂��󂯉摜��ύX���Ȃ�;
class Title : public OnClickListener {
	Button* mStartButton;

	Button* mHazimeButton;
	Button* mTudukiButton;
	Button* mSettingButton;
	Button* mEndButton;

	Button* mInpNameButton;
	Button* mCancelNameButton;

	Button* mKetteiTudukiButton;
	Button* mModoruTudukiButton;

	int nameLength = 0;
	int karaName = 0;
	int errKisoku = 0;
	char inputBuffer[256] = { 0 };
	int resultInput = 0;

	const int mFont_Daimei = CreateFontToHandle("���C���I", 70, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	const int mFont_Tuduki = CreateFontToHandle("�l�r �S�V�b�N", 20, 9, DX_FONTTYPE_NORMAL);

public:
	TitleMenu tMenu = ���߂���;

	Title()
	{
		mStartButton = new Button(260, 400, 100, 50, "�X�^�[�g");
		mStartButton->SetOnClickListener(this);

		mHazimeButton = new Button(80, 200, 100, 50, "���߂���");
		mHazimeButton->SetOnClickListener(this);

		mTudukiButton = new Button(200, 200, 100, 50, "��������");
		mTudukiButton->SetOnClickListener(this);

		mSettingButton = new Button(320, 200, 100, 50, "�ݒ�");
		mSettingButton->SetOnClickListener(this);

		mEndButton = new Button(440, 200, 100, 50, "�I��");
		mEndButton->SetOnClickListener(this);

		mInpNameButton = new Button(400, 50, 100, 50, "����");
		mInpNameButton->SetOnClickListener(this);

		mCancelNameButton = new Button(520, 50, 100, 50, "��蒼��");
		mCancelNameButton->SetOnClickListener(this);

		mKetteiTudukiButton = new Button(20, 180, 100, 50, "����");
		mKetteiTudukiButton->SetOnClickListener(this);

		mModoruTudukiButton = new Button(20, 240, 100, 50, "�߂�");
		mModoruTudukiButton->SetOnClickListener(this);
	}

	void Output(const int titleGHandle);
	void InputName(Player& player);
	void Tuduki(const int tudukiGHandle, Player& player);

	void OnClick(View* view)override;
};

void Title::Output(const int titleGHandle)
{
	if (mAllSeen == �^�C�g�� || mAllSeen == �^�C�g�����j���[)
	{
		/*** �^�C�g����ʂ̕`�� ***/
		DrawGraph(0, 0, titleGHandle, TRUE);
		/*** �薼�̕`�� ***/
		DrawStringToHandle(100, 100, "RPG����Ȃ�", GetColor(255, 255, 255), mFont_Daimei);
	}

	if (mAllSeen == �^�C�g�����j���[)
	{
		Mouse::Instance()->Update();
		mHazimeButton->Update();
		mTudukiButton->Update();
		mSettingButton->Update();
		mEndButton->Update();

		mHazimeButton->Draw();
		mTudukiButton->Draw();
		mSettingButton->Draw();
		mEndButton->Draw();
	}

	if (mAllSeen == �^�C�g��)
	{
		Mouse::Instance()->Update();
		mStartButton->Update();
		mStartButton->Draw();
	}
}

int ManualLength(const char* str) {
	size_t length = 0; // ���������J�E���g����ϐ�
	while (str[length] != '\0') { // �k�������ɒB����܂Ń��[�v
		length++; // �������𑝂₷
	}
	return length; // �ŏI�I�ȕ�������Ԃ�
}

int NyuryokuKisoku(const char* str) {
	size_t length = 0; // ���������J�E���g����ϐ�
	while (str[length] != '\0') { // �k�������ɒB����܂Ń��[�v

		if (str[length] == ' ' || str[length] == '�@')
		{
			return -1;
		}
		length++; // �������𑝂₷
	}
	return 0;
}

void Title::InputName(Player& player)
{
	if (tMenu == ���߂��� && mAllSeen == �^�C�g�����j���[��)
	{
		mAllSeen = ���O����;
	}
	else if (mAllSeen == ���O����)
	{
		/*** ���O���� ***/
		DrawString(100, 50, "���O����:�@�@�@�@�@�@�@�@�@�@\n         �S�p8�����܂œ��͉�", GetColor(255, 255, 0));
		resultInput = KeyInputString(200, 50, 256, inputBuffer, TRUE); // �L�[���͂��󂯎��
		DrawString(200, 100, inputBuffer, GetColor(255, 255, 255)); // ���͒��̕������\��

		nameLength = ManualLength(inputBuffer); // �����̒���
		karaName = strcmp(inputBuffer, ""); // �󕶎��̔�r
		errKisoku = NyuryokuKisoku(inputBuffer); // ���͋K���B�X�y�[�X�֎~
		
		if (resultInput == 1 && karaName > 0 && nameLength <= 8 * 2 && errKisoku == 0) { // ����8�����܂œ��͉�
			mAllSeen = ���O���͖��m��;
		}
	}
	else if (mAllSeen == ���O���͖��m��)
	{
		Mouse::Instance()->Update();
		mInpNameButton->Update();
		mCancelNameButton->Update();
		mInpNameButton->Draw();
		mCancelNameButton->Draw();


		DrawString(100, 50, "���O����:�@�@�@�@�@�@�@�@�@�@\n         �S�p8�����܂œ��͉�", GetColor(255, 255, 0));
		DrawString(200, 50, inputBuffer, GetColor(255, 255, 0));
	}
	else if (mAllSeen == ���O���͊m��)
	{
	retryPlayer:
		// ���O�ɕR�Â��������f�[�^��ǂݍ���
		char path[256] = "SyokiData\\�v���C���[.txt";
		int errPlayer = player.lord(player, path);
		if (errPlayer == -1)
		{
			WaitTimer(1000.0 / 60);
			DrawStringToHandle(100, 150, "�ǂݍ��ݒ�", GetColor(255, 255, 255), mFont_RetryLoad);
			goto retryPlayer;
		}
		player.Name = inputBuffer;

		mAllSeen = �����L������I��;
	}
}

GameSeen mZennkaiSave = �҂��󂯉��;
void Title::Tuduki(const int tudukiGHandle, Player& player) {
	if (tMenu == �������� && mAllSeen == �^�C�g�����j���[��)
	{
		/*** ������ʂ̕`�� ***/
		DrawGraph(0, 0, tudukiGHandle, TRUE);

		Mouse::Instance()->Update();
		mModoruTudukiButton->Update();
		mModoruTudukiButton->Draw();

		char path[256] = "SaveData\\�v���C���[.txt";
		int playerFlg = player.lord(player, path);
		mZennkaiSave = player.MapName;
		if (playerFlg == 0)
		{
			mKetteiTudukiButton->Update();
			mKetteiTudukiButton->Draw();

			std::string str1;
			const char* path1;
			int errPt = -1;
			for (int i = 0; i < player.Num_PT; i++)
			{
				retryPt:
				std::string str1 = "SaveData\\�p�[�e�B�[" + std::to_string(i + 1) + "�l��.txt";
				path1 = str1.c_str();
				mPt[i].lord(mPt[i], path1);

				//TODO;�摜�f�[�^�ǂݍ���

				if (errPt == -1)
				{
					WaitTimer(1000.0 / 60);
					DrawStringToHandle(100, 150, "�ǂݍ��ݒ�", GetColor(255, 255, 255), mFont_RetryLoad);
					goto retryPt;
				}
			}
		}
		else if (playerFlg == -1)
		{
			/*** �����f�[�^�̕`�� ***/
			DrawStringToHandle(100, 150, "�Z�[�u�f�[�^������܂���B", GetColor(255, 255, 255), mFont_Tuduki);
		}
	}
}

class Kihon : public OnClickListener {
private:
	Button* mKetteiButton;
	Button* mResetButton;
	Button* mModoruButton;
	Button* mUpButton;
	Button* mDownButton;

	FILE* file = 0;
	errno_t err = -1;

	char name[20];
	char* mfileName;
	int mVolume = 0;
	bool SyokiFlg = false;

	const int mFont_Vlume = CreateFontToHandle("�l�r �S�V�b�N", 50, 3, DX_FONTTYPE_NORMAL);
public:

	Kihon()
	{
		mKetteiButton = new Button(220, 400, 100, 50, "����");
		mKetteiButton->SetOnClickListener(this);

		mResetButton = new Button(80, 200, 100, 50, "���Z�b�g");
		mResetButton->SetOnClickListener(this);

		mModoruButton = new Button(340, 400, 100, 50, "�߂�");
		mModoruButton->SetOnClickListener(this);

		mUpButton = new Button(280, 200, 100, 50, "�グ��");
		mUpButton->SetOnClickListener(this);

		mDownButton = new Button(400, 200, 100, 50, "������");
		mDownButton->SetOnClickListener(this);
	}

	void Setting(char* fileName, int volume, Title title);
	int WriteVolume(int volume, char* fileName);
	int LoadVolume(int& volume, char* fileName);

	void OnClick(View* view)override;
};

void Kihon::Setting(char* fileName, int volume, Title title) {

	if (title.tMenu == �ݒ� && mAllSeen == �^�C�g�����j���[��)
	{
		SetVolumeMusic(volume);

		Mouse::Instance()->Update();
		mKetteiButton->Update();
		mResetButton->Update();
		mModoruButton->Update();
		mUpButton->Update();
		mDownButton->Update();

		mKetteiButton->Draw();
		mResetButton->Draw();
		mModoruButton->Draw();
		mUpButton->Draw();
		mDownButton->Draw();

		mfileName = fileName;
		if (SyokiFlg == false && mVolume < 255)
		{
			LoadVolume(mVolume, mfileName);
		}

		DrawStringToHandle(120, 100, "����:", GetColor(255, 255, 255), mFont_Vlume);
		int cnt = 0;
		for (int i = 0; i < mVolume; i += 15)
		{
            DrawStringToHandle(240 + cnt * 10, 100 , "|", GetColor(255, 255, 255), mFont_Vlume);
			cnt++;
		}
	}
}
int Kihon::WriteVolume(int volume, char* fileName)
{
	err = fopen_s(&file, fileName, "w");
	if (err != 0) {
		return -1;
	}
	fprintf(file, "%s %d.\n", "Volume", volume);
	fclose(file);//�t�@�C�������
	return 0;
}

int Kihon::LoadVolume(int& volume, char* fileName)
{
	err = fopen_s(&file, fileName, "r");
	if (err != 0) {
		return -1;
	}
    fscanf_s(file, "%19s %d.", name, (unsigned)_countof(name), &volume);
	fclose(file);

	return 0;
}

// �J�E���^�[
int WaitCounter;	// ���Ԍv���p
int NowTime;	// ���݂̃t���[���Ōo�߂�������
int OldTime;	// �O�̃t���[���̂Ƃ���GetNowCount�֐��œ����^�C��

// ���ԏ���
int TimeFunc(int waitTime)
{
	int Time;

	// ���݂̎��Ԃ𓾂�
	Time = GetNowCount();

	// ���t���[���Ōo�߂������Ԃ𓾂�
	NowTime = Time - OldTime;

	// ���݂̎��Ԃ�ۑ�
	OldTime = Time;

	// �E�G�C�g�J�E���^�Ɍo�ߎ��Ԃ����Z����
	WaitCounter += NowTime;

	// ��莞�Ԃ��o��
	if (WaitCounter > waitTime)
	{

		// �J�E���^�[���O�ɖ߂�
		WaitCounter = 0;
		return 1;
	}

	// �I��
	return 0;
}

class SyokiKyara : public OnClickListener {
private:
	Button* mKyara1Button;
	Button* mKyara2Button;
	Button* mKyara3Button;

	const int mFont_Status = CreateFontToHandle("�l�r �S�V�b�N", 20, 9, DX_FONTTYPE_NORMAL);
public:

	SyokiKyara()
	{
		mKyara1Button = new Button(0+50, 420, 100, 50, "�I��");
		mKyara1Button->SetOnClickListener(this);

		mKyara2Button = new Button(215+50, 420, 100, 50, "�I��");
		mKyara2Button->SetOnClickListener(this);

		mKyara3Button = new Button(430+50, 420, 100, 50, "�I��");
		mKyara3Button->SetOnClickListener(this);
	}

	void Select(const int mon1Handle, const int mon2Handle, const int mon3Handle);

	void OnClick(View* view)override;
};

char* intToCharArray(int num)
{
	std::string str = std::to_string(num); // int��std::string�ɕϊ�
	char charArray[100];                     // �\���ȃT�C�Y��char�z���p��
	strcpy_s(charArray, str.c_str());     // std::string��char�z��ɃR�s�[
	return charArray;
}

void SyokiKyara::Select(const int mon1Handle, const int mon2Handle, const int mon3Handle)
{
	if (mAllSeen == �����L������I��)
	{
		/*** �L����1�̕`�� ***/
		DrawGraph(0, 0, mon1Handle, TRUE);
		/*** �L����2�̕`�� ***/
		DrawGraph(215, 0, mon2Handle, TRUE);
		/*** �L����3�̕`�� ***/
		DrawGraph(430, 0, mon3Handle, TRUE);

		// 3�L�����̃X�e�[�^�X�\��
		for (int i = 0; i < 3; i++)
		{
			DrawStringToHandle(30 + 215 * i, 170, "���O�F", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 170, mEnemy[i].name, GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 200, "�����F", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 200, mEnemy[i].zokusei, GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 230, "  Lv�F", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 230, intToCharArray(mEnemy[i].level), GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 260, "  HP�F", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 260, intToCharArray(mEnemy[i].hp), GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 290, " Str�F", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 290, intToCharArray(mEnemy[i].str), GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 320, " Def�F", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 320, intToCharArray(mEnemy[i].def), GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 350, " Int�F", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 350, intToCharArray(mEnemy[i].maso), GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 380, "Mdef�F", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 380, intToCharArray(mEnemy[i].mdef), GetColor(255, 255, 255), mFont_Status);
		}
		Mouse::Instance()->Update();
		mKyara1Button->Update();
		mKyara1Button->Draw();
		mKyara2Button->Update();
		mKyara2Button->Draw();
		mKyara3Button->Update();
		mKyara3Button->Draw();
	}
}

class GameMain : public OnClickListener {
private:
	Button* mPtSetButton;
	Button* mSoubiButton;
	Button* mSaveButton;
	Button* mKyaraButton;
	Button* mGatyaButton;
	Button* mQuestButton;
	Button* mSoftButton;
public:

	GameMain()
	{
		mPtSetButton = new Button(0 + 30, 420, 100, 50, "�p�[�e�B�Ґ�");
		mPtSetButton->SetOnClickListener(this);

		mSoubiButton = new Button(120 + 30, 420, 100, 50, "�����ꗗ");
		mSoubiButton->SetOnClickListener(this);

		mSaveButton = new Button(240 + 30, 420, 100, 50, "�Z�[�u");
		mSaveButton->SetOnClickListener(this);

		mKyaraButton = new Button(360 + 30, 420, 100, 50, "�L�����ꗗ");
		mKyaraButton->SetOnClickListener(this);

		mGatyaButton = new Button(480 + 30, 420, 100, 50, "�K�`��");
		mGatyaButton->SetOnClickListener(this);

		mQuestButton = new Button(30, 320, 100, 50, "�N�G�X�g");
		mQuestButton->SetOnClickListener(this);

		mSoftButton = new Button(30, 220, 100, 50, "�\�t�g���");
		mSoftButton->SetOnClickListener(this);
	}

	void Play(const int matiWakuHandle, const int  matiImgHandle);

	void OnClick(View* view)override;
};

void GameMain::Play(const int matiWakuHandle, const int  matiImgHandle)
{
	if (mAllSeen == �҂��󂯉��)
	{
		/*** �҂��󂯉�ʂ̕`�� ***/
		DrawGraph(0, 0, matiWakuHandle, TRUE);
		/*** �҂��󂯉摜�̕`�� ***/
		DrawGraph(320, 240, matiImgHandle, TRUE);
		Mouse::Instance()->Update();
		mPtSetButton->Update();
		mPtSetButton->Draw();
		mSoubiButton->Update();
		mSoubiButton->Draw();
		mSaveButton->Update();
		mSaveButton->Draw();
		mKyaraButton->Update();
		mKyaraButton->Draw();
		mGatyaButton->Update();
		mGatyaButton->Draw();

		mQuestButton->Update();
		mQuestButton->Draw();
		mSoftButton->Update();
		mSoftButton->Draw();	
	}
}

class MenuPt : public OnClickListener {
private:
	//Button* mPtSetButton;
public:

	MenuPt()
	{
		//mPtSetButton = new Button(0 + 30, 420, 100, 50, "�ҏW");
		//mPtSetButton->SetOnClickListener(this);

		//mPtSetButton = new Button(0 + 30, 420, 100, 50, "�ҏW");
		//mPtSetButton->SetOnClickListener(this);

		//mPtSetButton = new Button(0 + 30, 420, 100, 50, "�ҏW");
		//mPtSetButton->SetOnClickListener(this);

		//mPtSetButton = new Button(0 + 30, 420, 100, 50, "�߂�");
		//mPtSetButton->SetOnClickListener(this);
	}

	void OnClick(View* view)override;
};

void Title::OnClick(View* view) {
	if (view == mStartButton) {
		mAllSeen = �^�C�g�����j���[;
	}
	if (view == mHazimeButton) {
		tMenu = ���߂���;
		mAllSeen = �^�C�g�����j���[��;
	}
	if (view == mTudukiButton) {
		tMenu = ��������;
		mAllSeen = �^�C�g�����j���[��;
	}
	if (view == mSettingButton) {
		tMenu = �ݒ�;
		mAllSeen = �^�C�g�����j���[��;
	}
	if (view == mEndButton) {
		tMenu = �I��;
		mAllSeen = �^�C�g�����j���[��;
	}
	if (view == mInpNameButton) {
		mAllSeen = ���O���͊m��;
	}
	if (view == mCancelNameButton) {
		mAllSeen = ���O����;
	}
	if (view == mKetteiTudukiButton) {
		mAllSeen = mZennkaiSave; // �O��̕ۑ��f�[�^
	}
	if (view == mModoruTudukiButton) {
		mAllSeen = �^�C�g�����j���[;
	}
	
}

void Kihon::OnClick(View* view)
{
	if (view == mKetteiButton) {
		mAllSeen = �^�C�g�����j���[;
		WriteVolume(mVolume, mfileName);
		SyokiFlg = false;
	}
	if (view == mResetButton) {
		mVolume = 255;
		SyokiFlg = false;
	}
	if (view == mModoruButton) {
		mAllSeen = �^�C�g�����j���[;
		LoadVolume(mVolume, mfileName);
		SyokiFlg = false;
	}
	if (view == mUpButton) {
		mVolume += 15; // 255��15=17����
		if (mVolume > 255)
		{
			mVolume = 255;
		}
		SyokiFlg = true;
	}
	if (view == mDownButton) {
		mVolume -= 15;
		if (mVolume < 0)
		{
			mVolume = 0;
		}
		SyokiFlg = true;
	}
	SetVolumeMusic(mVolume);
}

void SyokiKyara::OnClick(View* view)
{
	char str1[256] = "�}�ӂ���";
	if (view == mKyara1Button) {
		mPt[0] = mMon[0] = mEnemy[0];
		mPt[0].imgNum = 1;
		mPt[0].zukan = mMon[0].zukan = str1;
	}
	if (view == mKyara2Button) {
		mPt[0] = mMon[1] = mEnemy[1];
		mPt[0].imgNum = 2;
		mPt[0].zukan = mMon[1].zukan = str1;
	}
	if (view == mKyara3Button) {
		mPt[0] = mMon[2] = mEnemy[2];
		mPt[0].imgNum = 3;
		mPt[0].zukan = mMon[2].zukan = str1;
	}
	mAllSeen = �҂��󂯉��;
	mMatiFlg = �҂��󂯉摜��ύX����;
}

void GameMain::OnClick(View* view)
{
	if (view == mPtSetButton) {
		mAllSeen = ���j���[�p�[�e�B�ݒ�;
	}
	if (view == mSoubiButton) {
		mAllSeen = ���j���[�����ꗗ;
	}
	if (view == mSaveButton) {
		mAllSeen = ���j���[�Z�[�u;
	}
	if (view == mKyaraButton) {
		mAllSeen = ���j���[�L�����ꗗ;
	}
	if (view == mGatyaButton) {
		mAllSeen = ���j���[�K�`��;
	}
	if (view == mQuestButton) {
		mAllSeen = ���j���[�N�G�X�g;
	}
	if (view == mSoftButton) {
		mAllSeen = ���j���[�\�t�g���;
	}
}

void MenuPt::OnClick(View* view)
{
	//if (view == mPtSetButton) {
		//mAllSeen = ���j���[�p�[�e�B�ݒ�;
	//}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);
	// DX���C�u��������������
	if (DxLib_Init() < 0) {
		//�G���[�Ȃ�I������
		DxLib_End();    // DX���C�u�����I������
		return -1;
	}
	Title title;
	Kihon kihon;
	SyokiKyara syokiKyara;
	GameMain gameMain;

	const int titleHandle = LoadGraph("backImg\\Title.png");
	const int tudukiHandle = LoadGraph("backImg\\Tuduki.png");
	const int matiWakuHandle = LoadGraph("backImg\\�҂��󂯉��.png");

	if (titleHandle > 0 || tudukiHandle > 0 || matiWakuHandle > 0) {
	}
	else {
		MessageBox(NULL, "�C���[�W�Y�̓Ǎ����s", "�G���[", MB_ICONERROR | MB_OK);
		DxLib_End();    // DX���C�u�����I������
		return 0;
	}
	int monHandle[10] = { 0 }; // �S�Ẵ����X�^�[10��

	std::string str1;
	const char* monFile1;
	std::string strErr1;

	std::string str2;
	const char* monFile2;
	std::string strErr2;

	std::string str3;
	const char* monFile3;
	int matiImgHandle = -1;

	// �S�ẴG�l�~�[��ǂݍ���
	int errValue = -1;
	int numValue = sizeof(monHandle) / sizeof(int);
	for (int i = 0; i < numValue; i++)
	{
		str1 = "SyokiData\\�����X�^�[" + std::to_string(i + 1) + ".txt";
		monFile1 = str1.c_str();
		errValue = mEnemy[i].lord(mEnemy[i], monFile1);

		strErr1 = str1 + "�̓Ǎ����s";
		if (errValue == -1) {
			MessageBox(NULL, strErr1.c_str(), "�G���[", MB_ICONERROR | MB_OK);
			DxLib_End();    // DX���C�u�����I������
			return 0;
		}

		str2 = "monImg\\�����X�^�[" + std::to_string(i + 1) + ".png";
		monFile2 = str2.c_str();
		monHandle[i] = LoadGraph(monFile2);

		strErr2 = str2 + "�̓Ǎ����s";
		if (monHandle[i] > 0) {
		}
		else {
			MessageBox(NULL, strErr2.c_str(), "�G���[", MB_ICONERROR | MB_OK);
			DxLib_End();    // DX���C�u�����I������
			return 0;
		}
	}

	int volume = 0;
	char volumePath[256] = "SaveData\\��ʐݒ�.txt";
	char syokiVolumePath[256] = "SyokiData\\��ʐݒ�.txt";
	// ���ʒl�̓ǂݍ���
	int errVolume = kihon.LoadVolume(volume, volumePath);
	// �����f�[�^�ǂݍ���
	if (errVolume == -1)
	{
		errVolume = kihon.LoadVolume(volume, syokiVolumePath);
		if (errVolume == -1) {
			MessageBox(NULL, "���ʃt�@�C���̓Ǎ����s", "�G���[", MB_ICONERROR | MB_OK);
			DxLib_End();    // DX���C�u�����I������
			return 0;
		}
		errVolume = kihon.WriteVolume(volume, volumePath);
		if (errVolume == -1) {
			MessageBox(NULL, "���ʃt�@�C���̏������s", "�G���[", MB_ICONERROR | MB_OK);
			DxLib_End();    // DX���C�u�����I������
			return 0;
		}
	}
	SetVolumeMusic(volume);

	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		if (ProcessMessage() != 0) { // ���b�Z�[�W����
			break;//�E�B���h�E�́~�{�^���������ꂽ�烋�[�v�𔲂���
		}
		if (title.tMenu == �I��)
		{
			break;
		}
		WaitTimer(1000.0 / 60);

		ClearDrawScreen(); // ��ʂ�����

		title.Output(titleHandle); // �^�C�g����`��
		title.InputName(mPlayer); // ���O����
		title.Tuduki(tudukiHandle, mPlayer); // ��������
		kihon.Setting(volumePath, volume, title); // �ݒ�

		syokiKyara.Select(monHandle[0], monHandle[1], monHandle[2]);// �����L������I��

		if (mMatiFlg == �҂��󂯉摜��ύX����)
		{
			str3 = "monImg\\�����X�^�[" + std::to_string(mPt[0].imgNum) + ".png";
			monFile3 = str3.c_str();
			matiImgHandle = LoadGraph(monFile3);
			mMatiFlg = �҂��󂯉摜��ύX���Ȃ�;

			if (matiImgHandle > 0) {
			}
			else {
				MessageBox(NULL, strErr2.c_str(), "�G���[", MB_ICONERROR | MB_OK);
				DxLib_End();    // DX���C�u�����I������
				return 0;
			}
		}
		gameMain.Play(matiWakuHandle, matiImgHandle); // �Q�[�����v���C

		ScreenFlip(); //����ʂ�\��ʂɔ��f
	}

	DxLib_End();    // DX���C�u�����I������
	return 0;
}