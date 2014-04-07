/*
	�ļ�����    StringUtil.h
	�衡����    �ַ���������
	�����ˣ�    ��ľͷ (CSDN���ͣ�http://blog.csdn.net/musicvs)

	�������ڣ�   2012.11.22
*/
#ifndef __STRING_UTIL_H__
#define __STRING_UTIL_H__

#include "cocos2d.h"

using namespace cocos2d;

class StringUtil : public Object {
public:
    static StringUtil* sharedStrUtil();

    bool init();

    /** �÷ָ����ָ��ַ����������ŵ�һ���б��У��б��еĶ���ΪCCString */
    Array* split(const char* srcStr, const char* sSep);

    /* ת������Ϊ�ַ��� */
    const char* transIntToStr(int iValue);
private:
    static StringUtil* mStringUtil;

    /* ת������Ϊ�ַ��� */
    String* transIntToCCStr(int iValue);
};

#endif