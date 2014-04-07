#ifndef __DATAMGR_H__
#define __DATAMGR_H__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class DataMgr
{
private:
	Array* dataArr;
public:
	DataMgr();
	~DataMgr();
	static DataMgr* getInstance();
private:
	static DataMgr* instance;

	bool loadQuestionData();
	bool loadUserData();

public:
	CCDictionary* getCurrentQuestion();

	int getCurrentQuestionIndex();
	void answerRight();

	bool isBgSoundOpen();
	void openBgSound(bool bOpen);
};

#endif