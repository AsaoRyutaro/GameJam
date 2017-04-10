/******************************************************************
*|�@�T�v�@�@�@�@�Ŕ�
*|�@�쐬�ҁ@�@�@GS1_04_���R�q��
*|�@�쐬���@�@�@2017/04/10
*|�@�ŏI�X�V���@2017/04/10
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
bool SignBoard::isCorrectAnswer(Chara* playerAnser)
{
	// ���ɂ͂߂镶���̐����Ɣ�������
	if (m_anser[m_nowText.size()] == playerAnser->getCharData()[0] && m_anser[m_nowText.size() + 1] == playerAnser->getCharData()[1])
	{
		m_nowText += playerAnser->getCharData();
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
*�@�߂�l�@�G�t�F�N�g�̃X�v���C�g���W�߂��m�[�h
******************************************************************/
cocos2d::Node* SignBoard::corect()
{
	// �o�����̐������߂�
	int appearNum = (m_nowText.size()/2 + 1);

	// �����o��
	Sprite** starSprite = new Sprite*[appearNum];

	// �G�t�F�N�g�������܂Ƃ߂�m�[�h
	Node* sprites = Node::create();

	for (int i = 0; i < appearNum; i++)
	{
		starSprite[i] = Sprite::create("small_star7_yellow.png");
		starSprite[i]->setPosition(	m_pSprite[m_nowText.size() /2-1]->getPositionX() + this->getPositionX(),
									m_pSprite[m_nowText.size() / 2-1]->getPositionY() + this->getPositionY());
		starSprite[i]->setScale(0.1f);
		sprites->addChild(starSprite[i]);
	
		// ������
		int a = (rand() % 128) * ((i % 3) - 1);
		int b = rand() % 128;
		JumpBy* jump = JumpBy::create(0.5f, Vec2(a, -64.0f), b, 1);
		int rote = (rand() % 356) - 128.0f;
		RotateBy* rotate = RotateBy::create(0.5f, rote);
		RemoveSelf* removeSelf = RemoveSelf::create();
		Spawn* spawn = Spawn::create(jump, rotate, nullptr);
		Sequence* act = Sequence::create(spawn, removeSelf, nullptr);

		// �A�N�V�������N����
		starSprite[i]->runAction(act);
	}

	return sprites;
}

/*****************************************************************
*�@�@�\�@�@�s�������̏���
*�@�����@�@����
*�@�߂�l�@����
******************************************************************/
void SignBoard::incorect()
{

}

/*****************************************************************
*�@�@�\�@�@�N���A����
*�@�����@�@����
*�@�߂�l�@�N���A���Ă���Ȃ�true
******************************************************************/
bool SignBoard::isClear()
{
	if (m_anser == m_nowText)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*****************************************************************
*�@�@�\�@�@�X�v���C�g�̔z����擾����
*�@�����@�@����
*�@�߂�l�@�X�v���C�g�̔z��̃|�C���^
******************************************************************/
cocos2d::Sprite** SignBoard::getSprites()
{
	return m_pSprite;
}

/*****************************************************************
*�@�@�\�@�@���݉��������܂��Ă��邩���擾����
*�@�����@�@����
*�@�߂�l�@���݂̕�����
******************************************************************/
int SignBoard::getNowTextNum()
{
	return m_nowText.size()/2;
}
