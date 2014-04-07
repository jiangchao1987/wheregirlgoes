#include "Tools.h"
#include "DataMgr.h"
#include "SimpleAudioEngine.h"

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

void setItemPosition(Layer* backLayer, Point anchor, Point position, MenuItemImage* item) {
	item->setAnchorPoint(anchor);
	item->setPosition(position);
	// create menu, it's an autorelease object
	auto menu = Menu::create(item, NULL);
	menu->setPosition(Point::ZERO);
	backLayer->addChild(menu, 1);
}

void playBackGroundMusic()
{
	if (!CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() && DataMgr::getInstance()->isBgSoundOpen())
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("background.wav");
	}
}

void stopBackGroundMusic()
{
	if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

void playEffectBtnClicked()
{
	if (DataMgr::getInstance()->isBgSoundOpen())
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("pop3.mp3");
}