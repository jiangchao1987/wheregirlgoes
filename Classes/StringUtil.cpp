#include "StringUtil.h"

StringUtil* StringUtil::mStringUtil = NULL;

StringUtil* StringUtil::sharedStrUtil()
{
	if (mStringUtil == NULL)
	{
		mStringUtil = new StringUtil();
		if (mStringUtil && mStringUtil->init())
		{
			mStringUtil->autorelease();
		}
		else
		{
			CC_SAFE_DELETE(mStringUtil);
			mStringUtil = NULL;
		}
	}

	return mStringUtil;
}

bool StringUtil::init(){
    return true;
}

Array* StringUtil::split( const char* srcStr, const char* sSep )
{
	Array* stringList = Array::create();

	int size = strlen(srcStr);

	/* ������ת��Ϊ�ַ������� */
    CCString* str = CCString::create(srcStr);

	int startIndex = 0;
	int endIndex = 0;
	endIndex = str->_string.find(sSep);

	CCString* lineStr = NULL;

    /* ���ݻ��з�����ַ����������ӵ��б��� */
    while(endIndex > 0) {
        lineStr = CCString::create("");

        /* ��ȡһ���ַ��� */
        lineStr->_string = str->_string.substr(startIndex, endIndex);

		/* ���ӵ��б� */
        stringList->addObject(lineStr);

		/* ��ȡʣ�µ��ַ��� */
        str->_string = str->_string.substr(endIndex + 1, size);

        endIndex = str->_string.find(sSep);
	}

	/* ʣ�µ��ַ���Ҳ���ӽ��б� */
    if(str->_string.compare("") != 0) 
        stringList->addObject(CCString::create(str->_string));

    return stringList;
}

const char* StringUtil::transIntToStr( int iValue ) 
{
    return transIntToCCStr(iValue)->getCString();
}

CCString* StringUtil::transIntToCCStr( int iValue ) 
{
    char chValue[8];

    sprintf(chValue, "%d", iValue);

    return CCString::createWithFormat(chValue);
}