/******************************************************************
*|�@�T�v�@�@�@�@�Ŕ�
*|�@�쐬�ҁ@�@�@GS1_04_���R�q��
*|�@�쐬���@�@�@2017/04/07
*|�@�ŏI�X�V���@2017/04/10
*******************************************************************/
/* -- �t�@�C���̃C���N���[�h ---- */
#pragma once
#include "cocos2d.h"
#include"Classes\Chara.h"

class SignBoard : public cocos2d::Node
{
private:
	// ���g�̉摜
	cocos2d::Sprite** m_pSprite;

	// �����̕�����
	std::string m_anser;

	// ����̕���
	std::string m_nowText;

public:
	SignBoard();
	~SignBoard();

	// �N���G�C�g�֐�
	static SignBoard* create(std::string anserString);
	bool init(std::string anserString);

	// �������ǂ����𔻒肷��
	bool isCorrectAnswer(Chara* playerAnser);

	// �������̏���
	cocos2d::Node* corect();

	// �s�������̏���
	void incorect();

	// �N���A����
	bool isClear();

	// �X�v���C�g���擾����
	cocos2d::Sprite** getSprites();

	// ���݉��������܂��Ă��邩���擾����
	int getNowTextNum();
};

