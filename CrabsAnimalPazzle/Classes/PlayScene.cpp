/******************************************************************
*|�@�T�v�@�@�v���C�V�[��
*|�@�쐬�ҁ@GS1_04_���R�q��
*|�@�쐬���@2017/04/07
*|
*******************************************************************/
/* -- �t�@�C���̃C���N���[�h ---- */
#include "PlayScene.h"
#include "cocos2d.h"

/* -- ���O��Ԃ���� ---- */
USING_NS_CC;

/*****************************************************************
*�@�T�v�@�@�@�R���X�g���N�^
*�@�������@�@����
******************************************************************/
PlayScene::PlayScene()
{
}

/*****************************************************************
*�@�T�v�@�@�@�f�X�g���N�^
******************************************************************/
PlayScene::~PlayScene()
{

}

/*****************************************************************
*�@�T�v�@�@������
*�@�������@����
*�@�߂�l�@����I�����ۂ�:bool
******************************************************************/
bool PlayScene::init()
{
	// �p������init�֐�
	if (!Scene::init())
	{
		return false;
	}

	// �w�i�摜�̏�����
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


	// �L�����N�^�[���C���[�̏�����
	m_pCharacterLayer = CharacterLayer::create();
	addChild(m_pCharacterLayer);
}
