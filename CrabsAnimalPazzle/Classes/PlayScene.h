/******************************************************************
*|　概要　　プレイシーン
*|　作成者　GS1_04_牛山航平
*|　作成日　2017/04/07
*|
*******************************************************************/
/* -- ファイルのインクルード ---- */
#pragma once
#include "cocos2d.h"
#include "CharacterLayer.h"

class PlayScene : public cocos2d::Scene
{
private:
	// レイヤー
	CharacterLayer* m_pCharacterLayer;

	// 背景画像
	cocos2d::Sprite* m_pBackGroundImage;
	cocos2d::Sprite* m_pGoriraImage;
	cocos2d::Sprite* m_pSakuImage;

public:
	PlayScene();
	~PlayScene();

	CREATE_FUNC(PlayScene);
	bool init();
};
