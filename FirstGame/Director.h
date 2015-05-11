#ifndef __DIRECTOR__
#define __DIRECTOR__
#include "stdafx.h"

#define _director Director::getInstance()

class Director{
public:
	static Director* getInstance();
private:
	static Director* _instance;

public:

};
#endif