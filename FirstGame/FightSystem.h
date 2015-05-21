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
	void addEnemy(int NO, Enemy enemy);
	
	void createEnemys();
	
	inline void pushEnemy(Enemy* enemy){ cur_enemys.push_back(enemy); };
	void clearEnemy();

	inline int getCur_NO() const { return cur_NO; }
	inline void setCur_NO(int val) { cur_NO = val; }

private:
	int cur_NO;
	vector<Enemy> atk_enemys;
	vector<Enemy*> cur_enemys;

private:
	bool checkAttack(Node* n1, Node* n2);
};
#endif