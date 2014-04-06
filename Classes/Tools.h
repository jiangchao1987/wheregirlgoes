#ifndef __TOOLS__
#define __TOOLS__

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

Layer* createCommonBackLayer();
Sprite* createLogo();

void playBackGroundMusic();
void stopBackGroundMusic();

#endif