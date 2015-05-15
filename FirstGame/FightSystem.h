#ifndef __FIGHTSYSTEM__
#define __FIGHTSYSTEM__
#include "Message.h"

class FightSystem{
public:
	static FightSystem* getInstance();
private:
	static FightSystem* _instance;

private:
	bool fightStart(Message msg);
	bool fightAttack(Message msg);
	bool fightEnd(Message msg);
};
#endif