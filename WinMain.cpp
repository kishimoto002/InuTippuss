#pragma once
#include "DxLib.h"
#include "OnClickListener.h"
#include "Button.h"
#include "Mouse.h"

#include <iostream>
#include <string>

enum TitleMenu {
	初めから, 続きから, 設定, 終了,
};

enum MatiChange {
	待ち受け画像を変更する, 待ち受け画像を変更しない
};

enum GameSeen {
	タイトル, タイトルメニュー, タイトルメニュー中,
	名前入力, 名前入力確定, 名前入力未確定,
	初期キャラを選択,
	メニューパーティ設定,
	メニュー装備一覧,
	メニューセーブ, セーブ中,
	メニューキャラ一覧,
	メニューガチャ, ガチャ詳細,
	メニュークエスト, クエスト選択,
	メニューソフト解説,
	待ち受け画面, セリフ枠,
	装備, キャラ, ゲームオーバー, エンディング, オープニング,
	戦闘, 戦う, 戦うタゲ, 魔法, 魔法詳細, 魔法タゲ, 特技, 特技詳細, 特技タゲ, 逃げる, 逃げる失敗,
	ボス戦闘
};

class Player {
private:
	FILE* file = 0;
	errno_t err = -1;
	char txt_name[20];
	char txt_name1[20];
	char kara[256] = "テストプレイヤー";
public:
	int mapX, mapY;
	char* Name;
	GameSeen MapName;
	int Num_PT; // １～４人　※初めは誰も雇っていないので、0人
	Player()
	{
		Name = kara;
		MapName = 待ち受け画面;
		mapX = 320, mapY = 200;
		Num_PT = 0;
	}

	int write(Player Data, const char* fileName);
	int lord(Player& Data, const char* fileName);
};

