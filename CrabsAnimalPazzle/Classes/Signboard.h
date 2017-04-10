/******************************************************************
*|�@�T�v�@�@�Ŕ�
*|�@�쐬�ҁ@GS1_04_���R�q��
*|�@�쐬���@2017/04/07
*|
*******************************************************************/
/* -- �t�@�C���̃C���N���[�h ---- */
#pragma once
#include "cocos2d.h"

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
	bool isCorrectAnswer(char playerAnser);

	// �������̏���
	void corect();

	// �s�������̏���
	void incorect();
};

