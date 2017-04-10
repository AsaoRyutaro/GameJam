#include "Chara.h"


//コンストラクタ
Chara::Chara()
{

}

//デストラクタ
Chara::~Chara()
{

}

int Chara::ResetPotision()
{


	return 0;
}

std::string Chara::GetChar()
{
	return m_CharData;
}

Chara * Chara::create(int a, int b)
{
    Chara *pRet = new(std::nothrow) Chara(); 

    if (pRet && pRet->init(a,b)) 
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
bool Chara::init(int a, int b)
{
	m_CharData = a;
	m_sprite = cocos2d::Sprite::create("moji.png");
	const int size = 196.0f;
	m_sprite->setTextureRect(cocos2d::Rect(a*size,b*size,size,size));
	addChild(m_sprite);
	return true;
}

