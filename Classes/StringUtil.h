/*
	文件名：    StringUtil.h
	描　述：    字符串处理工具
	创建人：    笨木头 (CSDN博客：http://blog.csdn.net/musicvs)

	创建日期：   2012.11.22
*/
#ifndef __STRING_UTIL_H__
#define __STRING_UTIL_H__

#include "cocos2d.h"

using namespace cocos2d;

class StringUtil : public Object {
public:
    static StringUtil* sharedStrUtil();

    bool init();

    /** 用分隔符分割字符串，结果存放到一个列表中，列表中的对象为CCString */
    Array* split(const char* srcStr, const char* sSep);

    /* 转换整数为字符串 */
    const char* transIntToStr(int iValue);
private:
    static StringUtil* mStringUtil;

    /* 转换整数为字符串 */
    String* transIntToCCStr(int iValue);
};

#endif