#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

class StartScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
	void menuPlayCallback(Object* pSender);
	void menuShopCallback(Object* pSender);
	void menuSettingCallback(Object* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);

	void onEnter();
	void onExit();
};

#endif // __START_SCENE_H__
