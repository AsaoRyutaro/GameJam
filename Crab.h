#pragma once
#ifndef __cocos2d_x__Crab__
#define __cocos2d_x__Crab__

#include "cocos2d.h"

class Crab : public cocos2d::Layer
{
private:
	int x;	//座標X
	int y;	//座標Y



public:
	void Move(); //動く
	
	void Update();

	virtual bool init();
	
	static cocos2d::Scene* crab();

	CREATE_FUNC(Crab);


};





#endif /* defined(__cocos2d_x__Crab__) */