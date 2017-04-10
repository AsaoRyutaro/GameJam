#pragma once
#ifndef __cocos2d_x__Crab__
#define __cocos2d_x__Crab__

#include "cocos2d.h"

class Crab : public cocos2d::Node
{
private:

	//Sprite *Crab;
	int x;	//���WX
	int y;	//���WY



public:
	Crab();

	~Crab();

	void Move(cocos2d::Vec2 pos, cocos2d::Node *Crab); //����
	
	void HavingCharacter();//����������

	void ReleaseCharacter();//�����𗣂�

	void CuttingCharacter();//������؂�

	void PutOn();//�Ŕɂ͂߂�

	void Animation();//�A�j���[�V����

	virtual bool init();
	
	CREATE_FUNC(Crab);


};





#endif /* defined(__cocos2d_x__Crab__) */