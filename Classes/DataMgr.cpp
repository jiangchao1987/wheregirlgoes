#include "DataMgr.h"
#include "Tools.h"

DataMgr* DataMgr::instance = NULL;

DataMgr::DataMgr() : dataArr(NULL)
{
	dataArr = CCArray::create();
	dataArr->retain();

	//this->loadData1();
	//this->loadUserData();
}

DataMgr::~DataMgr()
{
}

DataMgr* DataMgr::getInstance()
{
	if (instance = NULL)
		instance == new DataMgr();
	return instance;
}

bool DataMgr::isBgSoundOpen()
{
	return LoadBooleanFromXML("isBgSoundOpen");
}

void DataMgr::openBgSound(bool bOpen)
{
	SaveBooleanToXML("isBgSoundOpen", bOpen);
	WriteDisk;
}