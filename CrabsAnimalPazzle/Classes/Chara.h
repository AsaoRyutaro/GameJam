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
	void ResetPotision();
	std::string GetChar();
	static Chara* create(int a,int b,std::string str);
	bool init(int a, int b, std::string str);

	cocos2d::Sprite* getSprite();
	void setDefaultPotision(cocos2d::Vec2 pos);
	cocos2d::Vec2 getDefaultPotision();

	std::string getCharData();
};

