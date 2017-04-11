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
using namespace std;



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
	if (m_pCharas != nullptr)
	{
		delete[] m_pCharas;
	}
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

	// 看板の初期化
	m_pSignBoard = SignBoard::create("ごりら");
	m_pSignBoard->setPosition(720.0f, 455.0f);
	addChild(m_pSignBoard);

	// 文字の初期化
	string str[10] = { "ら","り","る","れ","ろ","が","ぎ" ,"ぐ","げ","ご"};
	m_pCharas = new Chara*[10];
	for (int i = 0; i < 10; i++)
	{
		m_pCharas[i] = Chara::create(8 + (i / 5), i % 5, str[i]);
		m_pCharas[i]->setPosition(Vec2(i % 5 * 128.0f + 240.0f, (i / 5) * 128.0f + 120.0f));
		m_pCharas[i]->setDefaultPotision(Vec2(i % 5 * 128.0f + 240.0f, (i / 5) * 128.0f + 120.0f));
		addChild(m_pCharas[i]);
	}

	// 蟹の初期化
	m_pPlayer = Crab::create();
	m_pPlayer->setPosition(480.0f,360.0f);
	addChild(m_pPlayer);

	// 
	scheduleUpdate();

	/* イベントリスナーを制作する */
	EventListenerGesture* listener = EventListenerGesture::create();
	// ロングタップと判定する秒数を設定
	listener->setLongTapThreshouldSeconds(100.0f);
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
*　概要　　毎フレーム処理
*　引き数　
*　戻り値　無し
******************************************************************/
void CharacterLayer::update(float delta)
{
	m_pPlayer->update();
}

/*****************************************************************
*　概要　　正解時の関数
*　引き数　無し
*　戻り値　無し
******************************************************************/
void CharacterLayer::corect()
{
	m_pPlayer->getHaveChara()->setPosition(m_pSignBoard->getPositionX() + (m_pSignBoard->getNowTextNum() - 2)*64.0f, m_pSignBoard->getPosition().y);
	m_pPlayer->getHaveChara()->getSprite()->setRotation(0);
	addChild(m_pSignBoard->corect());
	m_pPlayer->ReleaseCharacter();
}

/*****************************************************************
*　概要　　不正解時の関数
*　引き数　無し
*　戻り値　無し
******************************************************************/
void CharacterLayer::incorect()
{
	Vec2 defoult = m_pPlayer->getHaveChara()->getDefaultPotision();

	JumpTo* jump = JumpTo::create(0.5, defoult, 128.0f, 1);
	m_pPlayer->getHaveChara()->runAction(jump);

	m_pPlayer->ReleaseCharacter();
}

/*****************************************************************
*　概要　　タップ時に呼ばれる
*　引き数　タップ座標
*　戻り値　正常終了か否か:bool
******************************************************************/
bool CharacterLayer::onTap(cocos2d::Vec2 pos)
{
	// 看板にタッチした場合
	int i;
	for (i = 0; i < 3; i++)
	{
		// 看板のレクトを取得
		Rect signBoardRect = m_pSignBoard->getSprites()[i]->getBoundingBox();
		Node* parent = m_pSignBoard->getSprites()[i]->getParent();
		signBoardRect = RectApplyAffineTransform(signBoardRect, parent->getNodeToWorldAffineTransform());

		// あたり判定をとる
		if (signBoardRect.containsPoint(pos))
		{
			break;
		}

	}

	// 当たった且つ文字を持っているなら
	if (i < 3 && m_pPlayer->getHaveChara() != nullptr)
	{
		// 答え合わせ
		bool result = m_pSignBoard->isCorrectAnswer(m_pPlayer->getHaveChara());

		// 正解時の処理
		if (result)
		{
			CallFunc* move = CallFunc::create(CC_CALLBACK_0(Crab::Move, m_pPlayer, pos));
			DelayTime* stop = DelayTime::create(1.0f);
			CallFunc* crectAct = CallFunc::create(CC_CALLBACK_0(CharacterLayer::corect, this));
			Sequence* act = Sequence::create(move, stop, crectAct, nullptr);

			// クリアした場合
			if (m_pSignBoard->isClear())
			{
				int mojiSize = 196;

				// "くりあ"の文字を出す
				Sprite* ku = Sprite::create("moji.png");
				ku->setPositionX(-200.0f);
				ku->setRotation(30);
				ku->setTextureRect(Rect(1* mojiSize, 2* mojiSize, mojiSize, mojiSize));

				Sprite* ri = Sprite::create("moji.png");
				ri->setRotation(-24);
				ri->setTextureRect(Rect(8 * mojiSize, 1 * mojiSize, mojiSize, mojiSize));

				Sprite* a = Sprite::create("moji.png");
				a->setPositionX(200); 
				a->setRotation(-32);
				a->setTextureRect(Rect(0 * mojiSize, 0 * mojiSize, mojiSize, mojiSize));

				Node* kuria = Node::create();
				kuria->addChild(ku);kuria->addChild(ri);kuria->addChild(a);
				kuria->setPosition(480.0f, -256.0f);
				

				addChild(kuria);

				// 文字を出現させる
				DelayTime* stop = DelayTime::create(1.5f);
				MoveTo* appear = MoveTo::create(2.0f,Vec2(480.0f, 320.0f));
				Sequence* kuriaAct = Sequence::create(stop, appear, nullptr);

				kuria->runAction(kuriaAct);
			}

				m_pPlayer->runAction(act);
			return true;
		}
		// 不正解
		else
		{
			CallFunc* move = CallFunc::create(CC_CALLBACK_0(Crab::Move, m_pPlayer, pos));
			DelayTime* stop = DelayTime::create(1.0f);
			CallFunc* increctAct = CallFunc::create(CC_CALLBACK_0(CharacterLayer::incorect, this));
			Sequence* act = Sequence::create(move, stop, increctAct, nullptr);

			m_pPlayer->runAction(act);

			return true;
		}
	}

	// 文字にタッチした場合
	for (i = 0; i < 10; i++)
	{
		// 文字のレクトを取得
		Rect CharaRect = m_pCharas[i]->getSprite()->getBoundingBox();
		Node* parent = m_pCharas[i]->getSprite()->getParent();
		CharaRect = RectApplyAffineTransform(CharaRect, parent->getNodeToWorldAffineTransform());
		parent = m_pCharas[i]->getParent();
		CharaRect = RectApplyAffineTransform(CharaRect, parent->getNodeToWorldAffineTransform());

		// あたり判定をとる
		if (CharaRect.containsPoint(pos))
		{
			break;
		}
	}

	// 動いてから文字を持つ
	if (i < 10 && pos.y < 480)
	{
		CallFunc* haveChara = CallFunc::create(CC_CALLBACK_0(Crab::HavingCharacter, m_pPlayer, m_pCharas[i]));
		CallFunc* move = CallFunc::create(CC_CALLBACK_0(Crab::Move, m_pPlayer,pos));
		DelayTime* stop = DelayTime::create(1.0f);
		Sequence* act = Sequence::create( move, stop, haveChara, nullptr);

		m_pPlayer->runAction(act);
		return true;
	}


	m_pPlayer->Move(pos);
	return true;
}

/*****************************************************************
*　概要　　スワイプ時に呼ばれる
*　引き数　スワイプの方向:SwipeDirection
*　戻り値　無し
******************************************************************/
void CharacterLayer::onSwipe(EventListenerGesture::SwipeDirection dir)
{
	if (m_pPlayer->getHaveChara() !=nullptr)
	{
		incorect();
	}
}
