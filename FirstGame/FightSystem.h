#ifndef __FIGHTSYSTEM__
#define __FIGHTSYSTEM__
#include "LimitedState.h"
#include "Enemy.h"

class Actor;
class Enemy;

#define _fightSystem FightSystem::getInstance()

class FightSystem{
public:
	static FightSystem* getInstance();
private:
	static FightSystem* _instance;

public:
	FightSystem();
	void attack(Actor* attacker, Actor* defencer);

	void freeActStart();
	void defenceStart();

	void setFreeActDT(int minutes);

	void timingDt();
	void resetDt(){ cur_dt = 0; };
private:
	int cur_state;
	long cur_dt;
	long freeAct_time;

public:
	inline vector<Actor*> getActorByCamp(int camp){return fight_actors.at(camp);};

	vector<int> getCamps();

private:
	map<int, vector<Actor*>> fight_actors;

private:
	bool checkAttack(Node* n1, Node* n2);
};
#endif