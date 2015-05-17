#ifndef __FIGHTSYSTEM__
#define __FIGHTSYSTEM__
#include "Message.h"
class Actor;

class FightSystem{
public:
	static FightSystem* getInstance();
private:
	static FightSystem* _instance;

private:
	bool fightStart(Message msg);

	void fight(Monster* monster);

	void attack(Actor* attacker, Actor* defencer);

	bool fightAttack(Message msg);
	bool fightEnd(Message msg);
};
#endif