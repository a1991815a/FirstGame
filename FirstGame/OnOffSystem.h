#ifndef __ONOFFSYSTEM__
#define __ONOFFSYSTEM__
#include "stdafx.h"

#define _onOffSystem OnOffSystem::getInstance()

class OnOffSystem{
public:
	static OnOffSystem* getInstance();
private:
	static OnOffSystem* _instance;

public:
	void setOnOff(int index, bool onoff);

	bool getOnOff(int index);

	void deleteOnOff(int index);
private:
	map<int,bool> _onoff_list;
};
#endif