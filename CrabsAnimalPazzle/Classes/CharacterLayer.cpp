/******************************************************************
*|�@�T�v�@�@�L�����N�^�[���C���[
*|�@�쐬�ҁ@GS1_04_���R�q��
*|�@�쐬���@2017/04/07
*|
*******************************************************************/
/* -- �t�@�C���̃C���N���[�h ---- */
#include "CharacterLayer.h"
#include "cocos2d.h"

/* -- ���O��Ԃ���� ---- */
USING_NS_CC;
using namespace std;



/*****************************************************************
*�@�T�v�@�@�@�R���X�g���N�^
*�@�������@�@����
******************************************************************/
CharacterLayer::CharacterLayer()
{

}

/*****************************************************************
*�@�T�v�@�@�f�X�g���N�^
******************************************************************/
CharacterLayer::~CharacterLayer()
{
	if (m_pCharas != nullptr)
	{
		delete[] m_pCharas;
	}
}

/*****************************************************************
*�@�T�v�@�@������
*�@�������@����
*�@�߂�l�@����I�����ۂ�:bool
******************************************************************/
bool CharacterLayer::init()
{
	// �p������init�֐�
	if (!Layer::init())
	{
		return false;
	}

	// �Ŕ̏�����
	m_pSignBoard = SignBoard::create("�����");
	m_pSignBoard->setPosition(720.0f, 455.0f);
	addChild(m_pSignBoard);

	// �����̏�����
	string str[10] = { "��","��","��","��","��","��","��" ,"��","��","��"};
	m_pCharas = new Chara*[10];
	for (int i = 0; i < 10; i++)
	{
		m_pCharas[i] = Chara::create(8 + (i / 5), i % 5, str[i]);
		m_pCharas[i]->setPosition(Vec2(i % 5 * 128.0f + 240.0f, (i / 5) * 128.0f + 120.0f));
		m_pCharas[i]->setDefaultPotision(Vec2(i % 5 * 128.0f + 240.0f, (i / 5) * 128.0f + 120.0f));
		addChild(m_pCharas[i]);
	}

	// �I�̏�����
	m_pPlayer = Crab::create();
	m_pPlayer->setPosition(480.0f,360.0f);
	addChild(m_pPlayer);

	// 
	scheduleUpdate();

	/* �C�x���g���X�i�[�𐧍삷�� */
	EventListenerGesture* listener = EventListenerGesture::create();
	// �����O�^�b�v�Ɣ��肷��b����ݒ�
	listener->setLongTapThreshouldSeconds(100.0f);
	// �X���C�v�Ɣ��肷�鋗����ݒ�
	listener->setSwipeThreshouldDistance(100.0f);
	// �e�R�[���o�b�N�֐���ݒ�
	listener->onTap = CC_CALLBACK_1(CharacterLayer::onTap, this);
	listener->onSwipe = CC_CALLBACK_1(CharacterLayer::onSwipe, this);

	// �C�x���g���X�i�[���V�X�e���ɓo�^
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

/*****************************************************************
*�@�T�v�@�@���t���[������
*�@�������@
*�@�߂�l�@����
******************************************************************/
void CharacterLayer::update(float delta)
{
	m_pPlayer->update();
}

/*****************************************************************
*�@�T�v�@�@�������̊֐�
*�@�������@����
*�@�߂�l�@����
******************************************************************/
void CharacterLayer::corect()
{
	m_pPlayer->getHaveChara()->setPosition(m_pSignBoard->getPositionX() + (m_pSignBoard->getNowTextNum() - 2)*64.0f, m_pSignBoard->getPosition().y);
	m_pPlayer->getHaveChara()->getSprite()->setRotation(0);
	addChild(m_pSignBoard->corect());
	m_pPlayer->ReleaseCharacter();
}

/*****************************************************************
*�@�T�v�@�@�s�������̊֐�
*�@�������@����
*�@�߂�l�@����
******************************************************************/
void CharacterLayer::incorect()
{
	Vec2 defoult = m_pPlayer->getHaveChara()->getDefaultPotision();

	JumpTo* jump = JumpTo::create(0.5, defoult, 128.0f, 1);
	m_pPlayer->getHaveChara()->runAction(jump);

	m_pPlayer->ReleaseCharacter();
}

/*****************************************************************
*�@�T�v�@�@�^�b�v���ɌĂ΂��
*�@�������@�^�b�v���W
*�@�߂�l�@����I�����ۂ�:bool
******************************************************************/
bool CharacterLayer::onTap(cocos2d::Vec2 pos)
{
	// �ŔɃ^�b�`�����ꍇ
	int i;
	for (i = 0; i < 3; i++)
	{
		// �Ŕ̃��N�g���擾
		Rect signBoardRect = m_pSignBoard->getSprites()[i]->getBoundingBox();
		Node* parent = m_pSignBoard->getSprites()[i]->getParent();
		signBoardRect = RectApplyAffineTransform(signBoardRect, parent->getNodeToWorldAffineTransform());

		// �����蔻����Ƃ�
		if (signBoardRect.containsPoint(pos))
		{
			break;
		}

	}

	// ���������������������Ă���Ȃ�
	if (i < 3 && m_pPlayer->getHaveChara() != nullptr)
	{
		// �������킹
		bool result = m_pSignBoard->isCorrectAnswer(m_pPlayer->getHaveChara());

		// �������̏���
		if (result)
		{
			CallFunc* move = CallFunc::create(CC_CALLBACK_0(Crab::Move, m_pPlayer, pos));
			DelayTime* stop = DelayTime::create(1.0f);
			CallFunc* crectAct = CallFunc::create(CC_CALLBACK_0(CharacterLayer::corect, this));
			Sequence* act = Sequence::create(move, stop, crectAct, nullptr);

			// �N���A�����ꍇ
			if (m_pSignBoard->isClear())
			{
				int mojiSize = 196;

				// "���肠"�̕������o��
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

				// �������o��������
				DelayTime* stop = DelayTime::create(1.5f);
				MoveTo* appear = MoveTo::create(2.0f,Vec2(480.0f, 320.0f));
				Sequence* kuriaAct = Sequence::create(stop, appear, nullptr);

				kuria->runAction(kuriaAct);
			}

				m_pPlayer->runAction(act);
			return true;
		}
		// �s����
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

	// �����Ƀ^�b�`�����ꍇ
	for (i = 0; i < 10; i++)
	{
		// �����̃��N�g���擾
		Rect CharaRect = m_pCharas[i]->getSprite()->getBoundingBox();
		Node* parent = m_pCharas[i]->getSprite()->getParent();
		CharaRect = RectApplyAffineTransform(CharaRect, parent->getNodeToWorldAffineTransform());
		parent = m_pCharas[i]->getParent();
		CharaRect = RectApplyAffineTransform(CharaRect, parent->getNodeToWorldAffineTransform());

		// �����蔻����Ƃ�
		if (CharaRect.containsPoint(pos))
		{
			break;
		}
	}

	// �����Ă��當��������
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
*�@�T�v�@�@�X���C�v���ɌĂ΂��
*�@�������@�X���C�v�̕���:SwipeDirection
*�@�߂�l�@����
******************************************************************/
void CharacterLayer::onSwipe(EventListenerGesture::SwipeDirection dir)
{
	if (m_pPlayer->getHaveChara() !=nullptr)
	{
		incorect();
	}
}
