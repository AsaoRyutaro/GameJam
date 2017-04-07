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


	// �Ŕ̏�����


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
