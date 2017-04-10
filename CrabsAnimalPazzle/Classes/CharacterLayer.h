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

class  CharacterLayer:public cocos2d::Layer
{
private:
	// 蟹


	// 文字


	// 看板
	SignBoard* m_pSignBoard;

public:
	 CharacterLayer();
	~ CharacterLayer();

	CREATE_FUNC(CharacterLayer);
	bool init();

	// タッチ関係の関数
	bool onTap(cocos2d::Vec2 pos);
	void onSwipe(EventListenerGesture::SwipeDirection dir);
};

