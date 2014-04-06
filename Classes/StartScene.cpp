#include "StartScene.h"
#include "Tools.h"

USING_NS_CC;

Scene* StartScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StartScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. 添加开始页面背景
	Layer* backLayer = createCommonBackLayer();

	/////////////////////////////
    // 3. 添加精灵们
	//logo
	Sprite* spriteLogo = createLogo();
	backLayer->addChild(spriteLogo);
	MoveTo* move1 = MoveTo::create(2, Point( spriteLogo->getPositionX(),spriteLogo->getPositionY() - 10));
	MoveTo* move2 = MoveTo::create(2, Point( spriteLogo->getPositionX(), spriteLogo->getPositionY() + 10));
	spriteLogo->runAction(RepeatForever::create(Sequence::create(move1, move2, nullptr)));
    //play
	auto playItem = MenuItemImage::create(
                                           "index_play.png",
                                           "index_play_selected.png",
                                           CC_CALLBACK_1(StartScene::menuPlayCallback, this));
	playItem->setAnchorPoint(Point(0.5f, 0.5f));
	playItem->setPosition(Point(origin.x + visibleSize.width/2,
								 visibleSize.height/2 - playItem->getContentSize().height));
	auto playMenu = Menu::create(playItem, nullptr);
    playMenu->setPosition(Point::ZERO);
    backLayer->addChild(playMenu, 1);
	//shop
	auto shopItem = MenuItemImage::create(
                                           "index_store.png",
                                           "index_store_selected.png",
                                           CC_CALLBACK_1(StartScene::menuShopCallback, this));
    shopItem->setAnchorPoint(Point(0.5f, 0.5f));
	shopItem->setPosition(Point(visibleSize.width/2 - shopItem->getContentSize().width/2  ,
								 visibleSize.height/4 ));
    auto shopMenu = Menu::create(shopItem, nullptr);
    shopMenu->setPosition(Point::ZERO);
    backLayer->addChild(shopMenu, 1);
	//setting
	auto settingItem = MenuItemImage::create(
										  "index_setting.png",
										  "index_setting_selected.png",
										  CC_CALLBACK_1(StartScene::menuSettingCallback, this));
    settingItem->setAnchorPoint(Point(0.5f, 0.5f));
	settingItem->setPosition(Point(visibleSize.width/2 + settingItem->getContentSize().width/2  ,
								visibleSize.height/4 ));
    auto settingMenu = Menu::create(settingItem, nullptr);
    settingMenu->setPosition(Point::ZERO);
    backLayer->addChild(settingMenu, 1);

	this->addChild(backLayer);
    
    return true;
}

void StartScene::onEnter(){
	CCLayer::onEnter();
	playBackGroundMusic();
}
void StartScene::onExit(){
	CCLayer::onExit();
}


void StartScene::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void StartScene::menuPlayCallback(Object* pSender)
{
}

void StartScene::menuShopCallback(Object* pSender)
{
}

void StartScene::menuSettingCallback(Object* pSender)
{
}
