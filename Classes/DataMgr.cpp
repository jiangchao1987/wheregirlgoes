#include "DataMgr.h"
#include "Tools.h"
#include "StringUtil.h"
#include "Defines.h"

DataMgr* DataMgr::instance = NULL;

DataMgr::DataMgr():dataArr(NULL)
{
	dataArr = CCArray::create();
	dataArr->retain();	//��ֹ��cocos2dx�Ļ��ջ��ƻ���

	this->loadQuestionData();
	this->loadUserData();
}

DataMgr::~DataMgr()
{
}

DataMgr* DataMgr::getInstance()
{
	if (instance == NULL)
		instance = new DataMgr();
	return instance;
}

bool DataMgr::loadQuestionData()
{
	FileUtils* File = FileUtils::getInstance();
	std::string sFullPath = File->fullPathForFilename("date.txt");
	std::string Beffer = File->getStringFromFile(sFullPath);

	Array* totalArr = StringUtil::sharedStrUtil()->split(Beffer.c_str(), "\n");
	log( "count is:%d", totalArr->count());

	for (int i = 0; i < totalArr->count(); i++)
	{
		Array* dicArr = StringUtil::sharedStrUtil()->split(((CCString*)totalArr->getObjectAtIndex(i))->_string.c_str(), ";");
		CCDictionary* dic = CCDictionary::create();

		log( "dic is:%d", dicArr->count());
		dic->setObject(dicArr->getObjectAtIndex(0), Key_guanka_index);
		dic->setObject(dicArr->getObjectAtIndex(1), Key_topic_title);
		dic->setObject(dicArr->getObjectAtIndex(2), Key_remark);
		dic->setObject(dicArr->getObjectAtIndex(3), Key_local_resource);
		dic->setObject(dicArr->getObjectAtIndex(4), Key_resource_name);
		dic->setObject(dicArr->getObjectAtIndex(5), Key_question);
		dic->setObject(dicArr->getObjectAtIndex(6), Key_m3u8_url);
		dic->setObject(dicArr->getObjectAtIndex(7), Key_detail_url);

		//������Array, ��һ��Ϊ��
		Array* answerArr = Array::create(dicArr->getObjectAtIndex(8),dicArr->getObjectAtIndex(9),dicArr->getObjectAtIndex(10),dicArr->getObjectAtIndex(11), NULL);
		srand((unsigned)time(0));
		int a = 1 + rand()%4;
		//������һ��Ͷ������е�ĳһ��λ��, ������λ�þ������
		answerArr->exchangeObjectAtIndex(a-1, 0);

		CCString* astr = CCString::createWithFormat("%d", a);
		//�Ѵ�����λ�ü���dic
		dic->setObject(astr, Key_answer_index);
		dataArr->addObject(dic);
				
		//���ĸ�ѡ�����dic
		dic->setObject(answerArr->getObjectAtIndex(0), Key_option1);
		dic->setObject(answerArr->getObjectAtIndex(1), Key_option2);
		dic->setObject(answerArr->getObjectAtIndex(2), Key_option3);
		dic->setObject(answerArr->getObjectAtIndex(3), Key_option4);
	}

	if ( dataArr != NULL && dataArr->count() > 0 )
		return true;
	
	return false;
}

bool DataMgr::loadUserData()
{
	{
		return true;
	}
	return false;
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