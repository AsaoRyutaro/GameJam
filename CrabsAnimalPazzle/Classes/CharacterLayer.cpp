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

	// �I�̏�����


	// �����̏�����
	m_pCharas = new Chara*[10];
	for (int i = 0; i < 10; i++)
	{
		m_pCharas[i] = Chara::create(8 + (i % 2), i % 5);
		m_pCharas[i]->setPosition(Vec2(i % 5 * 128.0f + 240.0f, (i % 2) * 128.0f + 120.0f));
		addChild(m_pCharas[i]);
	}

	// �Ŕ̏�����
	m_pSignBoard = SignBoard::create("�S����");
	m_pSignBoard->setPosition(640.0f, 540.0f);
	addChild(m_pSignBoard);

	/* �C�x���g���X�i�[�𐧍삷�� */
	EventListenerGesture* listener = EventListenerGesture::create();
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
*�@�T�v�@�@�^�b�v���ɌĂ΂��
*�@�������@�^�b�v���W
*�@�߂�l�@����I�����ۂ�:bool
******************************************************************/
bool CharacterLayer::onTap(cocos2d::Vec2 pos)
{

	return false;
}

/*****************************************************************
*�@�T�v�@�@�X���C�v���ɌĂ΂��
*�@�������@�X���C�v�̕���:SwipeDirection
*�@�߂�l�@����
******************************************************************/
void CharacterLayer::onSwipe(EventListenerGesture::SwipeDirection dir)
{
}
