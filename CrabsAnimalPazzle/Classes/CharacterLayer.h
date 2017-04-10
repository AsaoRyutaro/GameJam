/******************************************************************
*|　概要　　キャラクターレイヤー
*|　作成者　GS1_04_牛山航平
*|　作成日　2017/04/07
*|
*******************************************************************/
/* -- ファイルのインクルード ---- */
#pragma once

#include "cocos2d.h"
#include "EventListenerGesture.h"
#include "Classes\Signboard.h"
#include "Classes\Chara.h"
#include "Classes\Crab.h"

class  CharacterLayer:public cocos2d::Layer
{
private:
	// 蟹
	Crab* m_pPlayer;

	// 文字
	Chara** m_pCharas;

	// 看板
	SignBoard* m_pSignBoard;

public:
	 CharacterLayer();
	~ CharacterLayer();

	CREATE_FUNC(CharacterLayer);
	bool init();

	void update(float delta)override;

	// 正解時の関数
	void corect();

	// 不正解時の関数
	void incorect();

	// タッチ関係の関数
	bool onTap(cocos2d::Vec2 pos);
	void onSwipe(EventListenerGesture::SwipeDirection dir);
};

