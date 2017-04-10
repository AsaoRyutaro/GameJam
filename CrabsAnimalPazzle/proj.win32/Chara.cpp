#include "Chara.h"


//�R���X�g���N�^
Chara::Chara()
{

}

//�f�X�g���N�^
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

Chara * Chara::create(std::string a)
{
    Chara *pRet = new(std::nothrow) Chara(); 

    if (pRet && pRet->init(a)) 
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

// ������
bool Chara::init(std::string a)
{
	m_CharData = a;
	m_sprite = cocos2d::Sprite::create("moji.png");
	addChild(m_sprite);
	return true;
}

