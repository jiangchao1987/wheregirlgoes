#include "LevelView.h"
#include "Tools.h"

LevelView::LevelView():m_nCurPage(0),m_nPageCount(0),m_pScrollView(0)
{
    
}

LevelView::~LevelView()
{
    
}

Scene* LevelView::scene()
{
    Scene* scene = Scene::create();
    Layer* layer = LevelView::create();
    scene->addChild(layer);
    return scene;
}

bool LevelView::init()
{
    bool bRef = false;
    do
	{
        CC_BREAK_IF(!Layer::init());

		Size visibleSize = Director::getInstance()->getVisibleSize();
		Point origin = Director::getInstance()->getVisibleOrigin();
	
        Layer* backLayerColor = createCommonBackLayer();
        this->addChild(backLayerColor);

		bRef = true;
    } 
	while (0);
    return bRef;
}

void LevelView::onEnter()
{
	CCLayer::onEnter();
	
	//this->resetView();
}

void LevelView::onExit()
{
	CCLayer::onExit();
}