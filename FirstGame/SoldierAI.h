#ifndef __SOLDIERAI__
#define __SOLDIERAI__
#include "stdafx.h"
class Actor;

#define _soldierAI SoldierAI::getInstance()

class SoldierAI{
public:
	static SoldierAI* getInstance();
private:
	static SoldierAI* _instance;

public:
	void setAi(Actor* actor);

	void excuteAi();

	void clear();
private:
	vector<Actor*> ai_actors;
};
#endif