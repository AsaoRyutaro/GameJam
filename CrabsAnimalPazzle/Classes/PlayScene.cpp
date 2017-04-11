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
	m_pBackGroundImage = Sprite::create("backGroud.png");
	m_pBackGroundImage->setPosition(Vec2(480.0f, 360.0f));
	addChild(m_pBackGroundImage);


	m_pGoriraImage = Sprite::create("Gorira.png");
	m_pGoriraImage->setScale(0.5f);
	m_pGoriraImage->setPosition(Vec2(440.0f, 440.0f));
	addChild(m_pGoriraImage);

	m_pSakuImage = Sprite::create("saku.png");
	m_pSakuImage->setScale(0.9f);
	m_pSakuImage->setPosition(Vec2(440.0f, 440.0f));
	addChild(m_pSakuImage);


	// キャラクターレイヤーの初期化
	m_pCharacterLayer = CharacterLayer::create();
	addChild(m_pCharacterLayer);
}
