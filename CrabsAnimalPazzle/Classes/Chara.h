#pragma once
#include "cocos2d.h"
#include <string.h>

class Chara : public cocos2d::Node
{
	std::string m_CharData;
	cocos2d::Vec2 m_DefaultPotision;
	cocos2d::Vec2 m_CharPotision;
	cocos2d::Sprite* m_sprite;
public:
	Chara();
	~Chara();
	int ResetPotision();
	std::string GetChar();
	static Chara* create(int a,int b);
	bool init(int a, int b);
};

