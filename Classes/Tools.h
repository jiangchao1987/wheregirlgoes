#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

#define SaveStringToXML CCUserDefault::sharedUserDefault()->setStringForKey
#define SaveIntegerToXML CCUserDefault::sharedUserDefault()->setIntegerForKey
#define SaveBooleanToXML CCUserDefault::sharedUserDefault()->setBoolForKey
#define LoadStringFromXML CCUserDefault::sharedUserDefault()->getStringForKey
#define LoadIntegerFromXML CCUserDefault::sharedUserDefault()->getIntegerForKey
#define LoadBooleanFromXML CCUserDefault::sharedUserDefault()->getBoolForKey
#define WriteDisk CCUserDefault::sharedUserDefault()->flush()

Layer* createCommonBackLayer();
Sprite* createLogo();

void setItemPosition(Layer* layer, Point anchor, Point position, MenuItemImage* item);

void playBackGroundMusic();
void stopBackGroundMusic();

void playEffectBtnClicked();

#endif