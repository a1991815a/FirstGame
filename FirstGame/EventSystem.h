#ifndef __EVENTSYSTEM__
#define __EVENTSYSTEM__
#include "stdafx.h"

class EventSystem{
public:
	static EventSystem* getInstance();
private:
	static EventSystem* _instance;
public:


};
#endif