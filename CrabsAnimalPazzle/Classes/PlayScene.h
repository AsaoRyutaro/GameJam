/******************************************************************
*|�@�T�v�@�@�v���C�V�[��
*|�@�쐬�ҁ@GS1_04_���R�q��
*|�@�쐬���@2017/04/07
*|
*******************************************************************/
/* -- �t�@�C���̃C���N���[�h ---- */
#pragma once
#include "cocos2d.h"
#include "CharacterLayer.h"

class PlayScene : public cocos2d::Scene
{
private:
	// ���C���[
	CharacterLayer* m_pCharacterLayer;

public:
	PlayScene();
	~PlayScene();

	CREATE_FUNC(PlayScene);
	bool init();
};
