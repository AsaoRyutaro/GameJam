#pragma once
#ifndef __cocos2d_x__Crab__
#define __cocos2d_x__Crab__

#include "cocos2d.h"
#include"Classes\Chara.h"

class Crab : public cocos2d::Node
{
private:

	//Sprite *Crab;
	int x;	//���WX
	int y;	//���WY

	Chara* m_haveChara;

public:
	Crab();

	~Crab();

	void Move(cocos2d::Vec2 pos); //����
	
	void HavingCharacter(Chara* chara);//����������

	void ReleaseCharacter();//�����𗣂�

	void CuttingCharacter();//������؂�

	void PutOn();//�Ŕɂ͂߂�

	void Animation();//�A�j���[�V����

	virtual bool init();
	
	CREATE_FUNC(Crab);

	void update();

	Chara* getHaveChara();
};





#endif /* defined(__cocos2d_x__Crab__) */