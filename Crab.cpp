#include"Crab.h"

USING_NS_CC;




bool Crab::init()
{

	if (!Layer::init())
	{

		return false;
	}

	
	

	auto Text = Sprite::create("sozai.png");


	return true;

}


auto listener = EventListenerTouchOneByOne::create();




///////////////////////////////////////
//////							///////	
//////			“®‚­			///////	
//////							///////
//////							///////
///////////////////////////////////////

void Crab::Move()
{

	listener->onTouchBegan = [](Touch* touch, Event* event)
	{
		auto sprite = Sprite::create("sozai.png");
		
		sprite->setPosition(Vec2(320, 400));


		auto Text = (Sprite*)event->getCurrentTarget();

		Rect targetText = Text->getBoundingBox();

		Point touchPoint = Vec2(touch->getLocationInView().x, touch->getLocationInView().y);

		if (targetText.containsPoint(touchPoint))
		{
			sprite->runAction(MoveTo::create(1.0f, touchPoint));

			return true;
		}

		return false;

	};
	
}

void Crab::Update()
{

}





