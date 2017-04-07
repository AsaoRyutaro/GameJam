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

public:
	PlayScene();
	~PlayScene();

	CREATE_FUNC(PlayScene);
	bool init();
};
