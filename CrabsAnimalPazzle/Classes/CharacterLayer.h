/******************************************************************
*|�@�T�v�@�@�L�����N�^�[���C���[
*|�@�쐬�ҁ@GS1_04_���R�q��
*|�@�쐬���@2017/04/07
*|
*******************************************************************/
/* -- �t�@�C���̃C���N���[�h ---- */
#pragma once

#include "cocos2d.h"
#include "EventListenerGesture.h"
#include "Classes\Signboard.h"

class  CharacterLayer:public cocos2d::Layer
{
private:
	// �I


	// ����


	// �Ŕ�
	SignBoard* m_pSignBoard;

public:
	 CharacterLayer();
	~ CharacterLayer();

	CREATE_FUNC(CharacterLayer);
	bool init();

	// �^�b�`�֌W�̊֐�
	bool onTap(cocos2d::Vec2 pos);
	void onSwipe(EventListenerGesture::SwipeDirection dir);
};