int Player::write(Player Data, const char* fileName)
{
	err = fopen_s(&file, fileName, "w");//バイナリファイルを開く
	if (err != 0) {
		return -1;
	}
	fprintf(file,"%d\n", Data.mapX);
	fprintf(file, "%d\n", Data.mapY);
	fprintf(file, "%s\n", Data.Name);
	fprintf(file, "%d\n", Data.MapName);
	fprintf(file, "%d\n", Data.Num_PT);

	fclose(file);//ファイルを閉じる
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
	char kara[256] = "空データ";
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
    err = fopen_s(&file, fileName, "w");//バイナリファイルを開く
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
	fclose(file);//ファイルを閉じる
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
PTMenber mPt[2];   // TODO:画像ファイルのパス読み込み　エネミーは空データを使う
PTMenber mMon[10]; // TODO:ガチャでドロップしたモンスターを読み書きする（成長あり
PTMenber mEnemy[10];

const int mFont_RetryLoad = CreateFontToHandle("メイリオ", 50, 9, DX_FONTTYPE_NORMAL);
GameSeen mAllSeen = タイトル;
MatiChange mMatiFlg = 待ち受け画像を変更しない;
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

	const int mFont_Daimei = CreateFontToHandle("メイリオ", 70, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	const int mFont_Tuduki = CreateFontToHandle("ＭＳ ゴシック", 20, 9, DX_FONTTYPE_NORMAL);

public:
	TitleMenu tMenu = 初めから;

	Title()
	{
		mStartButton = new Button(260, 400, 100, 50, "スタート");
		mStartButton->SetOnClickListener(this);

		mHazimeButton = new Button(80, 200, 100, 50, "初めから");
		mHazimeButton->SetOnClickListener(this);

		mTudukiButton = new Button(200, 200, 100, 50, "続きから");
		mTudukiButton->SetOnClickListener(this);

		mSettingButton = new Button(320, 200, 100, 50, "設定");
		mSettingButton->SetOnClickListener(this);

		mEndButton = new Button(440, 200, 100, 50, "終了");
		mEndButton->SetOnClickListener(this);

		mInpNameButton = new Button(400, 50, 100, 50, "決定");
		mInpNameButton->SetOnClickListener(this);

		mCancelNameButton = new Button(520, 50, 100, 50, "やり直す");
		mCancelNameButton->SetOnClickListener(this);

		mKetteiTudukiButton = new Button(20, 180, 100, 50, "決定");
		mKetteiTudukiButton->SetOnClickListener(this);

		mModoruTudukiButton = new Button(20, 240, 100, 50, "戻る");
		mModoruTudukiButton->SetOnClickListener(this);
	}

	void Output(const int titleGHandle);
	void InputName(Player& player);
	void Tuduki(const int tudukiGHandle, Player& player);

	void OnClick(View* view)override;
};

void Title::Output(const int titleGHandle)
{
	if (mAllSeen == タイトル || mAllSeen == タイトルメニュー)
	{
		/*** タイトル画面の描画 ***/
		DrawGraph(0, 0, titleGHandle, TRUE);
		/*** 題名の描画 ***/
		DrawStringToHandle(100, 100, "RPGじゃない", GetColor(255, 255, 255), mFont_Daimei);
	}

	if (mAllSeen == タイトルメニュー)
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

	if (mAllSeen == タイトル)
	{
		Mouse::Instance()->Update();
		mStartButton->Update();
		mStartButton->Draw();
	}
}

int ManualLength(const char* str) {
	size_t length = 0; // 文字数をカウントする変数
	while (str[length] != '\0') { // ヌル文字に達するまでループ
		length++; // 文字数を増やす
	}
	return length; // 最終的な文字数を返す
}

int NyuryokuKisoku(const char* str) {
	size_t length = 0; // 文字数をカウントする変数
	while (str[length] != '\0') { // ヌル文字に達するまでループ

		if (str[length] == ' ' || str[length] == '　')
		{
			return -1;
		}
		length++; // 文字数を増やす
	}
	return 0;
}

void Title::InputName(Player& player)
{
	if (tMenu == 初めから && mAllSeen == タイトルメニュー中)
	{
		mAllSeen = 名前入力;
	}
	else if (mAllSeen == 名前入力)
	{
		/*** 名前入力 ***/
		DrawString(100, 50, "名前入力:　　　　　　　　　　\n         全角8文字まで入力可", GetColor(255, 255, 0));
		resultInput = KeyInputString(200, 50, 256, inputBuffer, TRUE); // キー入力を受け取る
		DrawString(200, 100, inputBuffer, GetColor(255, 255, 255)); // 入力中の文字列を表示

		nameLength = ManualLength(inputBuffer); // 文字の長さ
		karaName = strcmp(inputBuffer, ""); // 空文字の比較
		errKisoku = NyuryokuKisoku(inputBuffer); // 入力規制。スペース禁止
		
		if (resultInput == 1 && karaName > 0 && nameLength <= 8 * 2 && errKisoku == 0) { // 漢字8文字まで入力可
			mAllSeen = 名前入力未確定;
		}
	}
	else if (mAllSeen == 名前入力未確定)
	{
		Mouse::Instance()->Update();
		mInpNameButton->Update();
		mCancelNameButton->Update();
		mInpNameButton->Draw();
		mCancelNameButton->Draw();


		DrawString(100, 50, "名前入力:　　　　　　　　　　\n         全角8文字まで入力可", GetColor(255, 255, 0));
		DrawString(200, 50, inputBuffer, GetColor(255, 255, 0));
	}
	else if (mAllSeen == 名前入力確定)
	{
	retryPlayer:
		// 名前に紐づいた初期データを読み込み
		char path[256] = "SyokiData\\プレイヤー.txt";
		int errPlayer = player.lord(player, path);
		if (errPlayer == -1)
		{
			WaitTimer(1000.0 / 60);
			DrawStringToHandle(100, 150, "読み込み中", GetColor(255, 255, 255), mFont_RetryLoad);
			goto retryPlayer;
		}
		player.Name = inputBuffer;

		mAllSeen = 初期キャラを選択;
	}
}

GameSeen mZennkaiSave = 待ち受け画面;
void Title::Tuduki(const int tudukiGHandle, Player& player) {
	if (tMenu == 続きから && mAllSeen == タイトルメニュー中)
	{
		/*** 続き画面の描画 ***/
		DrawGraph(0, 0, tudukiGHandle, TRUE);

		Mouse::Instance()->Update();
		mModoruTudukiButton->Update();
		mModoruTudukiButton->Draw();

		char path[256] = "SaveData\\プレイヤー.txt";
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
				std::string str1 = "SaveData\\パーティー" + std::to_string(i + 1) + "人目.txt";
				path1 = str1.c_str();
				mPt[i].lord(mPt[i], path1);

				//TODO;画像データ読み込み

				if (errPt == -1)
				{
					WaitTimer(1000.0 / 60);
					DrawStringToHandle(100, 150, "読み込み中", GetColor(255, 255, 255), mFont_RetryLoad);
					goto retryPt;
				}
			}
		}
		else if (playerFlg == -1)
		{
			/*** 続きデータの描画 ***/
			DrawStringToHandle(100, 150, "セーブデータがありません。", GetColor(255, 255, 255), mFont_Tuduki);
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

	const int mFont_Vlume = CreateFontToHandle("ＭＳ ゴシック", 50, 3, DX_FONTTYPE_NORMAL);
public:

	Kihon()
	{
		mKetteiButton = new Button(220, 400, 100, 50, "決定");
		mKetteiButton->SetOnClickListener(this);

		mResetButton = new Button(80, 200, 100, 50, "リセット");
		mResetButton->SetOnClickListener(this);

		mModoruButton = new Button(340, 400, 100, 50, "戻る");
		mModoruButton->SetOnClickListener(this);

		mUpButton = new Button(280, 200, 100, 50, "上げる");
		mUpButton->SetOnClickListener(this);

		mDownButton = new Button(400, 200, 100, 50, "下げる");
		mDownButton->SetOnClickListener(this);
	}

	void Setting(char* fileName, int volume, Title title);
	int WriteVolume(int volume, char* fileName);
	int LoadVolume(int& volume, char* fileName);

	void OnClick(View* view)override;
};

void Kihon::Setting(char* fileName, int volume, Title title) {

	if (title.tMenu == 設定 && mAllSeen == タイトルメニュー中)
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

		DrawStringToHandle(120, 100, "音量:", GetColor(255, 255, 255), mFont_Vlume);
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
	fclose(file);//ファイルを閉じる
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

// カウンター
int WaitCounter;	// 時間計測用
int NowTime;	// 現在のフレームで経過した時間
int OldTime;	// 前のフレームのときにGetNowCount関数で得たタイム

// 時間処理
int TimeFunc(int waitTime)
{
	int Time;

	// 現在の時間を得る
	Time = GetNowCount();

	// 今フレームで経過した時間を得る
	NowTime = Time - OldTime;

	// 現在の時間を保存
	OldTime = Time;

	// ウエイトカウンタに経過時間を加算する
	WaitCounter += NowTime;

	// 一定時間が経過
	if (WaitCounter > waitTime)
	{

		// カウンターを０に戻す
		WaitCounter = 0;
		return 1;
	}

	// 終了
	return 0;
}

class SyokiKyara : public OnClickListener {
private:
	Button* mKyara1Button;
	Button* mKyara2Button;
	Button* mKyara3Button;

	const int mFont_Status = CreateFontToHandle("ＭＳ ゴシック", 20, 9, DX_FONTTYPE_NORMAL);
public:

	SyokiKyara()
	{
		mKyara1Button = new Button(0+50, 420, 100, 50, "選択");
		mKyara1Button->SetOnClickListener(this);

		mKyara2Button = new Button(215+50, 420, 100, 50, "選択");
		mKyara2Button->SetOnClickListener(this);

		mKyara3Button = new Button(430+50, 420, 100, 50, "選択");
		mKyara3Button->SetOnClickListener(this);
	}

	void Select(const int mon1Handle, const int mon2Handle, const int mon3Handle);

	void OnClick(View* view)override;
};

char* intToCharArray(int num)
{
	std::string str = std::to_string(num); // intをstd::stringに変換
	char charArray[100];                     // 十分なサイズのchar配列を用意
	strcpy_s(charArray, str.c_str());     // std::stringをchar配列にコピー
	return charArray;
}

void SyokiKyara::Select(const int mon1Handle, const int mon2Handle, const int mon3Handle)
{
	if (mAllSeen == 初期キャラを選択)
	{
		/*** キャラ1の描画 ***/
		DrawGraph(0, 0, mon1Handle, TRUE);
		/*** キャラ2の描画 ***/
		DrawGraph(215, 0, mon2Handle, TRUE);
		/*** キャラ3の描画 ***/
		DrawGraph(430, 0, mon3Handle, TRUE);

		// 3キャラのステータス表示
		for (int i = 0; i < 3; i++)
		{
			DrawStringToHandle(30 + 215 * i, 170, "名前：", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 170, mEnemy[i].name, GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 200, "属性：", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 200, mEnemy[i].zokusei, GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 230, "  Lv：", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 230, intToCharArray(mEnemy[i].level), GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 260, "  HP：", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 260, intToCharArray(mEnemy[i].hp), GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 290, " Str：", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 290, intToCharArray(mEnemy[i].str), GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 320, " Def：", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 320, intToCharArray(mEnemy[i].def), GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 350, " Int：", GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(90 + 215 * i, 350, intToCharArray(mEnemy[i].maso), GetColor(255, 255, 255), mFont_Status);
			DrawStringToHandle(30 + 215 * i, 380, "Mdef：", GetColor(255, 255, 255), mFont_Status);
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
		mPtSetButton = new Button(0 + 30, 420, 100, 50, "パーティ編成");
		mPtSetButton->SetOnClickListener(this);

		mSoubiButton = new Button(120 + 30, 420, 100, 50, "装備一覧");
		mSoubiButton->SetOnClickListener(this);

		mSaveButton = new Button(240 + 30, 420, 100, 50, "セーブ");
		mSaveButton->SetOnClickListener(this);

		mKyaraButton = new Button(360 + 30, 420, 100, 50, "キャラ一覧");
		mKyaraButton->SetOnClickListener(this);

		mGatyaButton = new Button(480 + 30, 420, 100, 50, "ガチャ");
		mGatyaButton->SetOnClickListener(this);

		mQuestButton = new Button(30, 320, 100, 50, "クエスト");
		mQuestButton->SetOnClickListener(this);

		mSoftButton = new Button(30, 220, 100, 50, "ソフト解説");
		mSoftButton->SetOnClickListener(this);
	}

	void Play(const int matiWakuHandle, const int  matiImgHandle);

	void OnClick(View* view)override;
};

void GameMain::Play(const int matiWakuHandle, const int  matiImgHandle)
{
	if (mAllSeen == 待ち受け画面)
	{
		/*** 待ち受け画面の描画 ***/
		DrawGraph(0, 0, matiWakuHandle, TRUE);
		/*** 待ち受け画像の描画 ***/
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
		//mPtSetButton = new Button(0 + 30, 420, 100, 50, "編集");
		//mPtSetButton->SetOnClickListener(this);

		//mPtSetButton = new Button(0 + 30, 420, 100, 50, "編集");
		//mPtSetButton->SetOnClickListener(this);

		//mPtSetButton = new Button(0 + 30, 420, 100, 50, "編集");
		//mPtSetButton->SetOnClickListener(this);

		//mPtSetButton = new Button(0 + 30, 420, 100, 50, "戻る");
		//mPtSetButton->SetOnClickListener(this);
	}

	void OnClick(View* view)override;
};

void Title::OnClick(View* view) {
	if (view == mStartButton) {
		mAllSeen = タイトルメニュー;
	}
	if (view == mHazimeButton) {
		tMenu = 初めから;
		mAllSeen = タイトルメニュー中;
	}
	if (view == mTudukiButton) {
		tMenu = 続きから;
		mAllSeen = タイトルメニュー中;
	}
	if (view == mSettingButton) {
		tMenu = 設定;
		mAllSeen = タイトルメニュー中;
	}
	if (view == mEndButton) {
		tMenu = 終了;
		mAllSeen = タイトルメニュー中;
	}
	if (view == mInpNameButton) {
		mAllSeen = 名前入力確定;
	}
	if (view == mCancelNameButton) {
		mAllSeen = 名前入力;
	}
	if (view == mKetteiTudukiButton) {
		mAllSeen = mZennkaiSave; // 前回の保存データ
	}
	if (view == mModoruTudukiButton) {
		mAllSeen = タイトルメニュー;
	}
	
}

void Kihon::OnClick(View* view)
{
	if (view == mKetteiButton) {
		mAllSeen = タイトルメニュー;
		WriteVolume(mVolume, mfileName);
		SyokiFlg = false;
	}
	if (view == mResetButton) {
		mVolume = 255;
		SyokiFlg = false;
	}
	if (view == mModoruButton) {
		mAllSeen = タイトルメニュー;
		LoadVolume(mVolume, mfileName);
		SyokiFlg = false;
	}
	if (view == mUpButton) {
		mVolume += 15; // 255÷15=17当分
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
	char str1[256] = "図鑑あり";
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
	mAllSeen = 待ち受け画面;
	mMatiFlg = 待ち受け画像を変更する;
}

void GameMain::OnClick(View* view)
{
	if (view == mPtSetButton) {
		mAllSeen = メニューパーティ設定;
	}
	if (view == mSoubiButton) {
		mAllSeen = メニュー装備一覧;
	}
	if (view == mSaveButton) {
		mAllSeen = メニューセーブ;
	}
	if (view == mKyaraButton) {
		mAllSeen = メニューキャラ一覧;
	}
	if (view == mGatyaButton) {
		mAllSeen = メニューガチャ;
	}
	if (view == mQuestButton) {
		mAllSeen = メニュークエスト;
	}
	if (view == mSoftButton) {
		mAllSeen = メニューソフト解説;
	}
}

void MenuPt::OnClick(View* view)
{
	//if (view == mPtSetButton) {
		//mAllSeen = メニューパーティ設定;
	//}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);
	// DXライブラリ初期化処理
	if (DxLib_Init() < 0) {
		//エラーなら終了する
		DxLib_End();    // DXライブラリ終了処理
		return -1;
	}
	Title title;
	Kihon kihon;
	SyokiKyara syokiKyara;
	GameMain gameMain;

	const int titleHandle = LoadGraph("backImg\\Title.png");
	const int tudukiHandle = LoadGraph("backImg\\Tuduki.png");
	const int matiWakuHandle = LoadGraph("backImg\\待ち受け画面.png");

	if (titleHandle > 0 || tudukiHandle > 0 || matiWakuHandle > 0) {
	}
	else {
		MessageBox(NULL, "イメージズの読込失敗", "エラー", MB_ICONERROR | MB_OK);
		DxLib_End();    // DXライブラリ終了処理
		return 0;
	}
	int monHandle[10] = { 0 }; // 全てのモンスター10体

	std::string str1;
	const char* monFile1;
	std::string strErr1;

	std::string str2;
	const char* monFile2;
	std::string strErr2;

	std::string str3;
	const char* monFile3;
	int matiImgHandle = -1;

	// 全てのエネミーを読み込む
	int errValue = -1;
	int numValue = sizeof(monHandle) / sizeof(int);
	for (int i = 0; i < numValue; i++)
	{
		str1 = "SyokiData\\モンスター" + std::to_string(i + 1) + ".txt";
		monFile1 = str1.c_str();
		errValue = mEnemy[i].lord(mEnemy[i], monFile1);

		strErr1 = str1 + "の読込失敗";
		if (errValue == -1) {
			MessageBox(NULL, strErr1.c_str(), "エラー", MB_ICONERROR | MB_OK);
			DxLib_End();    // DXライブラリ終了処理
			return 0;
		}

		str2 = "monImg\\モンスター" + std::to_string(i + 1) + ".png";
		monFile2 = str2.c_str();
		monHandle[i] = LoadGraph(monFile2);

		strErr2 = str2 + "の読込失敗";
		if (monHandle[i] > 0) {
		}
		else {
			MessageBox(NULL, strErr2.c_str(), "エラー", MB_ICONERROR | MB_OK);
			DxLib_End();    // DXライブラリ終了処理
			return 0;
		}
	}

	int volume = 0;
	char volumePath[256] = "SaveData\\画面設定.txt";
	char syokiVolumePath[256] = "SyokiData\\画面設定.txt";
	// 音量値の読み込み
	int errVolume = kihon.LoadVolume(volume, volumePath);
	// 初期データ読み込み
	if (errVolume == -1)
	{
		errVolume = kihon.LoadVolume(volume, syokiVolumePath);
		if (errVolume == -1) {
			MessageBox(NULL, "音量ファイルの読込失敗", "エラー", MB_ICONERROR | MB_OK);
			DxLib_End();    // DXライブラリ終了処理
			return 0;
		}
		errVolume = kihon.WriteVolume(volume, volumePath);
		if (errVolume == -1) {
			MessageBox(NULL, "音量ファイルの書込失敗", "エラー", MB_ICONERROR | MB_OK);
			DxLib_End();    // DXライブラリ終了処理
			return 0;
		}
	}
	SetVolumeMusic(volume);

	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		if (ProcessMessage() != 0) { // メッセージ処理
			break;//ウィンドウの×ボタンが押されたらループを抜ける
		}
		if (title.tMenu == 終了)
		{
			break;
		}
		WaitTimer(1000.0 / 60);

		ClearDrawScreen(); // 画面を消す

		title.Output(titleHandle); // タイトルを描画
		title.InputName(mPlayer); // 名前入力
		title.Tuduki(tudukiHandle, mPlayer); // 続きから
		kihon.Setting(volumePath, volume, title); // 設定

		syokiKyara.Select(monHandle[0], monHandle[1], monHandle[2]);// 初期キャラを選択

		if (mMatiFlg == 待ち受け画像を変更する)
		{
			str3 = "monImg\\モンスター" + std::to_string(mPt[0].imgNum) + ".png";
			monFile3 = str3.c_str();
			matiImgHandle = LoadGraph(monFile3);
			mMatiFlg = 待ち受け画像を変更しない;

			if (matiImgHandle > 0) {
			}
			else {
				MessageBox(NULL, strErr2.c_str(), "エラー", MB_ICONERROR | MB_OK);
				DxLib_End();    // DXライブラリ終了処理
				return 0;
			}
		}
		gameMain.Play(matiWakuHandle, matiImgHandle); // ゲームをプレイ

		ScreenFlip(); //裏画面を表画面に反映
	}

	DxLib_End();    // DXライブラリ終了処理
	return 0;
}