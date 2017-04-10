#pragma once
#ifndef __cocos2d_x__Crab__
#define __cocos2d_x__Crab__

#include "cocos2d.h"

class Crab : public cocos2d::Node
{
private:

	//Sprite *Crab;
	int x;	//座標X
	int y;	//座標Y



public:
	Crab();

	~Crab();

	void Move(cocos2d::Vec2 pos, cocos2d::Node *Crab); //動く
	
	void HavingCharacter();//文字を持つ

	void ReleaseCharacter();//文字を離す

	void CuttingCharacter();//文字を切る

	void PutOn();//看板にはめる

	void Animation();//アニメーション

	virtual bool init();
	
	CREATE_FUNC(Crab);


};





#endif /* defined(__cocos2d_x__Crab__) */