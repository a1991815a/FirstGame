#ifndef __TEXTOUT__
#define __TEXTOUT__
#include "stdafx.h"
#include "RenderEngine.h"

#define _textOutUtils TextOutUtils::getInstance()

#define showSubText(format, ...) _renderEngine->setSubText(format, __VA_ARGS__)
#define showSideText(row,format, ...) _renderEngine->setSideText(row,format, __VA_ARGS__)

class TextOutUtils{
public:
	static TextOutUtils* getInstance();

private:
	static TextOutUtils* _instance;

public:
};
#endif