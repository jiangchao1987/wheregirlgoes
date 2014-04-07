#ifndef __LEVEL_VIEW_H__
#define __LEVEL_VIEW_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class LevelView : public Layer
{
public:
	LevelView();
    ~LevelView();

	static Scene* scene();
    virtual bool init();
    CREATE_FUNC(LevelView);
    
	void onEnter();
	void onExit();

private:
	int m_nCurPage;
    int m_nPageCount;

    CC_SYNTHESIZE_RETAIN(ScrollView*, m_pScrollView, ScrollView);

};

#endif