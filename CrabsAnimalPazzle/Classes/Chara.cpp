#include "Chara.h"


//コンストラクタ
Chara::Chara()
{

}

//デストラクタ
Chara::~Chara()
{

}

void Chara::ResetPotision()
{


}

std::string Chara::GetChar()
{
	return m_CharData;
}

Chara * Chara::create(int a, int b, std::string str)
{
    Chara *pRet = new(std::nothrow) Chara(); 

    if (pRet && pRet->init(a,b,str)) 
    { 
        pRet->autorelease(); 
        return pRet; 
    } 
    else 
    { 
        delete pRet; 
        pRet = nullptr; 
        return nullptr; 
    } 


	return nullptr;
}

// 初期化
bool Chara::init(int a, int b, std::string str)
{
	m_sprite = cocos2d::Sprite::create("moji.png");
	m_sprite->setScale(1.0f / 3.0f);
	int rotate = rand() % 360 - 180;
	m_sprite->setRotation(rotate);
	const int size = 196.0f;
	m_sprite->setTextureRect(cocos2d::Rect(a*size,b*size,size,size));
	addChild(m_sprite);
	m_CharData = str;
	return true;


}

cocos2d::Sprite * Chara::getSprite()
{
	return m_sprite;
}

void Chara::setDefaultPotision(cocos2d::Vec2 pos)
{
	m_DefaultPotision = pos;
}

cocos2d::Vec2 Chara::getDefaultPotision()
{
	return m_DefaultPotision;
}

std::string Chara::getCharData()
{
	return m_CharData;
}

