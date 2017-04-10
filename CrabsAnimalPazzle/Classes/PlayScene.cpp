/******************************************************************
*|　概要　　プレイシーン
*|　作成者　GS1_04_牛山航平
*|　作成日　2017/04/07
*|
*******************************************************************/
/* -- ファイルのインクルード ---- */
#include "PlayScene.h"
#include "cocos2d.h"

/* -- 名前空間を解放 ---- */
USING_NS_CC;

/*****************************************************************
*　概要　　　コンストラクタ
*　引き数　　無し
******************************************************************/
PlayScene::PlayScene()
{
}

/*****************************************************************
*　概要　　　デストラクタ
******************************************************************/
PlayScene::~PlayScene()
{

}

/*****************************************************************
*　概要　　初期化
*　引き数　無し
*　戻り値　正常終了か否か:bool
******************************************************************/
bool PlayScene::init()
{
	// 継承元のinit関数
	if (!Scene::init())
	{
		return false;
	}

	// 背景画像の初期化

	// キャラクターレイヤーの初期化
	m_pCharacterLayer = CharacterLayer::create();
	addChild(m_pCharacterLayer);
}
