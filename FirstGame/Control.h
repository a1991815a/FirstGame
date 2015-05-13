#ifndef __CONTROL__
#define __CONTROL__
#include "stdafx.h"

#define _control Control::getInstance()

class Control{
public:
	static Control* getInstance();
private:
	static Control* _instance;

public:
	void getCh();

};
#endif