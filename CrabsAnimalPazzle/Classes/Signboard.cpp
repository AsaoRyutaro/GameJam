/******************************************************************
*|　概要　　看板
*|　作成者　GS1_04_牛山航平
*|　作成日　2017/04/10
*|
*******************************************************************/
/* -- ファイルのインクルード ---- */
#pragma once
#include "Signboard.h"
#include "cocos2d.h"

/* -- 名前空間を解放 ---- */
USING_NS_CC;


/*****************************************************************
*　機能　　コンストラクタ
*　引数　　無し
******************************************************************/
SignBoard::SignBoard()
{
}

/*****************************************************************
*　機能　　デストラクタ
******************************************************************/
SignBoard::~SignBoard()
{
	// スプライトを消す
	if (m_pSprite != nullptr)
	{
		delete[] m_pSprite;
	}
}

/*****************************************************************
*　機能　　看板を作る
*　引数　　正解の文字列
*　戻り値　作った看板のポインタ
******************************************************************/
SignBoard* SignBoard::create(std::string anserString)
{
	// 看板を作って
	SignBoard *pRet = new(std::nothrow) SignBoard();

	// イニット関数を呼んで
	if (pRet && pRet->init(anserString))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

/*****************************************************************
*　機能　　初期化
*　引数　　正解の文字列
*　戻り値　正常終了ならtrue
******************************************************************/
bool SignBoard::init(std::string anserString)
{
	// 正解を設定
	m_anser = anserString;

	// スプライトを生成
	m_pSprite = new Sprite*[anserString.size()];

	// 正解の文字数分スプライトを作る
	for (int i = 0; i < anserString.size()/2; i++)
	{
		m_pSprite[i] = Sprite::create("signBorad.png");
		float a = (i + 0.5) - anserString.size() / 4.0f;
		m_pSprite[i]->setPositionX(a * 64.0f);
		addChild(m_pSprite[i]);
	}

	// 現在の文字列を初期化
	m_nowText = "NULL";

	return true;
}

/*****************************************************************
*　機能　　正解かどうかを判定
*　引数　　無し
*　戻り値　正解ならtrue
******************************************************************/
bool SignBoard::isCorrectAnswer(char playerAnser)
{
	// 次にはめる文字の正解と判定を取る
	if (m_anser[m_nowText.size() + 1] == playerAnser)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*****************************************************************
*　機能　　正解時の処理
*　引数　　無し
*　戻り値　無し
******************************************************************/
void SignBoard::corect()
{

}

/*****************************************************************
*　機能　　不正解時の処理
*　引数　　無し
*　戻り値　無し
******************************************************************/
void SignBoard::incorect()
{

}
