#pragma once
#ifndef __cocos2d_x__Crab__
#define __cocos2d_x__Crab__

#include "cocos2d.h"

class Crab : public cocos2d::Layer
{
private:
	int x;	//���WX
	int y;	//���WY



public:
	void Move(); //����
	
	void HavingCharacter();//����������

	void ReleaseCharacter();//�����𗣂�

	void CuttingCharacter();//������؂�

	void PutOn();//�Ŕɂ͂߂�

	void Animation();//�A�j���[�V����

	virtual bool init();
	
	static cocos2d::Scene* crab();

	CREATE_FUNC(Crab);


};





#endif /* defined(__cocos2d_x__Crab__) */