#include "Tools.h"

Layer* createCommonBackLayer()
{
	Layer* layerBg = Layer::create();
	srand((unsigned) time(0));
	unsigned int randomBgIndex = rand();

	randomBgIndex = randomBgIndex%2;

	string bgName;
	if ( randomBgIndex == 0) {
		bgName = "index_bg.png";
	}else{
		bgName = "index_bg_iphone5.png";
	}

	Size size = Director::getInstance()->getVisibleSize();
	Sprite* bg = Sprite::create(bgName);
	bg->setPosition(Point(size.width/2, size.height/2));
	
	layerBg->addChild(bg);
	return layerBg;
}

Sprite* createLogo()
{
	Size size = Director::getInstance()->getVisibleSize();
	string logoName = "index_title.png";
	Sprite* logo = Sprite::create(logoName);
	logo->setPosition(Point(size.width/2 - 5, size.height/2 + logo->getSpriteFrame()->getRect().size.height/2));

	return logo;
}