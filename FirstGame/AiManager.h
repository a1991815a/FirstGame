#ifndef	__AIMANAGER__
#define __AIMANAGER__
#include "stdafx.h"
class Actor;

class AiManager{
public:
	struct AiActor{
		Actor* actor;
		Actor* enemy;
		int state;
		AiActor(): actor(nullptr), state(AI_STATE_NORMAL){};
		AiActor(Actor* in_actor): actor(in_actor), state(AI_STATE_NORMAL){};
	};
public:
	static AiManager* getInstance();
private:
	static AiManager* _instance;
public:
	void setAi(Actor* actor);
	void deleteAi(Actor* actor);
	Actor* getAi(int index) const{return ai_actors.at(index).actor;};
	void clearDeath();

	void searchEnemy(int index);

private:
	vector<AiActor> ai_actors;
	int _delay;
};
#endif