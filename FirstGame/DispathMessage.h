#ifndef __DISPATHMESSAGE__
#define __DISPATHMESSAGE__
#include "stdafx.h"

#define _dispathMessage DispathMessage::getInstance()

class DispathMessage{
public:
	static DispathMessage* getInstance();
private:
	static DispathMessage* _instance;
};
#endif