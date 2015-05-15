#ifndef __TEXTOUT__
#define __TEXTOUT__
#include "stdafx.h"
#include "RenderEngine.h"

#define _textOut TextOut::getInstance()

#define showSubText(format, ...) _renderEngine->setSubText(format, __VA_ARGS__)
#define showSideText(format, ...) _renderEngine->setSideText(format, __VA_ARGS__)

class TextOut{
public:
	static TextOut* getInstance();

private:
	static TextOut* _instance;

public:
};
#endif