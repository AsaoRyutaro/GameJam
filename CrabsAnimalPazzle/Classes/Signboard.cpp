/******************************************************************
*|�@�T�v�@�@�Ŕ�
*|�@�쐬�ҁ@GS1_04_���R�q��
*|�@�쐬���@2017/04/10
*|
*******************************************************************/
/* -- �t�@�C���̃C���N���[�h ---- */
#pragma once
#include "Signboard.h"
#include "cocos2d.h"

/* -- ���O��Ԃ���� ---- */
USING_NS_CC;


/*****************************************************************
*�@�@�\�@�@�R���X�g���N�^
*�@�����@�@����
******************************************************************/
SignBoard::SignBoard()
{
}

/*****************************************************************
*�@�@�\�@�@�f�X�g���N�^
******************************************************************/
SignBoard::~SignBoard()
{
	// �X�v���C�g������
	if (m_pSprite != nullptr)
	{
		delete[] m_pSprite;
	}
}

/*****************************************************************
*�@�@�\�@�@�Ŕ����
*�@�����@�@�����̕�����
*�@�߂�l�@������Ŕ̃|�C���^
******************************************************************/
SignBoard* SignBoard::create(std::string anserString)
{
	// �Ŕ������
	SignBoard *pRet = new(std::nothrow) SignBoard();

	// �C�j�b�g�֐����Ă��
	if (pRet && pRet->init(anserString))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

/*****************************************************************
*�@�@�\�@�@������
*�@�����@�@�����̕�����
*�@�߂�l�@����I���Ȃ�true
******************************************************************/
bool SignBoard::init(std::string anserString)
{
	// ������ݒ�
	m_anser = anserString;

	// �X�v���C�g�𐶐�
	m_pSprite = new Sprite*[anserString.size()];

	// �����̕��������X�v���C�g�����
	for (int i = 0; i < anserString.size()/2; i++)
	{
		m_pSprite[i] = Sprite::create("signBorad.png");
		float a = (i + 0.5) - anserString.size() / 4.0f;
		m_pSprite[i]->setPositionX(a * 64.0f);
		addChild(m_pSprite[i]);
	}
	return true;
}

/*****************************************************************
*�@�@�\�@�@�������ǂ����𔻒�
*�@�����@�@����
*�@�߂�l�@�����Ȃ�true
******************************************************************/
bool SignBoard::isCorrectAnswer(std::string playerAnser)
{
	// ���ɂ͂߂镶���̐����Ɣ�������
	if (m_anser[m_nowText.size() + 1] == playerAnser[0] && m_anser[m_nowText.size() + 2] == playerAnser[1])
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*****************************************************************
*�@�@�\�@�@�������̏���
*�@�����@�@����
*�@�߂�l�@����
******************************************************************/
void SignBoard::corect()
{
	// �o�����̐������߂�
	int appearNum = (m_nowText.size() + 1) * 3;

	// �����o��
	Sprite** starSprite = new Sprite*[appearNum];

	for (int i = 0; i < appearNum; i++)
	{
		starSprite[i] = Sprite::create("small_star7_yellow.png");
		starSprite[i]->setPosition(	m_pSprite[m_nowText.size() / 2]->getPosition().x,
									m_pSprite[m_nowText.size() / 2]->getPosition().y);
		starSprite[i]->setScale(0.1f);
		addChild(starSprite[i]);
	
		// ������
		int a = (rand() % 128) * ((i % 3) - 1);
		JumpTo* jump = JumpTo::create(0.5f, Vec2(a, -64.0f), 64.0f, 1);
		int rote = (rand() % 356) - 128.0f;
		RotateBy* rotate = RotateBy::create(0.5f, rote);
		RemoveSelf* removeSelf = RemoveSelf::create();
		Spawn* spawn = Spawn::create(jump, rotate, nullptr);
		Sequence* act = Sequence::create(spawn, removeSelf, nullptr);

		// �A�N�V�������N����
		starSprite[i]->runAction(act);
	}
}

/*****************************************************************
*�@�@�\�@�@�s�������̏���
*�@�����@�@����
*�@�߂�l�@����
******************************************************************/
void SignBoard::incorect()
{

}
