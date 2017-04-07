/******************************************************************
*|　概要　　キャラクターレイヤー
*|　作成者　GS1_04_牛山航平
*|　作成日　2017/04/07
*|
*******************************************************************/
/* -- ファイルのインクルード ---- */
#include "CharacterLayer.h"
#include "cocos2d.h"

/* -- 名前空間を解放 ---- */
USING_NS_CC;

/*****************************************************************
*　概要　　　コンストラクタ
*　引き数　　無し
******************************************************************/
CharacterLayer::CharacterLayer()
{

}

/*****************************************************************
*　概要　　デストラクタ
******************************************************************/
CharacterLayer::~CharacterLayer()
{

}

/*****************************************************************
*　概要　　初期化
*　引き数　無し
*　戻り値　正常終了か否か:bool
******************************************************************/
bool CharacterLayer::init()
{
	// 継承元のinit関数
	if (!Layer::init())
	{
		return false;
	}

	// 蟹の初期化


	// 文字の初期化


	// 看板の初期化


	/* イベントリスナーを制作する */
	EventListenerGesture* listener = EventListenerGesture::create();
	// スワイプと判定する距離を設定
	listener->setSwipeThreshouldDistance(100.0f);
	// 各コールバック関数を設定
	listener->onTap = CC_CALLBACK_1(CharacterLayer::onTap, this);
	listener->onSwipe = CC_CALLBACK_1(CharacterLayer::onSwipe, this);

	// イベントリスナーをシステムに登録
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

/*****************************************************************
*　概要　　タップ時に呼ばれる
*　引き数　タップ座標
*　戻り値　正常終了か否か:bool
******************************************************************/
bool CharacterLayer::onTap(cocos2d::Vec2 pos)
{
	return false;
}

/*****************************************************************
*　概要　　スワイプ時に呼ばれる
*　引き数　スワイプの方向:SwipeDirection
*　戻り値　無し
******************************************************************/
void CharacterLayer::onSwipe(EventListenerGesture::SwipeDirection dir)
{
}
