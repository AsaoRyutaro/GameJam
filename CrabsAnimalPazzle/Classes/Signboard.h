/******************************************************************
*|　概要　　　　看板
*|　作成者　　　GS1_04_牛山航平
*|　作成日　　　2017/04/07
*|　最終更新日　2017/04/10
*******************************************************************/
/* -- ファイルのインクルード ---- */
#pragma once
#include "cocos2d.h"
#include"Classes\Chara.h"

class SignBoard : public cocos2d::Node
{
private:
	// 自身の画像
	cocos2d::Sprite** m_pSprite;

	// 正解の文字列
	std::string m_anser;

	// 現状の文字
	std::string m_nowText;

public:
	SignBoard();
	~SignBoard();

	// クリエイト関数
	static SignBoard* create(std::string anserString);
	bool init(std::string anserString);

	// 正解かどうかを判定する
	bool isCorrectAnswer(Chara* playerAnser);

	// 正解時の処理
	cocos2d::Node* corect();

	// 不正解時の処理
	void incorect();

	// クリア判定
	bool isClear();

	// スプライトを取得する
	cocos2d::Sprite** getSprites();

	// 現在何文字埋まっているかを取得する
	int getNowTextNum();
};

